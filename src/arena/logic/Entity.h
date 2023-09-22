#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>
#include <unordered_set>
#include <vector>

#include "../../canvas/ImageLoader.h"
#include "../../canvas/Drawable.h"
#include "../../canvas/Canvas.h"

#include "../data/EntityDataManager.h"
#include "../data/EntityData.h"

#include "../../utils/Global.hpp"

#include "EntityEffect.h"

using namespace arena::data;
using namespace csv;
using namespace canvas;

namespace arena::logic {
	class Entity : public Drawable
	{
	public:
		static tl::expected<Entity, std::string> create(
			pEntityData entity_data, 
			Image entity_image,
			bool is_blue
		); 
		void setPosition(SkV2 position);
		void addNonStackableEffect(EntityEffect effect);
		void draw(Canvas& canvas);
		void draw_ui(Canvas& canvas);
		void draw_shadow(Canvas& canvas);
		~Entity();

		pEntityData entity_data;
		SkV2 position;
		SkV2 size;

		SkRect rect;

		Image image;

		bool is_blue;

		std::vector<std::shared_ptr<Entity>> spawn_entities;

		std::unordered_set<EntityEffect, EntityEffectHasher> non_stackable_effects;

		bool ui = false;
	private:
		Entity(
			pEntityData entity_data, 
			Image image,
			bool is_blue,
			std::vector<std::shared_ptr<Entity>> spawn_entities
		);
	};
	typedef std::shared_ptr<Entity> pEntity;
}

#endif