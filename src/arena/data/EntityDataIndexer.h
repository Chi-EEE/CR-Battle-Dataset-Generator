#ifndef ENTITY_DATA_INDEXER_H
#define ENTITY_DATA_INDEXER_H

#pragma once

#include <string>
#include <unordered_map>

#include "../../utils/Global.hpp"

#include "../../files/FileManager.h"
#include "../../files/data/AbstractTable.h"
#include "../../files/data/File.h"
#include "../data/EntityData.h"

#include "EntityDataTable.hpp"

using namespace csv;

namespace arena::data
{
    class EntityDataIndexer
    {
    public:
        EntityDataIndexer();
        EntityDataIndexer(EntityDataIndexer const&) = delete;
        EntityDataIndexer& operator=(EntityDataIndexer const&) = delete;
        static EntityDataIndexer& getInstance() {
            static EntityDataIndexer instance;
            return instance;
        }
        ~EntityDataIndexer();
        void insertEvolutionToml(std::filesystem::path filePath);
        pEntityData getEntityDataByFileName(std::string fileName);
        pEntityData getEntityDataByName(std::string name);
    private:
        std::unordered_map<std::string, pEntityData> entity_data_file_name_map;
        std::unordered_map<std::string, pEntityData> entity_data_name_map;
    };
}

#endif