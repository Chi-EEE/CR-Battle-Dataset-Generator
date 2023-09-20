#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>

#include "../../canvas/ImageLoader.h"
#include "../../canvas/Drawable.h"
#include "../../canvas/Canvas.h"

#include "../data/EntityData.h"

#include "../../utils/Global.hpp"

using namespace arena::data;
using namespace csv;
using namespace canvas;

namespace arena::logic {
	class Entity : public Drawable
	{
	public:
        static tl::expected<Entity, std::string> create(pEntityData entity_data, Image image);
		void addSpawnCharacter(std::shared_ptr<Entity> spawn_character);
		void setPosition(int x, int y);
		void draw(Canvas& canvas);
		void draw_shadow(Canvas& canvas);
		~Entity();

		pEntityData entity_data;
		std::filesystem::path file_path;
		int x;
		int y;
		
		SkV2 size;
		SkRect rect;

		Image image;

		std::shared_ptr<Entity> spawn_character = nullptr;
	private:
		Entity(pEntityData entity_data, Image image);
	};
	typedef std::shared_ptr<Entity> pEntity;
}

#endif