#include <iostream>
#include <fstream>

#include <filesystem>
#include <unordered_set>

#include <list>

#include <thread>
#include <future>

#include "utils/Global.hpp"
#include "arena/data/EntityDataManager.h"

#include "nlohmann/json.hpp"
#include "nlohmann/json-schema.hpp"

#include "tl/expected.hpp"
#include "spdlog/spdlog.h"

#include "csv.hpp"

#include "canvas/Canvas.h"
#include "arena/logic/Arena.h"

using namespace canvas;
using namespace arena::data;
using namespace arena::logic;

using json = nlohmann::json;
using nlohmann::json_schema::json_validator;

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
	// "ThreeMusketeer",
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
	"Skeleton_EV1",
	"Firecracker_EV1",
	"RoyalGiant_EV1",
	"Barbarian_EV1",
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

std::vector<EntityEffect> non_stackable_entity_effects = {
	EntityEffect::Damage,
	EntityEffect::Freeze,
	EntityEffect::Heal,
};

static json settings_schema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "title": "Settings JSON",
    "properties": {
		"thread_count": {
			"description": "The amount of threads to generate images",
			"type": "integer",
			"default": 1,
            "minimum": 1
		},
		"image_count": {
			"description": "The amount of images to generate",
			"type": "integer",
			"default": 1,
            "minimum": 1
		},
		"image_cache_size": {
			"description": "The amount of images to generate",
			"type": "integer",
			"default": 15000,
            "minimum": 0
		},
		"character_min_count": {
			"description": "Minimum range to randomly generate characters",
			"type": "integer",
			"default": 5,
            "minimum": 0
		},
		"character_max_count": {
			"description": "Maximum range to randomly generate characters",
			"type": "integer",
			"default": 5,
            "minimum": 0
		},
		"asset_directory": {
			"description": "The directory where the CR assets are located",
			"default": "",
			"type": "string"
		},
		"output_directory": {
			"description": "The directory where the images are going to be outputted",
			"default": "",
			"type": "string"
		},
		"display_bounding_boxes": {
			"description": "Whether to display annotation boxes around the characters",
			"default": false,
			"type": "boolean"
		},
		"ready": {
			"description": "Set to 'true' when ready",
			"default": false,
			"type": "boolean"
		},
		"debug": {
			"description": "Whether to display debug messages",
			"default": false,
			"type": "boolean"
		}
    },
    "type": "object"
}

)"_json;

struct CharacterStatistic {
	int count;
	std::unordered_map<std::string, int> effect_count_map;
	std::unordered_map<int, int> ui_count_map;
};

struct BattleResult {
	std::list<json> character_coco_objects;
	json image_coco_object;

	ArenaType arena_type;
	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map;
};

struct ThreadInfo {
	int thread_id;
	int end_character_id;
};

struct ThreadOutput {
	std::list<json> character_coco_objects_vector;
	std::list<json> image_coco_object_vector;
	std::unordered_map<std::string, int> arena_count_map;
	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map;
};

typedef std::pair<
	ThreadInfo,
	std::shared_future<ThreadOutput>
> ThreadPair;

