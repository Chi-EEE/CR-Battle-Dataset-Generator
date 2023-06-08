#include "Image.h"

tl::expected<Image, std::string> Image::create()
{
	std::unique_ptr<sk_sp<SkData>> imageData = std::make_unique<sk_sp<SkData>>(SkData::MakeFromFileName("./assets/arena/Bone.png"));
	if (!imageData.get()) {
		return tl::make_unexpected("Failed to read image file!");
	}

	std::unique_ptr<sk_sp<SkImage>> image = std::make_unique<sk_sp<SkImage>>(SkImage::MakeFromEncoded(*imageData.get()));
	if (!image) {
		return tl::make_unexpected("Failed to create SkImage from encoded data!");
	}
	return Image();
}

Image::Image()
{
}

Image::~Image()
{

}