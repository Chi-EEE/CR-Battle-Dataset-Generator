#ifndef TEXTURE_H
#define TEXTURE_H

#pragma once

#include "fmt/format.h"
#include "tl/expected.hpp";

#include "SFML/Graphics.hpp"

#include <filesystem>
#include <string>

namespace game {
	class Texture
	{
	public:
		static tl::expected<Texture, std::string> try_from_file(std::filesystem::path file_path);
		Texture(sf::Texture texture);
		~Texture();
		sf::Texture getTexture() const {
			return texture;
		}
		sf::Color getAverageColor() const;
		sf::Vector2u getSize() const {
			return this->texture.getSize();
		}
	private:
		sf::Texture texture;
	};
}

#endif