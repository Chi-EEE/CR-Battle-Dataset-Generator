#ifndef IMAGE_H
#define IMAGE_H

#pragma once

#include "tl/expected.hpp"
#include "core/SkData.h"
#include "core/SkImage.h"
#include "fmt/format.h"

#include <filesystem>
#include <string>

namespace canvas {
	class Image
	{
	public:
		static tl::expected<Image, std::string> try_from_file(std::filesystem::path file_path);
		Image(sk_sp<SkImage> image);
		~Image();
		sk_sp<SkImage> get_image() {
			return image;
		}
		tl::expected<SkV3, std::string> get_average_color() {
			SkBitmap bitmap;
			if (!image->asLegacyBitmap(&bitmap)) {
				return tl::make_unexpected("Unable to convert image to bitmap");
			}

			int width = bitmap.width();
			int height = bitmap.height();

			int totalR = 0;
			int totalG = 0;
			int totalB = 0;

			int visiblePixelCount = 0;
			for (int y = 0; y < height; y++) {
				for (int x = 0; x < width; x++) {
					SkColor pixelColor = bitmap.getColor(x, y);
					if (SkColorGetA(pixelColor) > 0) {
						totalR += SkColorGetR(pixelColor);
						totalG += SkColorGetG(pixelColor);
						totalB += SkColorGetB(pixelColor);
						++visiblePixelCount;
					}
				}
			}
			return SkV3{ totalR / visiblePixelCount * 1.0f, totalG / visiblePixelCount * 1.0f, totalB / visiblePixelCount * 1.0f };
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