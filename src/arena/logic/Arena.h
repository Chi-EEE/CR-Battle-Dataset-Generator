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

#include "SFML/Graphics.hpp"

#include "ArenaType.h"

#include "../../game/TextureLoader.h"
#include "../../game/AnnotationBox.h"

#include "TowerSkin.h"

#include "Entity.h"

#include "../data/EntityDataManager.h"
#include "../data/EntityData.h"

namespace arena::logic {
	class Arena : public sf::Drawable
	{
	public:
		static tl::expected<Arena, std::string> try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side);
		bool try_add_entity(pEntity character);
		~Arena();
		Arena clone();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		sf::Vector2u get_size() { return this->texture.getSize(); }

	private:
		Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Texture texture);
		void add_arena_tower(pEntityData entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y);
		tl::expected<Texture, std::string> try_get_arena_tower_texture(std::string character, std::string team_side, TowerSkin tower_skin);

		std::vector<pEntity> air_entities;
		std::vector<pEntity> ground_entities;

		ArenaType arena_type;
		TowerSkin blue_side_tower_skin;
		TowerSkin red_side_tower_skin;

		Texture texture;
	};
}

#endif