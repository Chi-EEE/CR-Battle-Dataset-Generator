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
	"Skeleton_EV1",
	"Barbarian_EV1",
	"RoyalGiant_EV1",
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

struct ThreadInfo {
	int thread_id;
	int end_character_id;
};

struct ThreadOutput {
	std::list<json> character_coco_objects_vector;
	std::list<json> image_coco_object_vector;
};

typedef std::pair<
	ThreadInfo,
	std::shared_future<ThreadOutput>
> ThreadPair;


tl::expected<bool, std::string> try_read_settings_json();
ThreadOutput generate_images(ThreadInfo thread_info, int start_image_id, int end_image_id);
std::pair<std::list<json>, json> generate_battle(int image_id, int character_count, std::filesystem::path& asset_directory, std::filesystem::path& output_image_directory);
json get_categories();
void create_annotations_json(std::filesystem::path& output_directory, json& coco_annotations);
void create_data_yaml(std::filesystem::path& output_directory);

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
	int thread_count(Global::get_json()["thread_count"].get<int>());

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
	{
		ThreadOutput thread_output = thread_futures[0].second.get();
		character_coco_objects_vector = std::move(thread_output.character_coco_objects_vector);
		image_coco_object_vector = std::move(thread_output.image_coco_object_vector);
	}

	for (int i = 1; i < thread_futures.size(); i++) {
		ThreadPair previous_thread_pair = thread_futures[i - 1];
		ThreadPair thread_pair = thread_futures[i];
		int threadId = thread_pair.first.thread_id;

		int previous_end_character_id = previous_thread_pair.first.end_character_id;

		ThreadOutput thread_output = thread_pair.second.get();

		for (auto& character_coco_object : thread_output.character_coco_objects_vector) {
			int character_id = character_coco_object["id"].get<int64_t>();
			character_coco_object["id"] = character_id + previous_end_character_id;
		}
		thread_pair.first.end_character_id = thread_output.character_coco_objects_vector.back()["id"].get<int64_t>();
		character_coco_objects_vector.splice(character_coco_objects_vector.end(), thread_output.character_coco_objects_vector);
		image_coco_object_vector.splice(image_coco_object_vector.end(), thread_output.image_coco_object_vector);
	}

	spdlog::info("Starting to generate images and annotations!\n");

	json coco_annotations = {
		{"categories", get_categories()},
		{"images", image_coco_object_vector},
		{"annotations", character_coco_objects_vector},
	};

	create_annotations_json(output_directory, coco_annotations);

	create_data_yaml(output_directory);

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
	if (!std::filesystem::is_regular_file("config/settings.json") || !std::filesystem::exists("config/settings.json")) {
		json j = {
			{"thread_count", 1},
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

ThreadOutput generate_images(ThreadInfo thread_info, int start_image_id, int end_image_id)
{
	std::list<json> character_coco_objects_vector;
	std::list<json> image_coco_object_vector;

	std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
	std::filesystem::path output_directory(Global::get_json()["output_directory"].get<std::string>());

	auto output_image_directory = output_directory / "images";

	int character_min_count(Global::get_json()["character_min_count"].get<int>());
	int character_max_count(Global::get_json()["character_max_count"].get<int>());
	for (int image_id = start_image_id; image_id < end_image_id; image_id++) {
		int character_count = Random::get_instance().random_int_from_interval(character_min_count, character_max_count);
		auto result = generate_battle(image_id, character_count, asset_directory, output_image_directory);
		std::list<json> character_coco_objects = result.first;
		json image_coco_object = result.second;

		character_coco_objects_vector.splice(character_coco_objects_vector.end(), character_coco_objects);
		image_coco_object_vector.push_back(image_coco_object);
	}
	return ThreadOutput{
		std::move(character_coco_objects_vector),
		std::move(image_coco_object_vector)
	};
}

std::pair<std::list<json>, json> generate_battle(int image_id, int character_count, std::filesystem::path& asset_directory, std::filesystem::path& output_image_directory) {
	auto& random = Random::get_instance();

	auto& entity_data_manager = EntityDataManager::getInstance();

	spdlog::info("Generating image {} with {} characters!\n", image_id, character_count);
	auto arena_result = Arena::try_create(allowed_arenas[random.random_int_from_interval(0, allowed_arenas.size() - 1)], TowerSkin::Default, TowerSkin::Default);
	if (!arena_result.has_value()) {
		spdlog::error("An error has occurred: {}\n", arena_result.error());
		throw std::exception();
	}

	std::list<json> character_coco_objects;

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
					if (random.random_int_from_interval(0, 1)) {
						std::vector<EntityEffect> non_stackable_entity_effects_vector(non_stackable_entity_effects);
						do {
							int index = random.random_int_from_interval(0, non_stackable_entity_effects_vector.size() - 1);
							EntityEffect effect = non_stackable_entity_effects_vector[index];
							character->addNonStackableEffect(effect);
							non_stackable_entity_effects_vector.erase(non_stackable_entity_effects_vector.begin() + index);
						} while (character->non_stackable_effects.size() < 2 && !non_stackable_entity_effects_vector.empty() && random.random_int_from_interval(0, 1));
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
