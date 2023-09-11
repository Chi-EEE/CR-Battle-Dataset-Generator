#include "EntityDataIndexer.h"

namespace arena::data
{
	EntityDataIndexer::EntityDataIndexer()
	{
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
		auto& file_manager_instance = FileManager::FileManager::getInstance();
		file_manager_instance.addCSVFile(File::Entity, (asset_directory / "files" / "buildings.csv").string());
		file_manager_instance.addCSVFile(File::Entity, (asset_directory / "files" / "characters.csv").string());
		file_manager_instance.addTomlFile(File::Entity, (asset_directory / "files" / "characters_evo.toml").string());
		AbstractTable* entity_data_table = file_manager_instance.getTable(File::Entity);
		for (auto entity_data : static_cast<Table<EntityData>*>(entity_data_table)->getEntries()) {
			this->entity_data_file_name_map.insert(std::make_pair(entity_data->getFileName(), entity_data));
			this->entity_data_name_map.insert(std::make_pair(entity_data->getName(), entity_data));
		}
	}

	EntityDataIndexer::~EntityDataIndexer()
	{

	}

	pEntityData EntityDataIndexer::getEntityDataByFileName(std::string file_name)
	{
		return this->entity_data_file_name_map["sc/" + file_name];
	}

	pEntityData EntityDataIndexer::getEntityDataByName(std::string name)
	{
		return this->entity_data_name_map[name];
	}
}