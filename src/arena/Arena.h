#ifndef ARENA_H
#define ARENA_H

#pragma once

#include <filesystem>

#include <random>

#include "../utils/Random.h"
#include "../utils/Global.hpp"

#include "fmt/format.h"
#include "tl/expected.hpp"

#include "ArenaType.h"
#include "../canvas/Canvas.h"
#include "../canvas/ImageLoader.h"
#include "TowerSkin.h"
#include "Entity.h"

using namespace canvas;

namespace arena {
    class Arena
    {
    public:
        static tl::expected<Arena, std::string> try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side);
        void draw();
        ~Arena();
        Arena clone();
        tl::expected<nullptr_t, std::string> try_save(std::string fileName);
        tl::expected<Image, std::string> try_get_image(Entity entity);
        tl::expected<nullptr_t, std::string> try_draw_entity(Entity entity);
    private:
        Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas);
        tl::expected<std::filesystem::path, std::string> try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin);

        std::vector<Entity> entities;

        ArenaType arena_type;
        TowerSkin blue_side;
        TowerSkin red_side;

        Canvas canvas;
    };
}

#endif