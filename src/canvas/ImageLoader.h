#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#pragma once

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

		tl::expected<Image, std::string> load_image(std::string file_name);

		static ImageLoader& getInstance() {
			static ImageLoader instance;
			return instance;
		}
	private:
		std::unordered_map<std::string, Image> images;
	};
}

#endif