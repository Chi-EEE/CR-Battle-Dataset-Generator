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
		void draw_annotation_box(Canvas& canvas);
		void draw_shadow(Canvas& canvas);
		~Entity();

		pEntityData entity_data;
		std::filesystem::path file_path;
		int x;
		int y;
		
		sf::Vector2f size;
		sf::Rect<float> rect;

		Texture texture;

		std::shared_ptr<Entity> spawn_character = nullptr;
	protected:
		Entity(pEntityData entity_data, std::filesystem::path file_path);
	};
	typedef std::shared_ptr<Entity> pEntity;
}

#endif