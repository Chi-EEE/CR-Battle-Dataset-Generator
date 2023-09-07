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
}