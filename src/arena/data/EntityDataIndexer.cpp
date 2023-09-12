#include "EntityDataIndexer.h"

namespace arena::data
{
	EntityDataIndexer::EntityDataIndexer()
	{
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
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
	}

	EntityDataIndexer::~EntityDataIndexer()
	{

	}

	void EntityDataIndexer::insertEvolutionToml(std::filesystem::path filePath)
	{
		auto& file_manager_instance = FileManager::FileManager::getInstance();
		toml::table tbl = toml::parse_file(filePath.string());
		for (auto pair : tbl) {
			std::string name(pair.first.str());
			toml::table* table = pair.second.as_table();
			std::string base = table->get("Base")->value<std::string>().value();
			pEntityData base_entity_data = this->getEntityDataByName(base);
			if (base_entity_data == nullptr) {
				std::cerr << "Unable to get the base_entity_data!\n";
			}
			EntityDataTable *entity_data_table = static_cast<EntityDataTable*>(file_manager_instance.getTable(File::Entity));
			entity_data_table->insertEvolutionEntity(File::Entity, name, table, base_entity_data);
		}
	};

	pEntityData EntityDataIndexer::getEntityDataByFileName(std::string file_name)
	{
		return this->entity_data_file_name_map["sc/" + file_name];
	}

	pEntityData EntityDataIndexer::getEntityDataByName(std::string name)
	{
		return this->entity_data_name_map[name];
	}
}