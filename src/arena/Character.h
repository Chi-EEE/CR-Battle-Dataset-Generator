#ifndef CHARACTER_H
#define CHARACTER_H

#pragma once

#include "Entity.h"
#include "../canvas/Canvas.h"

using namespace canvas;

namespace arena {
    class Character : public Entity
    {
    public:
        Character(std::filesystem::path file_path, int x, int y, bool is_air);
        tl::expected<Character, std::string> create(std::filesystem::path file_path, int x, int y, bool is_air);
        void draw(Canvas& canvas);
        ~Character();

    private:

    };
}

#endif