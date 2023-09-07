#include "ImageLoader.h"

namespace canvas {
	ImageLoader::ImageLoader()
	{

	}

	tl::expected<Image, std::string> canvas::ImageLoader::try_load_image(std::filesystem::path file_path)
	{
		auto it = this->images.find(file_path);
		if (it != this->images.end())
			return it->second;
		std::string file_string = file_path.string();
		sk_sp<SkData> image_data = SkData::MakeFromFileName(file_string.c_str());
		if (!image_data) {
			return tl::make_unexpected(fmt::format("Failed to read image file! '{}'", file_string));
		}
		sk_sp<SkImage> image = SkImage::MakeFromEncoded(image_data);
		if (!image) {
			return tl::make_unexpected(fmt::format("Failed to create SkImage from encoded data! '{}'", file_string));
		}
		this->images.insert(std::make_pair(file_path, image));
		return image;
	}
}