tl::expected<bool, std::string> try_read_settings_json();
ThreadOutput generate_images(ThreadInfo thread_info, int start_image_id, int end_image_id);
BattleResult generate_battle(int image_id, int total_character_count, int character_count, Random& random, std::filesystem::path& asset_directory, std::filesystem::path& output_image_directory);
json get_categories();
void create_annotations_json(std::filesystem::path& output_directory, json& coco_annotations);
void create_data_yaml(std::filesystem::path& output_directory);
void create_csv_stats(
	std::filesystem::path& output_directory,
	std::unordered_map<std::string, int> arena_count_map,
	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map
);

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
	const json& settings_json = Global::getSettings();

	int image_count(settings_json["image_count"].get<int>());
	int thread_count(settings_json["thread_count"].get<int>());

	int character_min_count(settings_json["character_min_count"].get<int>());
	int character_max_count(settings_json["character_max_count"].get<int>());

	if (character_min_count > character_max_count) {
		spdlog::error("character_min_count ({}) is greater than character_max_count ({})", character_min_count, character_max_count);
		return 0;
	}

	std::filesystem::path asset_directory(settings_json["asset_directory"].get<std::string>());
	std::filesystem::path output_directory(settings_json["output_directory"].get<std::string>());
	bool debug(settings_json["debug"].get<bool>());
	if (debug) {
		spdlog::set_level(spdlog::level::debug);
	}

	auto output_image_directory = output_directory / "images";
	if (!std::filesystem::is_directory(output_image_directory) || !std::filesystem::exists(output_image_directory)) {
		std::filesystem::create_directory(output_image_directory);
	}
	std::vector<std::thread> threads;
	std::vector<ThreadPair> thread_futures;
	int images_per_thread = image_count / thread_count;
	int remaining_images = image_count % thread_count;

	int image_id = 1;
	for (int thread_id = 0; thread_id < thread_count; ++thread_id) {
		ThreadInfo thread_info{
			thread_id,
			0
		};
		int start = image_id;
		int end = start + images_per_thread + (thread_id < remaining_images ? 1 : 0);
		std::packaged_task<ThreadOutput()> task(std::bind(generate_images, thread_info, start, end));
		std::shared_future<ThreadOutput> future = task.get_future();
		thread_futures.emplace_back(thread_info, std::move(future));
		threads.emplace_back(std::move(task));
		image_id = end;
	}

	std::sort(thread_futures.begin(), thread_futures.end(), [](const auto& t_1, const auto& t_2) -> bool
		{
			return t_1.first.thread_id < t_2.first.thread_id;
		}
	);

	std::list<json> character_coco_objects_vector;
	std::list<json> image_coco_object_vector;
	std::unordered_map<std::string, int> arena_count_map;
	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map;
	{
		ThreadInfo& thread_info = thread_futures[0].first;
		ThreadOutput thread_output = thread_futures[0].second.get();

		json last_character_coco_object = thread_output.character_coco_objects_vector.back();
		thread_info.end_character_id = last_character_coco_object["id"].get<int64_t>();

		character_coco_objects_vector = std::move(thread_output.character_coco_objects_vector);
		image_coco_object_vector = std::move(thread_output.image_coco_object_vector);

		for (const auto& arena_pair : thread_output.arena_count_map) {
			const std::string& arena_name = arena_pair.first;
			int arena_count = arena_pair.second;
			auto arena_it = arena_count_map.find(arena_name);
			if (arena_it != arena_count_map.end())
				arena_it->second += arena_count;
			else
				arena_count_map.insert(arena_pair);
		}

		for (const auto& character_pair : thread_output.character_stats_map) {
			const std::string& character_name = character_pair.first;
			std::shared_ptr<CharacterStatistic> character_stat = character_pair.second;
			auto character_it = character_stats_map.find(character_name);
			if (character_it != character_stats_map.end()) {
				std::shared_ptr<CharacterStatistic> main_character_stat = character_it->second;
				main_character_stat->count += character_stat->count;
				for (const auto& effect_pair : character_stat->effect_count_map) {
					const std::string& effect_name = effect_pair.first;
					int effect_count = effect_pair.second;
					auto effect_it = main_character_stat->effect_count_map.find(effect_name);
					if (effect_it != main_character_stat->effect_count_map.end())
						effect_it->second += effect_count;
					else
						main_character_stat->effect_count_map.insert(effect_pair);
				}
				for (const auto& ui_pair : character_stat->ui_count_map) {
					const int& ui_type = ui_pair.first;
					int ui_count = ui_pair.second;
					auto effect_it = main_character_stat->ui_count_map.find(ui_type);
					if (effect_it != main_character_stat->ui_count_map.end())
						effect_it->second += ui_count;
					else
						main_character_stat->ui_count_map.insert(ui_pair);
				}
			}
			else
				character_stats_map.insert(character_pair);
		}
	}

	for (int i = 1; i < thread_futures.size(); i++) {
		ThreadPair& previous_thread_pair = thread_futures[i - 1];
		ThreadPair& thread_pair = thread_futures[i];
		int threadId = thread_pair.first.thread_id;

		int previous_end_character_id = previous_thread_pair.first.end_character_id;

		ThreadInfo& thread_info = thread_pair.first;
		ThreadOutput thread_output = thread_pair.second.get();

		for (json& character_coco_object : thread_output.character_coco_objects_vector) {
			int character_id = character_coco_object["id"].get<int64_t>();
			character_coco_object["id"] = character_id + previous_end_character_id;
		}
		thread_info.end_character_id = thread_output.character_coco_objects_vector.back()["id"].get<int64_t>();
		
		character_coco_objects_vector.splice(character_coco_objects_vector.end(), std::move(thread_output.character_coco_objects_vector));
		image_coco_object_vector.splice(image_coco_object_vector.end(), std::move(thread_output.image_coco_object_vector));

		for (const auto& arena_pair : thread_output.arena_count_map) {
			const std::string& arena_name = arena_pair.first;
			int arena_count = arena_pair.second;
			auto arena_it = arena_count_map.find(arena_name);
			if (arena_it != arena_count_map.end())
				arena_it->second += arena_count;
			else
				arena_count_map.insert(arena_pair);
		}

		for (const auto& character_pair : thread_output.character_stats_map) {
			const std::string& character_name = character_pair.first;
			std::shared_ptr<CharacterStatistic> character_stat = character_pair.second;
			auto character_it = character_stats_map.find(character_name);
			if (character_it != character_stats_map.end()) {
				std::shared_ptr<CharacterStatistic> main_character_stat = character_it->second;
				main_character_stat->count += character_stat->count;
				for (const auto& effect_pair : character_stat->effect_count_map) {
					const std::string& effect_name = effect_pair.first;
					int effect_count = effect_pair.second;
					auto effect_it = main_character_stat->effect_count_map.find(effect_name);
					if (effect_it != main_character_stat->effect_count_map.end())
						effect_it->second += effect_count;
					else
						main_character_stat->effect_count_map.insert(effect_pair);
				}
				for (const auto& ui_pair : character_stat->ui_count_map) {
					const int& ui_type = ui_pair.first;
					int ui_count = ui_pair.second;
					auto effect_it = main_character_stat->ui_count_map.find(ui_type);
					if (effect_it != main_character_stat->ui_count_map.end())
						effect_it->second += ui_count;
					else
						main_character_stat->ui_count_map.insert(ui_pair);
				}
			}
			else
				character_stats_map.insert(character_pair);
		}
	}

	json coco_annotations = {
		{"categories", get_categories()},
		{"images", image_coco_object_vector},
		{"annotations", character_coco_objects_vector},
	};

	create_annotations_json(output_directory, coco_annotations);

	create_data_yaml(output_directory);

	create_csv_stats(output_directory, arena_count_map, character_stats_map);

	spdlog::info("Completed generating all images and annotations!");

	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
		<< "elapsed time: " << elapsed_seconds.count() << "s"
		<< std::endl;
	return 0;
}

