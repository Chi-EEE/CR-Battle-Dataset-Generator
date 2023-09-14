#ifndef ARENA_H
#define ARENA_H

#pragma once

#include <filesystem>
#include <optional>

#include "../../utils/Random.h"
#include "../../utils/Global.hpp"

#include "fmt/format.h"
#include "tl/expected.hpp"
#include "spdlog/spdlog.h"

#include "ArenaType.h"
#include "../../canvas/Canvas.h"
#include "../../canvas/ImageLoader.h"
#include "TowerSkin.h"

#include "Entity.h"
#include "Building.h"
#include "Character.h"

#include "../data/EntityDataIndexer.h"
#include "../data/EntityData.h"

using namespace canvas;

namespace arena {
	class Arena
	{
	public:
		static tl::expected<Arena, std::string> try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side);
		bool try_add_character(pCharacter character);
		void draw();
		~Arena();
		Arena clone();
		tl::expected<nullptr_t, std::string> try_save(std::filesystem::path file_path);
	private:
		Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas);
		void add_arena_tower(pEntityData entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y);
		tl::expected<std::filesystem::path, std::string> try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin);
		void draw_entity(pEntity entity);

		std::vector<pEntity> air_entities;
		std::vector<pEntity> ground_entities;

		ArenaType arena_type;
		TowerSkin blue_side_tower_skin;
		TowerSkin red_side_tower_skin;

		Canvas canvas;
	};
}

#endif