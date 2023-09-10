#ifndef ENTITY_DATA_INDEXER_H
#define ENTITY_DATA_INDEXER_H

#pragma once

#include <string>
#include <unordered_map>

#include "../utils/Global.hpp"

#include "../files/CSV.h"
#include "../files/CSVLogic/EntityData.h"

using namespace CSV::Logic;

namespace arena_files
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
        pEntityData getEntityDataByFileName(std::string fileName);
        pEntityData getEntityDataByName(std::string name);
    private:
        std::unordered_map<std::string, pEntityData> entity_data_file_name_map;
        std::unordered_map<std::string, pEntityData> entity_data_name_map;
    };
}

#endif