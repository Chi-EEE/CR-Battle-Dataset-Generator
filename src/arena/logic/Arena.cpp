#include "Arena.h"
#include "Character.h"

using namespace arena::data;
using namespace csv;

namespace arena {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side_tower_skin(blue_side), red_side_tower_skin(red_side), canvas(canvas)
	{
		auto& entity_data_indexer = EntityDataIndexer::getInstance();

		auto princess_tower = entity_data_indexer.getEntityDataByName("PrincessTower");
		auto king_tower = entity_data_indexer.getEntityDataByName("KingTower");

		add_arena_tower(princess_tower, "princess", "blue", this->blue_side_tower_skin, 171, 788);
		add_arena_tower(princess_tower, "princess", "blue", this->blue_side_tower_skin, 548, 788);
		add_arena_tower(king_tower, "king", "blue", this->blue_side_tower_skin, 360, 875);

		add_arena_tower(princess_tower, "princess", "red", this->red_side_tower_skin, 171, 262);
		add_arena_tower(princess_tower, "princess", "red", this->red_side_tower_skin, 548, 262);
		add_arena_tower(king_tower, "king", "red", this->red_side_tower_skin, 360, 167);
	}

	void Arena::add_arena_tower(pEntityData entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y)
	{
		auto result = try_get_arena_tower_path(character, team_side, tower_skin);
		if (!result.has_value()) throw std::exception(result.error().c_str());
		auto building_instance_result = Building::create(entity_data, result.value());
		if (!building_instance_result.has_value()) throw std::exception(building_instance_result.error().c_str());
		pBuilding building = std::make_shared<Building>(building_instance_result.value());
		building->setPosition(x, y);
		this->ground_entities.push_back(building);
	}

	tl::expected<std::filesystem::path, std::string> Arena::try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin)
	{
		std::string blue_side_name = tower_skin.to_string();
		std::transform(blue_side_name.begin(), blue_side_name.end(), blue_side_name.begin(), ::tolower);
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
		std::filesystem::path arena_tower_file = asset_directory / "essentials" / character / team_side / "tower" / blue_side_name / "01.png";
		if (!std::filesystem::exists(arena_tower_file)) return tl::make_unexpected(fmt::format("Unable to find the arena tower path containing: {}, {}, {}", character, team_side));
		return arena_tower_file;
	}

	void Arena::draw_entity(pEntity entity) {
		entity->draw(this->canvas);
		if (entity->spawn_character != nullptr) {
			Image entity_image = ImageLoader::get_instance().try_load_image(entity->spawn_character->file_path).value();

			int entity_scale = entity->entity_data->getScale();

			double entity_image_width = (entity_image.get_width() * (entity_scale / 100.0)) * Global::scale;
			double entity_image_height = (entity_image.get_height() * (entity_scale / 100.0)) * Global::scale;

			Random& random = Random::get_instance();
			for (int i = 0; i < entity->entity_data->getSpawnNumber(); i++) {
				SkRect rect = SkRect::MakeXYWH(
					random.random_int_from_interval(
						entity->rect.fLeft - (entity_image_width / 2),
						entity->rect.fRight - (entity_image_width / 2)
					),
					random.random_int_from_interval(
						entity->rect.fTop - (entity_image_height / 2),
						entity->rect.fBottom - (entity_image_height / 2)
					), 
					entity_image_width, entity_image_height
				);
				this->canvas.draw_image(entity_image, rect);
			}
		}
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

	bool Arena::try_add_character(pCharacter character)
	{
		for (auto entity : this->ground_entities) {
			double distance = sqrt(pow(entity->x - character->x, 2) + pow(entity->y - character->y, 2)) * 32;
			bool inside_bounds = distance <= (entity->entity_data->getCollisionRadius() * Global::scale) + (character->entity_data->getCollisionRadius() * Global::scale);
			spdlog::debug("CurrentName:{}|Name:{}|Distance:{}|Inside_Bounds:{}", character->entity_data->getName(), entity->entity_data->getName(), distance, inside_bounds);
			if (inside_bounds)
				return false;
		}
		for (auto entity : this->air_entities) {
			double distance = sqrt(pow(entity->x - character->x, 2) + pow(entity->y - character->y, 2)) * 32;
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
				return entity_1->y < entity_2->y;
			}
		);
		std::sort(this->air_entities.begin(), this->air_entities.end(), [](const pEntity& entity_1, const pEntity& entity_2) -> bool
			{
				return entity_1->y < entity_2->y;
			}
		);
		for (auto& entity : this->ground_entities) {
			this->draw_entity(entity);
		}
		for (auto& entity : this->air_entities) {
			this->draw_entity(entity);
		}
		if (Global::get_json()["display_bounding_boxes"].get<bool>()) {
			for (auto& entity : this->ground_entities) {
				entity->draw_annotation_box(this->canvas);
			}
			for (auto& entity : this->air_entities) {
				entity->draw_annotation_box(this->canvas);
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