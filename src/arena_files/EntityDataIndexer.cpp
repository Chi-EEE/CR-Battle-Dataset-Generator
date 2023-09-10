#include "EntityDataIndexer.h"

namespace arena_files
{
	EntityDataIndexer::EntityDataIndexer()
	{
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
		auto& csv_instance = CSV::CSV::getInstance();
		csv_instance.addFile(CSV::File::Entity, (asset_directory / "csv" / "buildings.csv").string());
		csv_instance.addFile(CSV::File::Entity, (asset_directory / "csv" / "characters.csv").string());
		CSV::AbstractTable* entity_data_table = csv_instance.getTable(CSV::File::Entity);
		for (auto entity_data : static_cast<CSV::Table<EntityData>*>(entity_data_table)->getEntries()) {
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