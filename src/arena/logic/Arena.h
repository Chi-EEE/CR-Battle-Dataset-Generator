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
#include "../../canvas/AnnotationBox.h"

#include "TowerSkin.h"

#include "Entity.h"

#include "../data/EntityDataManager.h"
#include "../data/EntityData.h"

using namespace canvas;

namespace arena::logic {
	class Arena
	{
	public:
		static tl::expected<Arena, std::string> try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side);
		bool try_add_character(pEntity character);
		void draw();
		~Arena();
		Arena clone();
		tl::expected<nullptr_t, std::string> try_save(std::filesystem::path file_path);
		int get_width() { return this->canvas.get_width(); }
		int get_height() { return this->canvas.get_height(); }
	private:
		Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas);
		void add_arena_tower(pEntityData entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y);
		tl::expected<Image, std::string> try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin);

		std::vector<pEntity> air_entities;
		std::vector<pEntity> ground_entities;

		ArenaType arena_type;
		TowerSkin blue_side_tower_skin;
		TowerSkin red_side_tower_skin;

		Canvas canvas;
	};
}

#endif