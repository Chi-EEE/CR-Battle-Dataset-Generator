#include "Image.h"

namespace canvas {
	tl::expected<Image, std::string> Image::fromFile(std::string fileName)
	{
		sk_sp<SkData> imageData = SkData::MakeFromFileName(fileName.c_str());
		if (!imageData) {
			return tl::make_unexpected(fmt::format("Failed to read image file! [{}]", fileName));
		}
		sk_sp<SkImage> image = SkImage::MakeFromEncoded(imageData);
		if (!image) {
			return tl::make_unexpected(fmt::format("Failed to create SkImage from encoded data! [{}]", fileName));
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