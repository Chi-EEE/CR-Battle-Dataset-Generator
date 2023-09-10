#include <iostream>
#include <fstream>

#include <filesystem>

#include "utils/Global.hpp"
#include "arena_files/EntityDataIndexer.h"

#include "nlohmann/json.hpp"
#include "tl/expected.hpp"

#include "canvas/Canvas.h"
#include "arena/Arena.h"
#include "arena/Character.h"

using namespace canvas;
using namespace arena;
using namespace arena_files;
using json = nlohmann::json;

tl::expected<bool, std::string> try_read_settings_json() {
	if (!std::filesystem::is_directory("config") || !std::filesystem::exists("config")) {
		std::filesystem::create_directory("config");
	}
	if (!std::filesystem::is_regular_file("config/settings.json") || !std::filesystem::exists("config/settings.json")) {
		json j = {
			{"assetDirectory", ""},
			{"ready", false},
		};
		std::ofstream outfile("config/settings.json");
		outfile << j.dump(4) << std::endl;
		outfile.close();
		return tl::make_unexpected("Please update the newly created file 'config/settings.json' and set the 'ready' key to true.");
	}
	auto load_json_result = Global::try_load_from_file("config/settings.json");
	if (load_json_result.has_value()) {
		return Global::get_json()["ready"].get<bool>();
	}
	else {
		return tl::make_unexpected(load_json_result.error());
	}
}

int main() {
	auto read_setting_json_result = try_read_settings_json();
	if (!read_setting_json_result.has_value()) {
		std::cerr << read_setting_json_result.error() << '\n';
		return 0;
	}
	if (!read_setting_json_result.value()) {
		std::cerr << "Please set 'ready' to true when you are ready." << '\n';
		return 0;
	}
	std::filesystem::path asset_directory(Global::get_json()["assetDirectory"].get<std::string>());
	auto& entity_data_indexer = EntityDataIndexer::getInstance();
	auto knight = entity_data_indexer.getEntityData("Knight");

	auto arena_result = Arena::try_create(ArenaType::Goblin_Stadium, TowerSkin::Default, TowerSkin::Default);
	if (arena_result.has_value()) {
		Arena arena = arena_result.value();
		for (int i = 0; i < 1; i++) {
			int add_attempts = 0;
			while (add_attempts < 100)
			{
				if (!arena.try_add_character(std::make_shared<Character>(Character::create(
					knight,
					asset_directory / "sprites" / "characters" / "chr_knight.sc" / "Knight_idle1_1_001.png",
					Random::get_instance().random_int_from_interval(58, 609),
					Random::get_instance().random_int_from_interval(126, 831),
					false
				).value()))) {
					add_attempts++;
				}
				else {
					break;
				}
			}
		}
		arena.draw();
		{
			auto result = arena.try_save("./testArena.png");
			if (!result.has_value()) {
				std::cerr << "An error has occurred while trying to save the arena: " << result.error() << '\n';
				return 0;
			}
		}
		std::cout << "Successful in creating 'testArena.png'!" << '\n';
	}
	else {
		std::cerr << "An error has occurred: " << arena_result.error() << '\n';
		return 0;
	}
	return 0;
}