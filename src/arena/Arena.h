#ifndef ARENA_H
#define ARENA_H

#pragma once

#include <filesystem>

#include <optional>

#include "../utils/Random.h"
#include "../utils/Global.hpp"

#include "fmt/format.h"
#include "tl/expected.hpp"

#include "ArenaType.h"
#include "../canvas/Canvas.h"
#include "../canvas/ImageLoader.h"
#include "TowerSkin.h"

#include "Entity.h"
#include "Building.h"
#include "Character.h"

#include "../arena_files/EntityDataIndexer.h"
#include "../files/CSVLogic/EntityData.h"

using namespace canvas;

namespace arena {
	class Arena
	{
	public:
		static tl::expected<Arena, std::string> try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side);
		bool try_add_character(std::shared_ptr<Character> character);
		void draw();
		~Arena();
		Arena clone();
		tl::expected<nullptr_t, std::string> try_save(std::string fileName);
	private:
		Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas);
		void add_arena_tower(std::shared_ptr<EntityData> entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y, bool is_air);
		tl::expected<std::filesystem::path, std::string> try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin);

		std::vector<std::shared_ptr<Entity>> entities;

		ArenaType arena_type;
		TowerSkin blue_side_tower_skin;
		TowerSkin red_side_tower_skin;

		Canvas canvas;
	};
}

#endif