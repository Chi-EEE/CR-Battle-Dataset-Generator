#ifndef ENTITYCOLORMANAGER_H
#define ENTITYCOLORMANAGER_H

#pragma once

#include <unordered_map>
#include <string>

#include "SFML/Graphics.hpp"

#include "spdlog/spdlog.h"

#include "EntityData.h"
#include "../../game/Texture.h"

using namespace game;

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
		sf::Color getAverageColor(pEntityData entity_data, Texture& image) {
			auto it = this->color_map.find(entity_data->getName());
			if (it != this->color_map.end())
				return it->second;
			sf::Color color = image.getAverageColor();
			this->color_map.insert(std::make_pair(entity_data->getName(), color));
			return color;
		}
	private:
		std::unordered_map<std::string, sf::Color> color_map;
	};
}

#endif