#include "EntityDataManager.h"

namespace arena::data
{
	EntityDataManager::EntityDataManager()
	{
		const json& settings_json = Global::getSettings();
		std::filesystem::path asset_directory(settings_json["asset_directory"].get<std::string>());
		auto& file_manager_instance = FileManager::FileManager::getInstance();
		file_manager_instance.createTable(File::Entity, new EntityDataTable{});
		file_manager_instance.addCSVFile(File::Entity, (asset_directory / "files" / "buildings.csv").string());
		file_manager_instance.addCSVFile(File::Entity, (asset_directory / "files" / "characters.csv").string());
		EntityDataTable* entity_data_table = static_cast<EntityDataTable*>(file_manager_instance.getTable(File::Entity));
		for (auto entity_data : entity_data_table->getEntries()) {
			this->entity_data_file_name_map.insert(std::make_pair(entity_data->getFileName(), entity_data));
			this->entity_data_name_map.insert(std::make_pair(entity_data->getName(), entity_data));
		}
		this->insertEvolutionToml(asset_directory / "files" / "characters_evo.toml");
		for (auto entity_data : entity_data_table->getEntries()) { // Could improve this!
			this->entity_data_file_name_map.insert(std::make_pair(entity_data->getFileName(), entity_data));
			this->entity_data_name_map.insert(std::make_pair(entity_data->getName(), entity_data));
		}
	}

	EntityDataManager::~EntityDataManager()
	{

	}

	void EntityDataManager::insertEvolutionToml(std::filesystem::path filePath)
	{
		auto& file_manager_instance = FileManager::FileManager::getInstance();
		toml::table tbl = toml::parse_file(filePath.string());
		for (auto pair : tbl) {
			std::string name(pair.first.str());
			toml::table* table = pair.second.as_table();
			std::string base = table->get("Base")->value<std::string>().value(); // Evo Entity Toml's should have this!
			pEntityData base_entity_data = this->getEntityDataByName(base);
			if (base_entity_data == nullptr) {
				std::cerr << "Unable to get the base_entity_data!\n";
			}
			EntityDataTable* entity_data_table = static_cast<EntityDataTable*>(file_manager_instance.getTable(File::Entity));
			entity_data_table->insertEvolutionEntity(File::Entity, name, table, base_entity_data);
		}
	}

	tl::expected<Image, std::string> EntityDataManager::getRandomEntityImage(pEntityData entity_data, bool is_blue)
	{
		const json& settings_json = Global::getSettings();
		Random& random = Random::get_instance();
		std::filesystem::path asset_directory(settings_json["asset_directory"].get<std::string>());

		std::string file_name = entity_data->getFileName();
		file_name.erase(0, 3); // Remove "/sc"

		auto character_directory = asset_directory / "sprites" / "characters" / file_name;

		std::vector<std::string> actions{
			"idle1",
			"run1",
			"attack1",
		};;

		if (!entity_data->getAbility().empty()) {
			actions.push_back("ability1");
		};

		// TODO: Check if this is still used, its only used for fisherman
		/*if (!entity_data->getProjectileSpecial().empty()) {
			actions.push_back("loading1");
		}*/

		auto action = actions[random.random_int_from_interval(0, actions.size() - 1)];
		std::filesystem::path directory_path = character_directory / fmt::format("{export_name}_{action}_1", fmt::arg("export_name", is_blue ? entity_data->getBlueExportName() : entity_data->getRedExportName()), fmt::arg("action", action));
		if (characters_with_one_orientation.find(entity_data->getName()) == characters_with_one_orientation.end()) {
			directory_path = character_directory / fmt::format("{export_name}_{action}_{orientation}", fmt::arg("export_name", is_blue ? entity_data->getBlueExportName() : entity_data->getRedExportName()), fmt::arg("action", action), fmt::arg("orientation", std::to_string(random.random_int_from_interval(1, 9))));
			if (!std::filesystem::exists(directory_path)) {
				characters_with_one_orientation.insert(entity_data->getName());
				directory_path = character_directory / fmt::format("{export_name}_{action}_1", fmt::arg("export_name", is_blue ? entity_data->getBlueExportName() : entity_data->getRedExportName()), fmt::arg("action", action));
			}
		}

		std::filesystem::path image_file_path;
		do {
			auto maybe_image = random.try_get_random_file_from_directory(directory_path);
			if (!maybe_image.has_value()) {
				spdlog::error("Unable to get an image from the directory: {} | {}", directory_path.string(), maybe_image.error());
				continue;
			}
			image_file_path = maybe_image.value();
		} while (image_file_path.filename().extension() != ".png");

		auto load_result = ImageLoader::get_instance().try_load_image(image_file_path);
		if (load_result.has_value()) {
			auto image = load_result.value();
			if (image.get_width() <= 1 || image.get_height() <= 1) {
				return tl::make_unexpected(fmt::format("Unable to load empty image: Either width ({}) or height ({}) is less than or equal to 1 from {}", image.get_width(), image.get_height(), image_file_path.string()));
			}
			return load_result.value();
		}
		else {
			return tl::make_unexpected(load_result.error());
		}
	}

	SkColor EntityDataManager::getAverageColor(pEntityData entity_data, Image& image) {
		auto it = this->color_map.find(entity_data->getName());
		if (it != this->color_map.end())
			return it->second;
		auto maybeColor = image.getAverageColor();
		if (!maybeColor.has_value()) {
			spdlog::error("Unable to get color from {}'s image", entity_data->getName());
			return SkColorSetARGB(255, 255, 255, 255);
		}
		SkColor color = maybeColor.value();
		this->color_map.insert(std::make_pair(entity_data->getName(), color));
		return color;
	}

	pEntityData EntityDataManager::getEntityDataByFileName(std::string file_name)
	{
		auto entity_data = this->entity_data_file_name_map["sc/" + file_name];
		if (entity_data == nullptr) {
			spdlog::error("Unable to get EntityData from sc/{}", file_name);
		}
		return entity_data;
	}

	pEntityData EntityDataManager::getEntityDataByName(std::string name)
	{
		auto entity_data = this->entity_data_name_map[name];
		if (entity_data == nullptr) {
			spdlog::error("Unable to get EntityData from {}", name);
		}
		return entity_data;
	}
}