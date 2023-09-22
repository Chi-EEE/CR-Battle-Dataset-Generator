#include "Arena.h"

namespace arena::logic {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side_tower_skin(blue_side), red_side_tower_skin(red_side), canvas(canvas)
	{
		auto& entity_data_manager = EntityDataManager::getInstance();

		auto princess_tower = entity_data_manager.getEntityDataByName("PrincessTower");
		auto king_tower = entity_data_manager.getEntityDataByName("KingTower");

		add_arena_tower(princess_tower, "princess", true, this->blue_side_tower_skin, SkV2{171, 788});
		add_arena_tower(princess_tower, "princess", true, this->blue_side_tower_skin, SkV2{548, 788});
		add_arena_tower(king_tower, "king", true, this->blue_side_tower_skin, SkV2{360, 875});

		add_arena_tower(princess_tower, "princess", false, this->red_side_tower_skin, SkV2{171, 262});
		add_arena_tower(princess_tower, "princess", false, this->red_side_tower_skin, SkV2{548, 262});
		add_arena_tower(king_tower, "king", false, this->red_side_tower_skin, SkV2{360, 167});
	}

	void Arena::add_arena_tower(pEntityData entity_data, std::string character, bool is_blue, TowerSkin tower_skin, SkV2 position)
	{
		auto result = try_get_arena_tower_path(character, is_blue, tower_skin);
		if (!result.has_value()) throw std::exception(result.error().c_str());
		auto building_instance_result = Entity::create(entity_data, result.value(), is_blue);
		if (!building_instance_result.has_value()) throw std::exception(building_instance_result.error().c_str());
		pEntity building = std::make_shared<Entity>(building_instance_result.value());
		building->setPosition(position);
		this->ground_entities.push_back(building);
	}

	tl::expected<Image, std::string> Arena::try_get_arena_tower_path(std::string character, bool is_blue, TowerSkin tower_skin)
	{
		std::string blue_side_name = tower_skin.to_string();
		std::transform(blue_side_name.begin(), blue_side_name.end(), blue_side_name.begin(), ::tolower);
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
		std::filesystem::path arena_tower_file = asset_directory / "essentials" / character / (is_blue ? "blue" : "red") / "tower" / blue_side_name / "01.png";
		if (!std::filesystem::exists(arena_tower_file)) return tl::make_unexpected(fmt::format("Unable to find the arena tower path containing: {}, {}, {}", character, is_blue));
		return ImageLoader::get_instance().try_load_image(arena_tower_file);
	}

	tl::expected<Arena, std::string> Arena::try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side)
	{
		Random& random = Random::get_instance();
		ImageLoader& image_loader = ImageLoader::get_instance();
		std::string arena_type_name = arena_type.to_string();
		std::transform(arena_type_name.begin(), arena_type_name.end(), arena_type_name.begin(), ::tolower);

		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());

		std::string time = "default";
		if (random.random_int_from_interval(0, 1)) time = "overtime";

		auto arena_file_path_result = random.try_get_random_file_from_directory(asset_directory / "arenas" / arena_type_name / time);
		if (!arena_file_path_result.has_value()) {
			return tl::make_unexpected(arena_file_path_result.error());
		}
		std::filesystem::path arena_file_path = arena_file_path_result.value();

		auto image_result = image_loader.try_load_image(arena_file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		Canvas canvas = Canvas(image.get_width(), image.get_height());
		canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width(), image.get_height()));
		return Arena(arena_type, blue_side, red_side, canvas);
	}

	bool Arena::try_add_character(pEntity character)
	{
		SkV2 character_position = character->position;
		for (auto entity : this->ground_entities) {
			SkV2 entity_position = entity->position;
			double distance = sqrt(pow(entity_position.x - character_position.x, 2) + pow(entity_position.y - character_position.y, 2)) * 32;
			bool inside_bounds = distance <= (entity->entity_data->getCollisionRadius() * Global::scale) + (character->entity_data->getCollisionRadius() * Global::scale);
			spdlog::debug("CurrentName:{}|Name:{}|Distance:{}|Inside_Bounds:{}", character->entity_data->getName(), entity->entity_data->getName(), distance, inside_bounds);
			if (inside_bounds)
				return false;
		}
		for (auto entity : this->air_entities) {
			SkV2 entity_position = entity->position;
			double distance = sqrt(pow(entity_position.x - character_position.x, 2) + pow(entity_position.y - character_position.y, 2)) * 32;
			bool inside_bounds = distance <= (entity->entity_data->getCollisionRadius() * 4 * Global::scale) + (character->entity_data->getCollisionRadius() * Global::scale);
			spdlog::debug("CurrentName:{}|Name:{}|Distance:{}|Inside_Bounds:{}", character->entity_data->getName(), entity->entity_data->getName(), distance, inside_bounds);
			if (inside_bounds)
				return false;
		}
		if (character->entity_data->getFlyingHeight()) {
			this->air_entities.push_back(character);
		}
		else {
			this->ground_entities.push_back(character);
		}
		return true;
	}

	void Arena::draw()
	{
		std::sort(this->ground_entities.begin(), this->ground_entities.end(), [](const pEntity& entity_1, const pEntity& entity_2) -> bool
			{
				return entity_1->position.y < entity_2->position.y;
			}
		);
		std::sort(this->air_entities.begin(), this->air_entities.end(), [](const pEntity& entity_1, const pEntity& entity_2) -> bool
			{
				return entity_1->position.y < entity_2->position.y;
			}
		);

		for (auto& entity : this->ground_entities) {
			this->canvas.draw(*entity);
		}

		for (auto& entity : this->air_entities) {
			this->canvas.draw(*entity);
		}

		for (auto& entity : this->ground_entities) {
			if (entity->ui) {
				entity->draw_ui(this->canvas);
			}
		}

		for (auto& entity : this->air_entities) {
			if (entity->ui) {
				entity->draw_ui(this->canvas);
			}
		}

		if (Global::get_json()["display_bounding_boxes"].get<bool>()) {
			EntityDataManager& entity_data_manager = EntityDataManager::getInstance();
			for (auto& entity : this->ground_entities) {
				SkColor average_color = entity_data_manager.getAverageColor(entity->entity_data, entity->image);
				AnnotationBox annotation_box{entity->entity_data->getName(), entity->rect, average_color };
				annotation_box.draw(canvas);
			}
			for (auto& entity : this->air_entities) {
				SkColor average_color = entity_data_manager.getAverageColor(entity->entity_data, entity->image);
				AnnotationBox annotation_box{ entity->entity_data->getName(), entity->rect, average_color };
				annotation_box.draw(canvas);
			}
		}
	}

	Arena::~Arena()
	{

	}

	Arena Arena::clone()
	{
		return Arena(this->arena_type, blue_side_tower_skin, red_side_tower_skin, this->canvas.clone());
	}

	tl::expected<nullptr_t, std::string> Arena::try_save(std::filesystem::path file_path)
	{
		return this->canvas.try_save(file_path);
	}
}