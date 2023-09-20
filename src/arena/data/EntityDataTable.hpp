#ifndef ENTITYDATATABLE_H
#define ENTITYDATATABLE_H

#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "toml++/toml.h"

#include "../../files/data/Data.h"
#include "../../files/data/Table.hpp"

#include "EntityData.h"

using namespace data;

namespace arena::data {
    class EntityDataTable : public Table<EntityData>
    {
    public:
        EntityDataTable() {};

		void insertEvolutionEntity(File fileType, std::string name, toml::table* table, pEntityData entity_data)
		{
			this->entries.push_back(std::make_shared<EntityData>(EntityData(name, table, entity_data.get())));
		};

    private:

    };
}

#endif