#include "CSV.h"
#include "CSVLogic/EntityData.h"
#include "CSVLogic/ProjectileData.h"
#include "CSVLogic/SpellData.h"
using namespace CSV::Logic;

namespace CSV
{
	CSV::CSV()
	{
		this->tables.insert(std::make_pair(File::Entity, new Table<EntityData>()));
		this->tables.insert(std::make_pair(File::Projectile, new Table<ProjectileData>()));
		this->tables.insert(std::make_pair(File::Spell, new Table<SpellData>()));
		addFile(File::Entity, "entities.csv");
		addFile(File::Entity, "buildings.csv");
		addFile(File::Projectile, "projectiles.csv");
		addFile(File::Spell, "spells_buildings.csv");
		addFile(File::Spell, "spells_characters.csv");
		addFile(File::Spell, "spells_other.csv");
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
		if (this->tables.contains(csvFileType))
		{
			return this->tables[csvFileType];
		}
		else
		{
			std::cerr << "Unable to find the CSVFile Enum for " << csvFileType;
		}
	}

	void CSV::addFile(File csvFileType, std::string fileName)
	{
		if (this->tables.contains(csvFileType))
		{
			this->tables[csvFileType]->insert(fileName);
		}
		else
		{
			std::cerr << "Unable to find the CSVFile Enum for " << csvFileType;
		}
	}

}