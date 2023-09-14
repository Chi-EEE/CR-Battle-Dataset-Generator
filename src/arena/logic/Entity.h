#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>
#include "../../canvas/ImageLoader.h"
#include "../../canvas/Drawable.h"
#include "../../canvas/Canvas.h"

#include "../data/EntityData.h"

using namespace arena::data;
using namespace csv;

namespace arena {
	class Entity : public canvas::Drawable
	{
	public:
		void addSpawnCharacter(std::shared_ptr<Entity> spawn_character);
		void setPosition(int x, int y);
		virtual void draw(canvas::Canvas& canvas) = 0;
		~Entity();

		pEntityData entity_data;
		std::filesystem::path file_path;
		int x;
		int y;
		std::shared_ptr<Entity> spawn_character = nullptr;
	protected:
		Entity(pEntityData entity_data, std::filesystem::path file_path);
	};
	typedef std::shared_ptr<Entity> pEntity;
}

#endif