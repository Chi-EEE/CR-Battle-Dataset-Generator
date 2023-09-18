#ifndef IMAGE_H
#define IMAGE_H

#pragma once

#include "tl/expected.hpp"
#include "fmt/format.h"

#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Vector3.hpp"

#include <filesystem>
#include <string>

namespace canvas {
	class Texture
	{
	public:
		static tl::expected<Texture, std::string> try_from_file(std::filesystem::path file_path);
		Texture(sf::Texture texture);
		~Texture();
		sf::Texture get_texture() {
			return texture;
		}
		tl::expected<sf::Vector3<float>, std::string> get_average_color();
		sf::Vector2u get_size() {
			return this->texture.getSize();
		}
	private:
		sf::Texture texture;
	};
}

#endif