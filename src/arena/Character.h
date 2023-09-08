#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once

#include <optional>

#include "Entity.h"
#include "../canvas/Canvas.h"

#include "../files/CSV.h"
#include "../files/Table.hpp"
#include "../files/CSVLogic/EntityData.h"

using namespace canvas;

namespace arena {
    class Character : public Entity
    {
    public:
        static tl::expected<Character, std::string> create(std::string name, std::filesystem::path file_path, int x, int y, bool is_air);
        void draw(Canvas& canvas);
        ~Character();

    private:
        Character(std::string name, std::filesystem::path file_path, int x, int y, bool is_air);

    };
}

#endif