#include "CSV.h"
#include "CSVLogic/EntityData.h"
using namespace CSV::Logic;

namespace CSV
{
	CSV::CSV()
	{
		this->tables.insert(std::make_pair(File::Entity, new Table<EntityData>{}));
		//addFile(File::Entity, "entities.csv");
		//addFile(File::Entity, "buildings.csv");
	}

	CSV::~CSV()
	{
		for (auto table = this->tables.begin(); table != this->tables.end(); ++table)
		{
			delete (*table).second;
		}
		this->tables.clear();
	}

	AbstractTable* CSV::getTable(File csvFileType)
	{
		if (contains(csvFileType))
		{
			return this->tables[csvFileType];
		}
		else
		{
			std::cerr << "Unable to find the CSVFile Enum for " << csvFileType;
			return nullptr;
		}
	}

	void CSV::addFile(File csvFileType, std::string fileName)
	{
		if (contains(csvFileType))
		{
			this->tables[csvFileType]->insert(fileName);
		}
		else
		{
			std::cerr << "Unable to find the CSVFile Enum for " << csvFileType;
		}
	}

	inline bool CSV::contains(File csvFileType) {
		auto it = this->tables.find(csvFileType);
		return it != this->tables.end();
	}
}