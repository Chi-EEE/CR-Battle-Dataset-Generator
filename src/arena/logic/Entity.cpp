#include "Entity.h"

namespace arena::logic {
	Entity::Entity(pEntityData entity_data, Texture texture, std::vector<std::shared_ptr<Entity>> spawn_entities) : entity_data(entity_data), texture(texture), spawn_entities(spawn_entities)
	{
		float scale = (this->entity_data->getScale() / 100.0f);

		sf::Vector2u size = this->texture.getSize();

		float entity_width = (size.x * scale) * Global::scale;
		float entity_height = (size.y * scale) * Global::scale;

		this->size = { entity_width, entity_height };

		this->rect = sf::FloatRect{ 0.0f, 0.0f, this->size.x, this->size.y };
	}

	tl::expected<Entity, std::string> Entity::create(pEntityData entity_data, Texture entity_texture)
	{	
		EntityDataManager& entity_data_manager = EntityDataManager::getInstance();
		std::vector<std::shared_ptr<Entity>> spawn_entities;
		bool spawn_entity_immediately = !entity_data->getSpawnCharacter().empty() && !entity_data->getSpawnPauseTime();
		if (spawn_entity_immediately) {
			auto spawn_entity_data = entity_data_manager.getEntityDataByName(entity_data->getSpawnCharacter());
			for (int i = 0; i < entity_data->getSpawnNumber(); i++) {
				auto maybe_spawn_entity_texture = entity_data_manager.getRandomEntityTexture(spawn_entity_data);
				auto maybe_spawn_entity = Entity::create(spawn_entity_data, maybe_spawn_entity_texture.value());
				if (!maybe_spawn_entity.has_value()) {
					return tl::make_unexpected(maybe_spawn_entity.error());
				}
				spawn_entities.push_back(std::make_shared<Entity>(maybe_spawn_entity));
			}
		}
		return Entity(entity_data, entity_texture, spawn_entities);
	}

	void Entity::setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->rect = sf::FloatRect{ this->x - (this->size.x / 2), this->y - (this->size.y / 2), this->size.x, this->size.y };

		int entity_scale = this->entity_data->getScale();

		if (!this->spawn_entities.empty()) {
			return;
		}

		sf::Vector2u size = this->texture.getSize();

		auto width = size.x;
		auto height = size.y;

		double entity_image_width = (width * (entity_scale / 100.0)) * Global::scale;
		double entity_image_height = (height * (entity_scale / 100.0)) * Global::scale;

		Random& random = Random::get_instance();
		for (auto& spawn_entity : this->spawn_entities) {
			spawn_entity->setPosition(
				random.random_int_from_interval(
					this->rect.left + (entity_image_width / 2),
					this->rect.left + this->rect.width - (entity_image_width / 2)
				),
				random.random_int_from_interval(
					this->rect.top + (entity_image_height / 2),
					this->rect.top + this->rect.height - (entity_image_height / 2)
				)
			);
		}
	}

	void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		Random& random = Random::get_instance();
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());

		sf::RectangleShape rectangle;
		rectangle.setTexture(&this->texture.getTexture());
		rectangle.setPosition(sf::Vector2f{ this->rect.left, this->rect.top });
		rectangle.setSize(sf::Vector2f{ this->rect.width, this->rect.height });
		target.draw(rectangle, states);
		for (auto& spawn_entity : this->spawn_entities) {
			target.draw(*spawn_entity);
		}
	}

	// If the annotation box is not visible, then you would need to run a script to get rid of transparent area around the entity
	/*void Entity::draw_annotation_box(Canvas& canvas)
	{
		sf::Color average_color = EntityColorManager::getInstance().get_average_color(this->entity_data, this->texture);
		SkPaint box;
		box.setColor(average_color);
		box.setStyle(SkPaint::Style::kStroke_Style);
		box.setStrokeWidth(1.0f);
		canvas.draw_rect(this->rect, box);
		canvas.draw_text(this->entity_data->getName(), this->rect.fLeft, this->rect.fBottom);
	}*/

	/*void Entity::draw_shadow(Canvas& canvas)
	{
		Canvas entity_shadow_canvas = Canvas(this->size.x, this->size.y);
		entity_shadow_canvas.draw_image(this->texture, SkRect::MakeXYWH(0, 0, this->size.x, this->size.y));

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

		canvas.draw_image(entity_shadow_canvas.replace_pixels_to(), entity_shadow_rect);
	}*/

	Entity::~Entity()
	{

	}
}