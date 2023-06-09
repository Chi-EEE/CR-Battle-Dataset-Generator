#include "ArenaType.h"
#include "../canvas/Canvas.h"
#ifndef ARENA_H
#define ARENA_H

#pragma once

using namespace canvas;

namespace arena {
    class Arena
    {
    public:
        static tl::expected<Arena, std::string> create(ArenaType arena_type);
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