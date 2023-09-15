#include "Image.h"
#include <iostream>
namespace canvas {
	tl::expected<Image, std::string> Image::try_from_file(std::filesystem::path file_path)
	{
		std::string file_string = file_path.string();
		sk_sp<SkData> image_data = SkData::MakeFromFileName(file_string.c_str());
		if (!image_data) {
			return tl::make_unexpected(fmt::format("Failed to read image file! [{}]", file_string));
		}
		sk_sp<SkImage> image = SkImage::MakeFromEncoded(image_data);
		if (!image) {
			return tl::make_unexpected(fmt::format("Failed to create SkImage from encoded data! [{}]", file_string));
		}
		return Image(image);
	}

	Image::Image(sk_sp<SkImage> image) : image(image)
	{
	}

	Image::~Image()
	{

	}
	tl::expected<SkV3, std::string> Image::get_average_color()
	{
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
}