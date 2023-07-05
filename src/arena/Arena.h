#ifndef ARENA_H
#define ARENA_H

#pragma once

#include "fmt/format.h"

#include "ArenaType.h"
#include "../canvas/Canvas.h"
#include "../canvas/ImageLoader.h"
#include "TowerSkin.h"

using namespace canvas;

namespace arena {
    class Arena
    {
    public:
        static tl::expected<Arena, std::string> create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side);
        ~Arena();
        Arena clone();
        tl::expected<nullptr_t, std::string> save(std::string fileName);
    private:
        Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas);
        tl::expected<nullptr_t, std::string> draw_blue_side();
        tl::expected<nullptr_t, std::string> draw_blue_king_tower(int x, int y);
        tl::expected<nullptr_t, std::string> draw_blue_princess_tower(int x, int y);
        tl::expected<Image, std::string> get_blue_princess_tower();
        tl::expected<Image, std::string> get_blue_king_tower();
        tl::expected<nullptr_t, std::string> draw_red_side();
        ArenaType arena_type;
        TowerSkin blue_side;
        TowerSkin red_side;
        Canvas canvas;
    };
}

#endif