tl::expected<bool, std::string> try_read_settings_json() {
	if (!std::filesystem::is_directory("config") || !std::filesystem::exists("config")) {
		std::filesystem::create_directory("config");
	}
	json_validator validator;
	try {
		validator.set_root_schema(settings_schema);
	}
	catch (const std::exception& e) {
		return tl::make_unexpected(fmt::format("Validation of schema failed, here is why: {}\n", e.what()));
	}
	if (!std::filesystem::is_regular_file("config/settings.json") || !std::filesystem::exists("config/settings.json")) {
		json settings_json = "{}"_json;
		const auto default_patch = validator.validate(settings_json);
		settings_json = settings_json.patch(default_patch);
		std::ofstream settings_file("config/settings.json");
		settings_file << settings_json.dump(4) << std::endl;
		settings_file.close();
		return tl::make_unexpected("Please update the newly created file 'config/settings.json' and set the 'ready' key to true.");
	}
	else {
		try {
			std::ifstream settings_file("config/settings.json");
			if (settings_file) {
				try {
					json settings_json;
					settings_file >> settings_json;
					const auto default_patch = validator.validate(settings_json);
					if (default_patch != nullptr) {
						settings_json = settings_json.patch(default_patch);
					}
					Global::setSettings(settings_json);
					return settings_json["ready"].get<bool>();
				}
				catch (const std::exception& e) {
					return tl::make_unexpected(fmt::format("Error loading JSON from file: {}", e.what()));
				}
			}
			else {
				return tl::make_unexpected("Unable to open 'config/settings.json'");
			}
		}
		catch (const std::exception& e) {
			return tl::make_unexpected(fmt::format("Validation failed, here is why: {}\n", e.what()));
		}
	}
}

