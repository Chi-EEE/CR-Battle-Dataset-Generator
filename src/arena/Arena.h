#ifndef ARENA_H
#define ARENA_H

#pragma once

#include "ArenaType.h"
#include "../canvas/Canvas.h"
#include "TowerSkin.h"

using namespace canvas;

namespace arena {
    class Arena
    {
    public:
        static tl::expected<Arena, std::string> create(ArenaType arena_type, TowerSkin::Enum red, TowerSkin blue);
        ~Arena();
        Arena clone();
        tl::expected<nullptr_t, std::string> save(std::string fileName);
    private:
        Arena(ArenaType arena_type, Canvas canvas);
        ArenaType arena_type;
        Canvas canvas;
    };
}

#endif