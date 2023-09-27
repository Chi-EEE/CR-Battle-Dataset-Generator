#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#pragma once

#include <filesystem>
#include <mutex>

#include "tl/expected.hpp"

#include "Image.h"

#include "../utils/Global.hpp"
#include "../utils/LRUCache.hpp"

namespace canvas {
	class ImageLoader
	{
	public:
		ImageLoader();
		ImageLoader(ImageLoader const&) = delete;
		ImageLoader& operator=(ImageLoader const&) = delete;

		tl::expected<Image, std::string> try_load_image(std::filesystem::path file_path);

		static ImageLoader& get_instance() {
			static ImageLoader instance;
			return instance;
		}
	private:
		LRUCache<std::filesystem::path, Image> images;

		std::mutex mtx;
	};
}

#endif