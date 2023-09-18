#include "Image.h"
#include <iostream>
namespace canvas {
	tl::expected<Texture, std::string> Texture::try_from_file(std::filesystem::path file_path)
	{
		std::string file_string = file_path.string(); 
		sf::Texture texture;
		if (!texture.loadFromFile(file_string)) {
			return tl::make_unexpected(fmt::format("Failed to load image file! [{}]", file_string));
		}
		return Texture(texture);
	}

	Texture::Texture(sf::Texture texture) : texture(texture)
	{
	}

	Texture::~Texture()
	{

	}
	tl::expected<sf::Vector3<float>, std::string> Texture::get_average_color()
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
				sf::Color pixel_color = image.getPixel(x, y);
				if (pixel_color.a > 0) {
					totalR += pixel_color.r;
					totalG += pixel_color.g;
					totalB += pixel_color.b;
					++visiblePixelCount;
				}
			}
		}
		return sf::Vector3<float>{ totalR / visiblePixelCount * 1.0f, totalG / visiblePixelCount * 1.0f, totalB / visiblePixelCount * 1.0f };
	}
}