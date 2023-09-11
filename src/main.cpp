#include <iostream>
#include <fstream>

#include <filesystem>

#include "utils/Global.hpp"
#include "arena/data/EntityDataIndexer.h"

#include "nlohmann/json.hpp"
#include "tl/expected.hpp"
#include "spdlog/spdlog.h"

#include "canvas/Canvas.h"
#include "arena/logic/Arena.h"
#include "arena/logic/Character.h"

using namespace canvas;
using namespace arena;
using namespace arena::data;

using json = nlohmann::json;

tl::expected<bool, std::string> try_read_settings_json() {
	if (!std::filesystem::is_directory("config") || !std::filesystem::exists("config")) {
		std::filesystem::create_directory("config");
	}
	if (!std::filesystem::is_regular_file("config/settings.json") || !std::filesystem::exists("config/settings.json")) {
		json j = {
			{"image_count", 0},
			{"character_count", 0},
			{"asset_directory", ""},
			{"output_directory", ""},
			{"ready", false},
			{"debug", false},
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
		std::cerr << "Please set 'ready' to true when you are ready.\n";
		return 0;
	}

	int image_count(Global::get_json()["image_count"].get<int>());
	int character_count(Global::get_json()["character_count"].get<int>());
	std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
	std::filesystem::path output_directory(Global::get_json()["output_directory"].get<std::string>());
	bool debug(Global::get_json()["debug"].get<bool>());
	if (debug) {
		spdlog::set_level(spdlog::level::debug);
	}

	auto& random = Random::get_instance();

	auto& entity_data_indexer = EntityDataIndexer::getInstance();

	spdlog::info("Starting to generate images and annotations!\n");
	for (int image_id = 0; image_id < image_count; image_id++) {
		spdlog::info("Generating image {}!\n", image_id);
		auto arena_result = Arena::try_create(ArenaType::Goblin_Stadium, TowerSkin::Default, TowerSkin::Default);
		if (!arena_result.has_value()) {
			spdlog::error("An error has occurred: {}\n", arena_result.error());
			return 0;
		}
		Arena arena = arena_result.value();
		for (int character_id = 0; character_id < character_count; character_id++) {
			int add_attempts = 0;
			while (add_attempts < 100)
			{
				auto directory = random.try_get_random_directory_from_directory(asset_directory / "sprites" / "characters").value();
				auto character = entity_data_indexer.getEntityDataByFileName(directory.filename().string());
				if (character == nullptr) {
					continue;
				}
				auto image = random.try_get_random_file_from_directory(directory).value();
				if (!arena.try_add_character(std::make_shared<Character>(Character::create(
					character,
					image,
					Random::get_instance().random_int_from_interval(64, 664),
					Random::get_instance().random_int_from_interval(128, 954),
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
			auto result = arena.try_save(output_directory / fmt::format("{}.png", image_id));
			if (!result.has_value()) {
				spdlog::error("An error has occurred while trying to save the arena: {}\n", result.error());
				return 0;
			}
		}
		spdlog::info("Completed generating image {}!\n", image_id);
	}
	spdlog::info("Completed generating all images and annotations!");
	return 0;
}