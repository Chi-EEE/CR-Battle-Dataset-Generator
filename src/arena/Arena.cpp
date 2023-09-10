#include "Arena.h"
#include "Character.h"

using namespace arena_files;
using namespace CSV::Logic;

namespace arena {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side_tower_skin(blue_side), red_side_tower_skin(red_side), canvas(canvas)
	{
		auto& entity_data_indexer = EntityDataIndexer::getInstance();

		auto princess_tower = entity_data_indexer.getEntityDataByName("PrincessTower");
		auto king_tower = entity_data_indexer.getEntityDataByName("KingTower");

		add_arena_tower(princess_tower,  "princess", "blue", this->blue_side_tower_skin, 171, 788, false);
		add_arena_tower(princess_tower, "princess", "blue", this->blue_side_tower_skin, 548, 788, false);
		add_arena_tower(king_tower, "king", "blue", this->blue_side_tower_skin, 360, 875, false);

		add_arena_tower(princess_tower, "princess", "red", this->red_side_tower_skin, 171, 262, false);
		add_arena_tower(princess_tower, "princess", "red", this->red_side_tower_skin, 548, 262, false);
		add_arena_tower(king_tower, "king", "red", this->red_side_tower_skin, 360, 167, false);
	}

	void Arena::add_arena_tower(pEntityData entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y, bool is_air)
	{
		auto result = try_get_arena_tower_path(character, team_side, tower_skin);
		if (!result.has_value()) throw std::exception(result.error().c_str());
		auto building_instance_result = Building::create(entity_data, result.value(), x, y, is_air);
		if (!building_instance_result.has_value()) throw std::exception(building_instance_result.error().c_str());
		this->entities.push_back(std::make_shared<Building>(building_instance_result.value()));
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
		for (auto entity : this->entities) {
			double distance = sqrt(pow(entity->x - character->x, 2) + pow(entity->y - character->y, 2)) * 32;
			bool inside_bounds = distance <= entity->entity_data->getCollisionRadius() + character->entity_data->getCollisionRadius();
			spdlog::debug("CurrentName:{}|Name:{}|Distance:{}|Inside_Bounds:{}", character->entity_data->getName(), entity->entity_data->getName(), distance, inside_bounds);
			if (inside_bounds)
				return false;
		}
		this->entities.push_back(character);
		return true;
	}

	void Arena::draw()
	{
		std::sort(this->entities.begin(), this->entities.end(), [](const pEntity& entity_1, const pEntity& entity_2) -> bool {
			if (~(entity_1->is_air & entity_2->is_air))
			{
				return entity_1->y < entity_2->y;
			}
			else if (entity_1->is_air)
				return false;
			else /*e2->is_air*/ return true;
		});
		for (auto& entity : this->entities) {
			entity->draw(this->canvas);
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