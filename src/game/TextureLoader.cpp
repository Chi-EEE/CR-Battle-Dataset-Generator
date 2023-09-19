#include "TextureLoader.h"
#include <iostream>
namespace game {
	TextureLoader::TextureLoader()
	{

	}

	// There is not a memory leak here since the images are being loaded here!
	tl::expected<Texture, std::string> TextureLoader::try_load_image(std::filesystem::path file_path)
	{
		auto it = this->images.find(file_path);
		if (it != this->images.end())
			return it->second;
		auto maybe_texture = Texture::try_from_file(file_path);
		if (!maybe_texture.has_value()) {
			return maybe_texture;
		}
		Texture texture = maybe_texture.value();
		this->images.insert(std::make_pair(file_path, texture));
		return texture;
	}
}