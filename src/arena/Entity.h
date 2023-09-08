#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>
#include "../canvas/ImageLoader.h"
#include "../canvas/Drawable.h"
#include "../canvas/Canvas.h"

namespace arena {
	class Entity : public canvas::Drawable
	{
	public:
		virtual void draw(canvas::Canvas& canvas) = 0;
		~Entity();

		std::string name;
		std::filesystem::path file_path;
		int x;
		int y;
		bool is_air;
	protected:
		Entity(std::string name, std::filesystem::path file_path, int x, int y, bool is_air);
	};
}

#endif