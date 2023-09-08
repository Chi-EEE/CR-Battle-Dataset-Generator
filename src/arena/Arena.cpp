#include "Arena.h"
#include "Character.h"

namespace arena {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side_tower_skin(blue_side), red_side_tower_skin(red_side), canvas(canvas)
	{
		add_arena_tower("PrincessTower", "princess", "blue", this->blue_side_tower_skin, 171, 788, false);
		add_arena_tower("PrincessTower", "princess", "blue", this->blue_side_tower_skin, 548, 788, false);
		add_arena_tower("KingTower", "king", "blue", this->blue_side_tower_skin, 360, 875, false);

		add_arena_tower("PrincessTower", "princess", "red", this->red_side_tower_skin, 171, 262, false);
		add_arena_tower("PrincessTower", "princess", "red", this->red_side_tower_skin, 548, 262, false);
		add_arena_tower("KingTower", "king", "red", this->red_side_tower_skin, 360, 167, false);
	}

	void Arena::add_arena_tower(std::string name, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y, bool is_air)
	{
		auto result = try_get_arena_tower_path(character, team_side, tower_skin);
		if (!result.has_value()) throw std::exception(result.error().c_str());
		auto building_instance_result = Building::create(name, result.value(), x, y, is_air);
		if (!building_instance_result.has_value()) throw std::exception(building_instance_result.error().c_str());
		this->entities.push_back(std::make_shared<Building>(building_instance_result.value()));
	}

	tl::expected<std::filesystem::path, std::string> Arena::try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin)
	{
		std::string blue_side_name = tower_skin.to_string();
		std::transform(blue_side_name.begin(), blue_side_name.end(), blue_side_name.begin(), ::tolower);
		std::filesystem::path asset_directory(Global::get_json()["assetDirectory"].get<std::string>());
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
		std::filesystem::path assetDirectory(Global::get_json()["assetDirectory"].get<std::string>());

		std::string time = "default";
		if (random.random_int_from_interval(0, 1)) time = "overtime";

		auto arena_file_path_result = random.try_get_random_file_from_directory(assetDirectory / "arenas" / arena_type_name / time);
		if (!arena_file_path_result.has_value()) {
			return tl::make_unexpected(arena_file_path_result.error());
		}
		std::string arena_file_path = arena_file_path_result.value();

		auto image_result = image_loader.try_load_image(arena_file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		Canvas canvas = Canvas(image.get_width(), image.get_height());
		canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width(), image.get_height()));
		return Arena(arena_type, blue_side, red_side, canvas);
	}

	void Arena::add_character(std::shared_ptr<Character> character)
	{
		this->entities.push_back(character);
	}

	void Arena::draw()
	{
		std::sort(this->entities.begin(), this->entities.end(), [](const auto& e1, const auto& e2) -> bool {
			if (~(e1->is_air & e2->is_air))
				return e1->y < e2->y;
			else if (e1->is_air)
				return true;
			else /*e2->is_air*/ return false;
		});
		for (auto& entity : this->entities) {
			std::cout << entity->file_path << '\n';
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

	tl::expected<nullptr_t, std::string> Arena::try_save(std::string file_name)
	{
		return this->canvas.try_save(file_name);
	}
}