#include "Entity.h"

namespace arena::logic {
	tl::expected<Entity, std::string> Entity::create(pEntityData entity_data, Image entity_image)
	{
		EntityDataManager& entity_data_manager = EntityDataManager::getInstance();
		std::vector<std::shared_ptr<Entity>> spawn_entities;
		bool spawn_entity_immediately = !entity_data->getSpawnCharacter().empty() && !entity_data->getSpawnPauseTime();
		if (spawn_entity_immediately) {
			auto spawn_entity_data = entity_data_manager.getEntityDataByName(entity_data->getSpawnCharacter());
			for (int i = 0; i < entity_data->getSpawnNumber(); i++) {
				auto maybe_spawn_entity_image = entity_data_manager.getRandomEntityImage(spawn_entity_data);
				auto maybe_spawn_entity = Entity::create(spawn_entity_data, maybe_spawn_entity_image.value());
				if (!maybe_spawn_entity.has_value()) {
					return tl::make_unexpected(maybe_spawn_entity.error());
				}
				spawn_entities.push_back(std::make_shared<Entity>(maybe_spawn_entity.value()));
			}
		}
		return Entity(entity_data, entity_image, spawn_entities);
	}

	Entity::Entity(pEntityData entity_data, Image image, std::vector<std::shared_ptr<Entity>> spawn_entities) : entity_data(entity_data), image(image), spawn_entities(spawn_entities)
	{
		float scale = (this->entity_data->getScale() / 100.0f);
		float entity_width = (this->image.get_width() * scale) * Global::scale;
		float entity_height = (this->image.get_height() * scale) * Global::scale;

		this->size = { entity_width, entity_height };

		this->rect = SkRect::MakeXYWH(0, 0, this->size.x, this->size.y);
	}

	void Entity::setPosition(SkV2 position)
	{
		this->position = position;
		this->rect = SkRect::MakeXYWH(position.x - (this->size.x / 2), position.y - (this->size.y / 2), this->size.x, this->size.y);

		int entity_scale = this->entity_data->getScale();

		if (!this->spawn_entities.empty()) {
			return;
		}

		auto width = this->size.x;
		auto height = this->size.y;

		double entity_image_width = (width * (entity_scale / 100.0)) * Global::scale;
		double entity_image_height = (height * (entity_scale / 100.0)) * Global::scale;

		Random& random = Random::get_instance();
		for (auto& spawn_entity : this->spawn_entities) {
			SkV2 spawn_position = SkV2{
				static_cast<float>(
					random.random_int_from_interval(
						this->rect.fLeft + (entity_image_width / 2),
						this->rect.fRight - (entity_image_width / 2)
					)
				),
				static_cast<float>(
					random.random_int_from_interval(
						this->rect.fTop + (entity_image_height / 2),
						this->rect.fBottom - (entity_image_height / 2)
					)
				)
			};
			spawn_entity->setPosition(spawn_position);
		}
	}

	void Entity::draw(Canvas& canvas)
	{
		Canvas entity_canvas(this->size.x, this->size.y);
		entity_canvas.draw_image(this->image, SkRect{0, 0, this->size.x, this->size.y}, nullptr);

		SkPaint paint;
		paint.setBlendMode(SkBlendMode::kPlus);
		paint.setColor(SK_ColorRED);
		entity_canvas.draw_rect(SkRect{ 0, 0, this->size.x, this->size.y }, paint);

		SkPaint normal;
		normal.setBlendMode(SkBlendMode::kDstIn);
		entity_canvas.draw_image(this->image, SkRect{0, 0, this->size.x, this->size.y}, & normal);

		canvas.draw_canvas(entity_canvas, this->rect);

		for (auto& spawn_entity : this->spawn_entities) {
			canvas.draw(*spawn_entity);
		}
	}

	void Entity::draw_shadow(Canvas& canvas)
	{
		Canvas entity_shadow_canvas = Canvas(this->size.x, this->size.y);
		entity_shadow_canvas.draw_image(this->image, SkRect::MakeXYWH(0, 0, this->size.x, this->size.y), nullptr);

		double new_height = std::floor(entity_shadow_canvas.get_height() * 0.71751412429378531073446327683616);
		entity_shadow_canvas = entity_shadow_canvas.stretch(SkPoint::Make(this->size.x, this->size.y));
		entity_shadow_canvas = entity_shadow_canvas.vertical_flip();
		entity_shadow_canvas = entity_shadow_canvas.skew(-this->entity_data->getShadowSkew() / 50.0f, 0);
		SkRect entity_shadow_rect = SkRect::MakeXYWH(
			this->rect.left() + this->entity_data->getShadowX(),
			this->rect.top() + this->size.y + this->entity_data->getShadowY(),
			entity_shadow_canvas.get_width() + this->entity_data->getShadowX(),
			entity_shadow_canvas.get_height() + this->entity_data->getShadowY()
		);

		canvas.draw_image(entity_shadow_canvas.replace_pixels_to(), entity_shadow_rect, nullptr);
	}

	Entity::~Entity()
	{

	}
}