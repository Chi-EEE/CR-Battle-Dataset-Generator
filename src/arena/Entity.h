#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>

namespace arena {
    class Entity
    {
    public:
        Entity(std::filesystem::path file_path, int x, int y, bool is_air);
        ~Entity();
        std::filesystem::path file_path;
        int x;
        int y;
        bool is_air;
    private:
    };
}

#endif