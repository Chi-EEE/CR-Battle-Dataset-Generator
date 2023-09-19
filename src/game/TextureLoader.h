#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#pragma once

#include <filesystem>
#include <unordered_map>

#include "tl/expected.hpp"

#include "Texture.h"

namespace game {
	class TextureLoader
	{
	public:
		TextureLoader();
		TextureLoader(TextureLoader const&) = delete;
		TextureLoader& operator=(TextureLoader const&) = delete;

		tl::expected<Texture, std::string> try_load_image(std::filesystem::path file_path);

		static TextureLoader& get_instance() {
			static TextureLoader instance;
			return instance;
		}
	private:
		std::unordered_map<std::filesystem::path, Texture> images;
	};
}

#endif