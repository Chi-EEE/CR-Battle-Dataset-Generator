#include <iostream>
#include <fstream>

#include <filesystem>
#include <unordered_set>

#include "utils/Global.hpp"
#include "arena/data/EntityDataManager.h"

#include "nlohmann/json.hpp"
#include "tl/expected.hpp"
#include "spdlog/spdlog.h"

#include "canvas/Canvas.h"
#include "arena/logic/Arena.h"

using namespace canvas;
using namespace arena::data;
using namespace arena::logic;

using json = nlohmann::json;

std::vector<std::string> allowed_characters = {
	"Knight",
	"Archer",
	"Goblin",
	"Giant",
	"Pekka",
	"Minion",
	"Balloon",
	"Witch",
	"Skeleton",
	"Barbarian",
	"Golem",
	"Golemite",
	"Valkyrie",
	"Bomber",
	"Musketeer",
	"BabyDragon",
	"MiniPekka",
	"Wizard",
	"Prince",
	"SpearGoblin",
	"GiantSkeleton",
	"HogRider",
	// "TowerPrincess",
	"IceWizard",
	"RoyalGiant",
	"Princess",
	"DarkPrince",
	"SkeletonWarrior",
	"LavaHound",
	"LavaPups",
	"RageBarbarian",
	"IceSpirits",
	"FireSpirits",
	"Miner",
	"ZapMachine",
	"Bowler",
	"IceGolemite",
	"MegaMinion",
	"InfernoDragon",
	"BattleRam",
	"BlowdartGoblin",
	"ElectroWizard",
	"AngryBarbarian",
	"AxeMan",
	"Assassin",
	// "GhostOverlay",
	"Ghost",
	"MiniZapMachine",
	"Hunter",
	"DarkWitch",
	"Bat",
	"Recruit",
	"RascalBoy",
	"MovingCannon",
	"MegaKnight",
	"RascalGirl",
	"SkeletonBalloon",
	"DartBarrell",
	"Wallbreaker",
	"RoyalHog",
	"GoblinBrawler",
	"GoblinGiant",
	"EliteArcher",
	//"SpearGoblinGiant",
	"Ram",
	//"RamRider",
	"ThreeMusketeer",
	"ElectroDragon",
	"Fisherman",
	"ElixirGolem1",
	"ElixirGolem2",
	"ElixirGolem4",
	"HealSpirit",
	// "YetAnotherSkeleton",
	"Firecracker",
	"BattleHealer",
	"DeliveryRecruit",
	"MightyMiner",
	// "SuperWitch",
	// "GoblinDrillDig",
	"WitchMother",
	"VoodooHog",
	"SkeletonDragon",
	"ElectroGiant",
	"ElectroSpirit",
	// "SuperLavaHound",
	"SkeletonKing",
	// "SuperLavaHound2",
	//"SuperEliteArcher",
	//"SkeletonKingSkeleton",
	// "SuperHogRider",
	// "SuperIceGolemite",
	"GoldenKnight",
	"ArcherQueen",
	// "GoblinParty",
	// "SpearGoblinParty",
	// "GoblinBrawlerParty",
	// "GoblinDummy",
	"Monk",
};


std::vector<ArenaType> allowed_arenas = {
	ArenaType::Goblin_Stadium,
	ArenaType::Bone_Pit,
	ArenaType::Barbarian_Bowl,
	ArenaType::Spell_Valley,
	ArenaType::Builders_Workshop,
	ArenaType::PEKKAs_Playhouse,
	ArenaType::Royal_Arena,
	ArenaType::Frozen_Peak,
	ArenaType::Jungle_Arena,
	ArenaType::Hog_Mountain,
	ArenaType::Chess_Arena,
	ArenaType::Electro_Valley,
	ArenaType::Spooky_Town,
	ArenaType::Rascals_Hideout,
	ArenaType::Serenity_Peak,
	ArenaType::Miners_Mine,
	ArenaType::Executioners_Kitchen,
	ArenaType::Royal_Crypt,
	ArenaType::Silent_Sanctuary,
	ArenaType::Dragon_Spa,
	ArenaType::Boot_Camp,
	ArenaType::Clash_Fest,
	ArenaType::Touchdown_Arena,
	ArenaType::Boat_Arena,
	ArenaType::Rock_Evolution_Arena,
	ArenaType::Cake_Arena,
	ArenaType::ClanBoat_Arena,
	ArenaType::Dream_Arena,
	ArenaType::Flood_Arena,
	ArenaType::Shipwreck_Arena,
};


