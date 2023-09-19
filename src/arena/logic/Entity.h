#ifndef ENTITY_H
#define ENTITY_H

#pragma once

#include <filesystem>

#include "SFML/Graphics.hpp"

#include "../data/EntityDataManager.h"
#include "../data/EntityColorManager.hpp"

#include "../../game/TextureLoader.h"

#include "../data/EntityData.h"

#include "../../utils/Global.hpp"
#include "../../utils/Random.h"

using namespace arena::data;
using namespace csv;
using namespace game;

namespace arena::logic {
	class Entity : public sf::Drawable
	{
	public:
		static tl::expected<Entity, std::string> create(pEntityData entity_data, Texture entity_texture);
		void setPosition(int x, int y);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		//void draw_annotation_box(Canvas& canvas);
		//void draw_shadow(Canvas& canvas);

		~Entity();

		pEntityData entity_data;
		std::filesystem::path file_path;
		int x;
		int y;
		
		sf::Vector2f size;
		sf::FloatRect rect;

		Texture texture;

		std::vector<std::shared_ptr<Entity>> spawn_entities;
	protected:
		Entity(pEntityData entity_data, Texture texture, std::vector<std::shared_ptr<Entity>> spawn_entities);
	};
	typedef std::shared_ptr<Entity> pEntity;
}

#endif