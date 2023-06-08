#include "Image.h"

tl::expected<Image, std::string> Image::create()
{
	sk_sp<SkData> imageData = SkData::MakeFromFileName("./assets/arena/Bone.png");
	if (!imageData) {
		return tl::make_unexpected("Failed to read image file!");
	}

	sk_sp<SkImage> image = SkImage::MakeFromEncoded(imageData);
	if (!image) {
		return tl::make_unexpected("Failed to create SkImage from encoded data!");
	}
	return Image(imageData, image);
}

Image::Image(sk_sp<SkData> imageData, sk_sp<SkImage> image): imageData(imageData), image(image)
{
}

Image::~Image()
{

}