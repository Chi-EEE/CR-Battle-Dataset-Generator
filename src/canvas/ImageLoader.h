#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#pragma once

#include <filesystem>
#include <unordered_map>

#include "tl/expected.hpp"

#include "Image.h"

namespace canvas {
	class ImageLoader
	{
	public:
		ImageLoader();
		ImageLoader(ImageLoader const&) = delete;
		ImageLoader& operator=(ImageLoader const&) = delete;

		tl::expected<Texture, std::string> try_load_image(std::filesystem::path file_path);

		static ImageLoader& get_instance() {
			static ImageLoader instance;
			return instance;
		}
	private:
		std::unordered_map<std::filesystem::path, Texture> images;
	};
}

#endif