#ifndef GAME_H
#define GAME_H

#pragma once

#include "SFML/Graphics.hpp"
#include "../arena/logic/Arena.h"

using namespace arena::logic;

namespace game {
	class Game
	{
	public:
		Game(Arena arena);
		~Game();

		sf::Texture snapshot();

		void draw();
		void display();
		void clear();

		tl::expected<nullptr_t, std::string> try_save(std::filesystem::path file_path);

	private:
		sf::RenderWindow window;
		Arena arena;
	};
}
#endif