ThreadOutput generate_images(ThreadInfo thread_info, int start_image_id, int end_image_id)
{
	Random& random = Random::get_instance();

	std::list<json> character_coco_objects_vector;
	std::list<json> image_coco_object_vector;
	std::unordered_map<std::string, int> arena_count_map;
	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map;

	const json& settings_json = Global::getSettings();

	std::filesystem::path asset_directory(settings_json["asset_directory"].get<std::string>());
	std::filesystem::path output_directory(settings_json["output_directory"].get<std::string>());

	auto output_image_directory = output_directory / "images";

	int character_min_count(settings_json["character_min_count"].get<int>());
	int character_max_count(settings_json["character_max_count"].get<int>());

	int total_character_count = 0;
	for (int image_id = start_image_id; image_id < end_image_id; image_id++) {
		int character_count = random.random_int_from_interval(character_min_count, character_max_count);
		BattleResult result = generate_battle(image_id, total_character_count, character_count, random, asset_directory, output_image_directory);
		std::list<json> character_coco_objects = result.character_coco_objects;
		json image_coco_object = result.image_coco_object;

		character_coco_objects_vector.splice(character_coco_objects_vector.end(), character_coco_objects);
		image_coco_object_vector.push_back(image_coco_object);

		auto arena_it = arena_count_map.find(result.arena_type.to_string());
		if (arena_it != arena_count_map.end())
			arena_it->second = arena_it->second + 1;
		else
			arena_count_map.insert(std::make_pair(result.arena_type.to_string(), 1));
		
		for (const auto& character_pair : result.character_stats_map) {
			const std::string& character_name = character_pair.first;
			std::shared_ptr<CharacterStatistic> character_stat = character_pair.second;

			auto character_it = character_stats_map.find(character_name);
			if (character_it != character_stats_map.end()) {
				std::shared_ptr<CharacterStatistic> main_character_stat = character_it->second;
				main_character_stat->count += character_stat->count;
				for (const auto& effect_pair : character_stat->effect_count_map) {
					const std::string& effect_name = effect_pair.first;
					int effect_count = effect_pair.second;
					auto effect_it = main_character_stat->effect_count_map.find(effect_name);
					if (effect_it != main_character_stat->effect_count_map.end())
						effect_it->second += effect_count;
					else
						main_character_stat->effect_count_map.insert(effect_pair);
				}
				for (const auto& ui_pair : character_stat->ui_count_map) {
					const int& ui_type = ui_pair.first;
					int ui_count = ui_pair.second;
					auto effect_it = main_character_stat->ui_count_map.find(ui_type);
					if (effect_it != main_character_stat->ui_count_map.end())
						effect_it->second += ui_count;
					else
						main_character_stat->ui_count_map.insert(ui_pair);
				}
			}
			else {
				character_stats_map.insert(character_pair);
			}
		}

		total_character_count += character_count;
	}
	return ThreadOutput{
		std::move(character_coco_objects_vector),
		std::move(image_coco_object_vector),
		std::move(arena_count_map),
		std::move(character_stats_map),
	};
}