tl::expected<bool, std::string> try_read_settings_json() {
	if (!std::filesystem::is_directory("config") || !std::filesystem::exists("config")) {
		std::filesystem::create_directory("config");
	}
	if (!std::filesystem::is_regular_file("config/settings.json") || !std::filesystem::exists("config/settings.json")) {
		json j = {
			{"image_count", 0},
			{"character_min_count", 0},
			{"character_max_count", 0},
			{"asset_directory", ""},
			{"output_directory", ""},
			{"display_bounding_boxes", false},
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

std::pair<std::vector<json>, json> generate_battle(int image_id, int character_count, long total_character_count, std::filesystem::path& asset_directory, std::filesystem::path& output_image_directory) {
	auto& random = Random::get_instance();

	auto& entity_data_manager = EntityDataManager::getInstance();

	spdlog::info("Generating image {} with {} characters!\n", image_id, character_count);
	auto arena_result = Arena::try_create(allowed_arenas[random.random_int_from_interval(0, allowed_arenas.size() - 1)], TowerSkin::Default, TowerSkin::Default);
	if (!arena_result.has_value()) {
		spdlog::error("An error has occurred: {}\n", arena_result.error());
		throw std::exception();
	}

	std::vector<json> character_coco_objects;

	Arena arena = arena_result.value();
	for (int character_id = 0; character_id < character_count; character_id++) {
		int add_attempts = 0;
		while (add_attempts < 100)
		{
			int character_type_id = random.random_int_from_interval(0, allowed_characters.size() - 1);
			auto entity_data = entity_data_manager.getEntityDataByName(allowed_characters[character_type_id]);
			if (entity_data == nullptr) {
				continue;
			}
			auto maybeCharacter = Entity::create(
				entity_data,
				entity_data_manager.getRandomEntityImage(entity_data).value()
			);
			if (maybeCharacter.has_value()) {
				auto character = std::make_shared<arena::logic::Entity>(maybeCharacter.value());
				SkV2 position = SkV2{
					static_cast<float>(Random::get_instance().random_int_from_interval(64, 664)),
					static_cast<float>(Random::get_instance().random_int_from_interval(128, 954))
				};
				character->setPosition(position);
				character->addNonStackableEffect(EntityEffect::Damage);
				if (arena.try_add_character(character)) {
					json character_coco_object = {
						{"id", total_character_count + character_id},
						{"image_id", image_id},
						{"category_id", character_type_id + 1},
						{"segmentation", json::array()},
						{"area", character->size.x * character->size.y},
						{"bbox", json::array({
							character->rect.fLeft,
							character->rect.fTop,
							character->size.x,
							character->size.y,
						})},
						{"iscrowd", 0},
					};
					character_coco_objects.push_back(character_coco_object);
					break;
				}
				else {
					add_attempts++;
				}
			}
			else {
				spdlog::error("Unable to create character, Got error: {}", maybeCharacter.error());
				add_attempts++;
			}
		}
	}
	arena.draw();
	std::filesystem::path output_destination = output_image_directory / fmt::format("{:07}.png", image_id);
	{
		auto result = arena.try_save(output_destination);
		if (!result.has_value()) {
			spdlog::error("An error has occurred while trying to save the arena: {}\n", result.error());
			throw std::exception();
		}
	}
	spdlog::info("Completed generating image {}!\n", image_id);
	json image_coco_object = {
		{"id", image_id},
		{"width", arena.get_width()},
		{"height", arena.get_height()},
		{"file_name", output_destination},
	};
	return std::make_pair(character_coco_objects, image_coco_object);
}

json get_categories() {
	json category_json = json::array();
	for (int i = 0; i < allowed_characters.size(); i++) {
		category_json.push_back(
			json{
				{"id", i + 1},
				{"name", allowed_characters[i]},
			}
		);
	}
	return category_json;
}

int main() {
	auto start = std::chrono::system_clock::now();
	{
		std::time_t start_time = std::chrono::system_clock::to_time_t(start);
		std::cout << "Started computation at " << std::ctime(&start_time) << '\n';
	}

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
	int character_min_count(Global::get_json()["character_min_count"].get<int>());
	int character_max_count(Global::get_json()["character_max_count"].get<int>());

	if (character_min_count > character_max_count) {
		spdlog::error("character_min_count ({}) is greater than character_max_count ({})", character_min_count, character_max_count);
		return 0;
	}

	std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
	std::filesystem::path output_directory(Global::get_json()["output_directory"].get<std::string>());
	bool debug(Global::get_json()["debug"].get<bool>());
	if (debug) {
		spdlog::set_level(spdlog::level::debug);
	}

	auto output_image_directory = output_directory / "images";
	if (!std::filesystem::is_directory(output_image_directory) || !std::filesystem::exists(output_image_directory)) {
		std::filesystem::create_directory(output_image_directory);
	}

	std::vector<json> character_coco_objects_vector;
	std::vector<json> image_coco_object_vector;

	spdlog::info("Starting to generate images and annotations!\n");
	long total_character_count = 1;
	for (int image_id = 1; image_id < image_count + 1; image_id++) {
		int character_count = Random::get_instance().random_int_from_interval(character_min_count, character_max_count);
		auto result = generate_battle(image_id, character_count, total_character_count, asset_directory, output_image_directory);
		std::vector<json> character_coco_objects = result.first;
		json image_coco_object = result.second;

		character_coco_objects_vector.insert(character_coco_objects_vector.end(), character_coco_objects.begin(), character_coco_objects.end());
		image_coco_object_vector.push_back(image_coco_object);
		total_character_count += character_count;
	}

	json coco_annotations = {
		{"categories", get_categories()},
		{"images", image_coco_object_vector},
		{"annotations", character_coco_objects_vector},
	};

	std::ofstream outfile(output_directory / "annotations.json");
	outfile << coco_annotations.dump() << std::endl;
	outfile.close();

	spdlog::info("Completed generating all images and annotations!");

	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s"
		<< std::endl;
	return 0;
}