#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>

#include "../data/EntityColorManager.hpp"

#include "../../canvas/ImageLoader.h"
#include "../../canvas/Drawable.h"
#include "../../canvas/Canvas.h"

#include "../data/EntityData.h"

#include "../../utils/Global.hpp"

using namespace arena::data;
using namespace csv;
using namespace canvas;

namespace arena {
	class Entity : public Drawable
	{
	public:
		void addSpawnCharacter(std::shared_ptr<Entity> spawn_character);
		void setPosition(int x, int y);
		void draw(Canvas& canvas);
		void draw_bounding_box(Canvas& canvas, SkRect& entity_rect, Image& image);
		~Entity();

		pEntityData entity_data;
		std::filesystem::path file_path;
		int x;
		int y;
		SkV2 size;
		std::shared_ptr<Entity> spawn_character = nullptr;
	protected:
		Entity(pEntityData entity_data, std::filesystem::path file_path);
	};
	typedef std::shared_ptr<Entity> pEntity;
}

#endif