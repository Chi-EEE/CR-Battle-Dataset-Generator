#include <iostream>
#include <fstream>

#include <filesystem>

#include <optional>

#include "utils/Global.hpp"
#include "nlohmann/json.hpp"
#include "tl/expected.hpp"
#include "canvas/Canvas.h"
#include "arena/Arena.h"

using namespace canvas;
using namespace arena;
using json = nlohmann::json;

tl::expected<bool, std::string> readSettingJson() {
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
	auto loadJsonResult = Global::loadFromFile("config/settings.json");
	if (loadJsonResult.has_value()) {
		return Global::getJson()["ready"].get<bool>();
	}
	else {
		return tl::make_unexpected(loadJsonResult.error());
	}
}

int main() {
	auto readSettingJsonResult = readSettingJson();
	if (!readSettingJsonResult.has_value()) {
		std::cerr << readSettingJsonResult.error() << '\n';
		return 0;
	}
	if (!readSettingJsonResult.value()) {
		std::cerr << "Please set 'ready' to true when you are ready." << '\n';
		return 0;
	}

	auto arenaResult = Arena::create(ArenaType::Goblin_Stadium, TowerSkin::Default, TowerSkin::Default);
	if (arenaResult.has_value()) {
		Arena arena = arenaResult.value();
		auto result = arena.save("./testArena.png");
		if (!result.has_value()) {
			std::cerr << "An error has occurred while trying to save the arena: " << result.error() << '\n';
			return 0;
		}
	}
	else {
		std::cerr << "An error has occurred: " << arenaResult.error() << '\n';
		return 0;
	}
	return 0;
}