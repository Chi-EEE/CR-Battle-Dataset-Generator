#ifndef IMAGE_H
#define IMAGE_H

#pragma once

#include "tl/expected.hpp"
#include "core/SkData.h"
#include "core/SkImage.h"
#include "fmt/format.h"
#include <string>

namespace canvas {
	class Image
	{
	public:
		static tl::expected<Image, std::string> from_file(std::string file);
		Image(sk_sp<SkImage> image);
		~Image();
		sk_sp<SkImage> get_image() {
			return image;
		}
		int get_width() {
			return this->image->width();
		}
		int get_height() {
			return this->image->height();
		}
	private:
		sk_sp<SkImage> image;
	};
}

#endif