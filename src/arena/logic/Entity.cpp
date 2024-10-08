#include "Entity.h"

namespace arena::logic {
	tl::expected<Entity, std::string> Entity::create(
		pEntityData entity_data,
		Image entity_image,
		bool is_blue
	) {
		EntityDataManager& entity_data_manager = EntityDataManager::getInstance();
		Random& random = Random::get_instance();
		std::vector<std::shared_ptr<Entity>> spawn_entities;
		bool spawn_entity_immediately = !entity_data->getSpawnCharacter().empty() && !entity_data->getSpawnPauseTime();
		if (spawn_entity_immediately) {
			auto spawn_entity_data = entity_data_manager.getEntityDataByName(entity_data->getSpawnCharacter());
			for (int i = 0; i < entity_data->getSpawnNumber(); i++) {
				auto maybe_spawn_entity_image = [&entity_data_manager, &spawn_entity_data, is_blue]() {
					while (true) {
						auto character_image_result = entity_data_manager.getRandomEntityImage(spawn_entity_data, is_blue);
						if (character_image_result.has_value()) {
							return character_image_result.value();
						}
						spdlog::error(character_image_result.error());
					}
				}();
				auto maybe_spawn_entity = Entity::create(spawn_entity_data, maybe_spawn_entity_image, is_blue);
				if (!maybe_spawn_entity.has_value()) {
					return tl::make_unexpected(maybe_spawn_entity.error());
				}
				auto spawn_entity = maybe_spawn_entity.value();
				spawn_entities.push_back(std::make_shared<Entity>(spawn_entity));
			}
		}
		return Entity(entity_data, entity_image, is_blue, spawn_entities);
	}

	void Entity::setPosition(SkV2 position)
	{
		this->position = position;
		this->rect = SkRect::MakeXYWH(position.x - (this->size.x / 2), position.y - (this->size.y / 2), this->size.x, this->size.y);

		int entity_scale = this->entity_data->getScale();

		if (this->spawn_entities.empty()) {
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
						this->rect.fRight - (entity_image_width / 2),
						this->rect.fLeft + (entity_image_width / 2)
					)
				),
				static_cast<float>(
					random.random_int_from_interval(
						this->rect.fBottom - (entity_image_height / 2),
						this->rect.fTop + (entity_image_height / 2)
					)
				)
			};
			spawn_entity->setPosition(spawn_position);
		}
	}

	void Entity::addNonStackableEffect(EntityEffect effect) {
		this->non_stackable_effects.insert(effect);
	}

	void Entity::draw(Canvas& canvas)
	{
		SkRect size_rect = SkRect::MakeIWH(this->size.x, this->size.y);
		SkPaint paint, crop;
		Canvas entity_canvas(this->size.x, this->size.y);
		entity_canvas.draw_image(this->image, size_rect);
		for (EntityEffect effect : this->non_stackable_effects)
		{
			auto effect_pair = effect.get_effect();

			SkBlendMode blend = effect_pair.first;
			SkColor color = effect_pair.second;

			paint.setBlendMode(blend);
			paint.setColor(color);
			entity_canvas.draw_rect(size_rect, paint);
		}
		crop.setBlendMode(SkBlendMode::kDstIn);
		entity_canvas.draw_image(this->image, size_rect, &crop);
		if (Random::get_instance().random_int_from_interval(0, 1)) {
			entity_canvas = entity_canvas.horizonal_flip();
		}
		canvas.draw_canvas(entity_canvas, this->rect);

		for (auto& spawn_entity : this->spawn_entities) {
			canvas.draw(*spawn_entity);
		}
	}

	void Entity::draw_ui(Canvas& canvas)
	{
		if (!this->level_ui) {
			return;
		}
		const json& settings_json = Global::getSettings();
		std::filesystem::path asset_directory(settings_json["asset_directory"].get<std::string>());
		ImageLoader& image_loader = ImageLoader::get_instance();
		auto level_ui = image_loader.try_load_image(asset_directory / "sprites" / "ui" / fmt::format("{}_level.png", this->is_blue ? "player" : "enemy")).value();

		auto level_width = level_ui.get_width() / 2;
		auto level_height = level_ui.get_height() / 2;
		if (this->health_ui) {
			std::string health_bar_type = this->entity_data->getHealthBar();

			std::transform(health_bar_type.begin(), health_bar_type.end(), health_bar_type.begin(),
				[](unsigned char c) { return std::tolower(c); });

			Image health_bar = [this, &image_loader, asset_directory, health_bar_type]()
				{
					std::filesystem::path health_bar_directory = 
						asset_directory /
						"sprites" /
						"ui" /
						fmt::format("hp_{}_{}", this->is_blue ? "player" : "enemy", health_bar_type);
					if (!std::filesystem::exists(health_bar_directory)) {
						health_bar_directory = 
							asset_directory /
							"sprites" /
							"ui" /
							fmt::format("hp_{}_medium", this->is_blue ? "player" : "enemy");
					}
					return image_loader.try_load_image(Random::get_instance().try_get_random_file_from_directory(health_bar_directory).value()).value();
				}();

				auto health_bar_width = health_bar.get_width() / 2;
				auto health_bar_height = health_bar.get_height() / 2;
				SkRect health_bar_rect = SkRect::MakeXYWH(
					this->position.x - (health_bar_width / 2),
					this->rect.fTop - (health_bar_height / 2) + this->entity_data->getHealthBarOffsetY(),
					health_bar_width,
					health_bar_height
				);
				canvas.draw_image(health_bar, health_bar_rect);

				SkRect level_rect = SkRect::MakeXYWH(
					health_bar_rect.fLeft - level_width,
					this->rect.fTop - (level_height / 2) + this->entity_data->getHealthBarOffsetY(),
					level_width,
					level_height
				);
				canvas.draw_image(level_ui, level_rect);
		}
		else {
			SkRect level_rect = SkRect::MakeXYWH(
				this->position.x - (level_width / 2),
				this->rect.fTop - (level_height / 2) + this->entity_data->getHealthBarOffsetY(),
				level_width,
				level_height
			);
			canvas.draw_image(level_ui, level_rect);
		}
	}

	void Entity::draw_shadow(Canvas& canvas)
	{
		Canvas entity_shadow_canvas = Canvas(this->size.x, this->size.y);
		entity_shadow_canvas.draw_image(this->image, SkRect::MakeXYWH(0, 0, this->size.x, this->size.y));

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
	}

	Entity::~Entity()
	{

	}

	Entity::Entity(pEntityData entity_data, Image image, bool is_blue, std::vector<std::shared_ptr<Entity>> spawn_entities) : entity_data(entity_data), image(image), is_blue(is_blue), spawn_entities(spawn_entities)
	{
		float scale = (this->entity_data->getScale() / 100.0f);
		float entity_width = (this->image.get_width() * scale) * Global::scale;
		float entity_height = (this->image.get_height() * scale) * Global::scale;
		this->size = { entity_width, entity_height };
		this->rect = SkRect::MakeIWH(this->size.x, this->size.y);
	}
}