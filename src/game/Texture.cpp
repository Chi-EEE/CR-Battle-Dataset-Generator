#include "Texture.h"
#include <iostream>
namespace game {
	tl::expected<Texture, std::string> Texture::try_from_file(std::filesystem::path file_path)
	{
		std::string file_string = file_path.string();
		sf::Texture texture;
		if (!texture.loadFromFile(file_string)) {
			return tl::make_unexpected(fmt::format("Failed to load texture file! [{}]", file_string));
		}
		return Texture(texture);
	}

	Texture::Texture(sf::Texture texture) : texture(texture)
	{
	}

	Texture::~Texture()
	{

	}
	sf::Color Texture::getAverageColor() const
	{
		sf::Image image = this->texture.copyToImage();

		sf::Vector2 size = this->texture.getSize();

		int width = size.x;
		int height = size.y;

		int totalR = 0;
		int totalG = 0;
		int totalB = 0;

		int visiblePixelCount = 0;
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				sf::Color pixelColor = image.getPixel(x, y);
				if (pixelColor.a > 0) {
					totalR += pixelColor.r;
					totalG += pixelColor.g;
					totalB += pixelColor.b;
					++visiblePixelCount;
				}
			}
		}
		return sf::Color{
			static_cast<sf::Uint8>(totalR / visiblePixelCount),
			static_cast<sf::Uint8>(totalG / visiblePixelCount),
			static_cast<sf::Uint8>(totalB / visiblePixelCount)
		};
	}
}