BattleResult generate_battle(int image_id, int total_character_count, int character_count, Random& random, std::filesystem::path& asset_directory, std::filesystem::path& output_image_directory) {
	auto& entity_data_manager = EntityDataManager::getInstance();

	spdlog::info("Generating image {} with {} characters!\n", image_id, character_count);
	auto arena_type = allowed_arenas[random.random_int_from_interval(0, allowed_arenas.size() - 1)];
	auto arena_result = Arena::try_create(arena_type, TowerSkin::Default, TowerSkin::Default);
	if (!arena_result.has_value()) {
		spdlog::error("An error has occurred: {}\n", arena_result.error());
		throw std::exception();
	}

	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map;
	std::list<json> character_coco_objects;

	Arena arena = arena_result.value();
	for (int character_id = total_character_count; character_id < total_character_count + character_count; character_id++) {
		int add_attempts = 0;
		while (add_attempts < 100)
		{
			int character_type_id = random.random_int_from_interval(0, allowed_characters.size() - 1);
			std::string character_type_name = allowed_characters[character_type_id];
			auto entity_data = entity_data_manager.getEntityDataByName(character_type_name);
			if (entity_data == nullptr) {
				continue;
			}
			bool is_blue = random.random_int_from_interval(0, 1);
			Image character_image = [&entity_data_manager, &entity_data, is_blue]() {
				while (true) {
					auto character_image_result = entity_data_manager.getRandomEntityImage(entity_data, is_blue);
					if (character_image_result.has_value()) {
						return character_image_result.value();
					}
					spdlog::error(character_image_result.error());
				}
			}();
			auto maybeCharacter = Entity::create(
				entity_data,
				character_image,
				is_blue
			);
			if (maybeCharacter.has_value()) {
				auto character = std::make_shared<arena::logic::Entity>(maybeCharacter.value());
				SkV2 position = SkV2{
					static_cast<float>(Random::get_instance().random_int_from_interval(64, 664)),
					static_cast<float>(Random::get_instance().random_int_from_interval(128, 954))
				};
				character->setPosition(position);

				std::shared_ptr<CharacterStatistic> character_stat;
				auto character_it = character_stats_map.find(character_type_name);
				if (character_it != character_stats_map.end())
				{
					character_stat = character_it->second;
					character_stat->count += 1;
				}
				else 
				{
					character_stat = std::make_shared<CharacterStatistic>(CharacterStatistic{ 1 });
					character_stats_map.insert(std::make_pair(character_type_name, character_stat));
				}

				if (random.random_int_from_interval(0, 1)) {
					std::vector<EntityEffect> non_stackable_entity_effects_vector(non_stackable_entity_effects);
					do {
						int index = random.random_int_from_interval(0, non_stackable_entity_effects_vector.size() - 1);
						EntityEffect effect = non_stackable_entity_effects_vector[index];
						character->addNonStackableEffect(effect);

						auto effect_it = character_stat->effect_count_map.find(effect.to_string());
						if (effect_it != character_stat->effect_count_map.end()) effect_it->second = effect_it->second + 1;
						else character_stat->effect_count_map.insert(std::make_pair(effect.to_string(), 1));

						non_stackable_entity_effects_vector.erase(non_stackable_entity_effects_vector.begin() + index);
					} while (character->non_stackable_effects.size() < 2 && !non_stackable_entity_effects_vector.empty() && random.random_int_from_interval(0, 1));
				}
				else {
					auto effect_it = character_stat->effect_count_map.find("Empty");
					if (effect_it != character_stat->effect_count_map.end()) effect_it->second = effect_it->second + 1;
					else character_stat->effect_count_map.insert(std::make_pair("Empty", 1));
					character->non_stackable_effects.insert(EntityEffect::Empty);
				}
				bool ui_state = random.random_int_from_interval(0, 2);
				switch (ui_state) {
				case 0:
					break;
				case 1:
					character->level_ui = true;
					character->health_ui = true;
					break;
				case 2:
					character->level_ui = true;
					break;
				}
				auto ui_it = character_stat->ui_count_map.find(ui_state);
				if (ui_it != character_stat->ui_count_map.end()) ui_it->second = ui_it->second + 1;
				else character_stat->ui_count_map.insert(std::make_pair(ui_state, 1));

				if (arena.try_add_character(character)) {
					json character_coco_object = {
						{"id", character_id},
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
	return BattleResult{
		std::move(character_coco_objects),
		std::move(image_coco_object),

		std::move(arena_type),
		std::move(character_stats_map),
	};
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

void create_annotations_json(std::filesystem::path& output_directory, json& coco_annotations) {
	std::ofstream json_output_file(output_directory / "annotations.json");
	json_output_file << coco_annotations.dump() << std::endl;
	json_output_file.close();
}

void create_data_yaml(std::filesystem::path& output_directory) {
	toml::array character_array;
	for (auto& character : allowed_characters) {
		character_array.push_back(character);
	}

	auto yaml = toml::table{
		{ "train", "TRAINING_PATH" },
		{ "val", "VALIDATION_PATH" },
		{ "nc", static_cast<int64_t>(allowed_characters.size())},
		{ "names", character_array},
	};

	std::ofstream yaml_output_file(output_directory / "data.yaml");
	yaml_output_file << toml::yaml_formatter{ yaml } << std::endl;
	yaml_output_file.close();
}

void create_csv_stats(
	std::filesystem::path& output_directory,
	std::unordered_map<std::string, int> arena_count_map,
	std::unordered_map<std::string, std::shared_ptr<CharacterStatistic>> character_stats_map
) {
	std::ofstream arena_csv(output_directory / "arena.csv");
	auto arena_csv_writer = csv::make_csv_writer(arena_csv);
	std::vector<std::string> arena_headers = { "Name", "Count" };
	arena_csv_writer << arena_headers;
	for (const auto& arena_pair : arena_count_map) {
		const std::string& arena_name = arena_pair.first;
		int arena_count = arena_pair.second;
		arena_csv_writer << std::vector<std::string>({ arena_name, std::to_string(arena_count) });
	}

	auto entity_effect_values = EntityEffect::values();
	std::ofstream character_csv(output_directory / "character.csv");
	auto character_csv_writer = csv::make_csv_writer(character_csv);
	std::vector<std::string> character_headers = { "Name", "Count" };
	for (auto effect_name : entity_effect_values) {
		character_headers.push_back(effect_name);
	}
	character_csv_writer << character_headers;
	for (const auto& character_pair : character_stats_map) {
		const std::string& character_name = character_pair.first;
		std::shared_ptr<CharacterStatistic> character_stat = character_pair.second;
		std::vector<std::string> character_row;
		character_row.reserve(2 + entity_effect_values.size());
		character_row.push_back(character_name);
		character_row.push_back(std::to_string(character_stat->count));
		for (auto effect_name : entity_effect_values) {
			auto effect_it = character_stat->effect_count_map.find(effect_name);
			if (effect_it != character_stat->effect_count_map.end())
				character_row.push_back(std::to_string(effect_it->second));
			else
				character_row.push_back("0");
		}
		character_csv_writer << character_row;
	}
}