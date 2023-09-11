#ifndef BUILDING_H
#define BUILDING_H

#pragma once

#include "Entity.h"
#include "../../canvas/Image.h"

using namespace canvas;

namespace arena {
    class Building : public Entity
    {
    public:
        static tl::expected<Building, std::string> create(pEntityData entity_data, std::filesystem::path file_path, int x, int y, bool is_air);
        void draw(Canvas& canvas) override;
        ~Building();
    private:
        Building(pEntityData entity_data, std::filesystem::path file_path, int x, int y, bool is_air);
    };
}
#endif