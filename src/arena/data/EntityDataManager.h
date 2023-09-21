#ifndef ENTITY_DATA_MANAGER_H
#define ENTITY_DATA_MANAGER_H

#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>

#include "spdlog/spdlog.h"

#include "../../utils/Global.hpp"
#include "../../utils/Random.h"

#include "../../files/FileManager.h"
#include "../../files/data/AbstractTable.h"
#include "../../files/data/File.h"
#include "../data/EntityData.h"

#include "EntityDataTable.hpp"
#include "../../canvas/Image.h"
#include "../../canvas/ImageLoader.h"

using namespace csv;
using namespace canvas;

namespace arena::data
{
    class EntityDataManager
    {
    public:
        EntityDataManager();
        EntityDataManager(EntityDataManager const&) = delete;
        EntityDataManager& operator=(EntityDataManager const&) = delete;
        static EntityDataManager& getInstance() {
            static EntityDataManager instance;
            return instance;
        }
        ~EntityDataManager();
        void insertEvolutionToml(std::filesystem::path filePath);

        tl::expected<Image, std::string> getRandomEntityImage(pEntityData entity_data, bool is_blue);

        SkColor getAverageColor(pEntityData entity_data, Image& image);
        
        pEntityData getEntityDataByFileName(std::string fileName);
        pEntityData getEntityDataByName(std::string name);
    private:
        std::unordered_map<std::string, pEntityData> entity_data_file_name_map;
        std::unordered_map<std::string, pEntityData> entity_data_name_map;

        std::unordered_set<std::string> characters_with_one_orientation;
 
        std::unordered_map<std::string, SkColor> color_map;
    };
}

#endif