#ifndef ENTITYCOLORMANAGER_H
#define ENTITYCOLORMANAGER_H

#pragma once

#include <unordered_map>
#include <string>

#include <core/SkM44.h>
#include "spdlog/spdlog.h"

#include "EntityData.h"
#include "../../canvas/Image.h"
using namespace canvas;

namespace arena::data
{
	class EntityColorManager
	{
	public:
		EntityColorManager() {}
		EntityColorManager(EntityColorManager const&) = delete;
		EntityColorManager& operator=(EntityColorManager const&) = delete;
		static EntityColorManager& getInstance() {
			static EntityColorManager instance;
			return instance;
		}
		~EntityColorManager() {}
		SkColor get_average_color(pEntityData entity_data, Image& image) {
			auto it = this->color_map.find(entity_data->getName());
			if (it != this->color_map.end())
				return it->second;
			auto maybeColor = image.get_average_color();
			if (!maybeColor.has_value()) {
				spdlog::error("Unable to get color from {}'s image", entity_data->getName());
				return SkColorSetARGB(255, 255, 255, 255);
			}
			SkColor color = maybeColor.value();
			this->color_map.insert(std::make_pair(entity_data->getName(), color));
			return color;
		}
	private:
		std::unordered_map<std::string, SkColor> color_map;
	};
}

#endif