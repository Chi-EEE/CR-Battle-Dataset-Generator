#include "ImageLoader.h"
#include <iostream>
namespace canvas {
	ImageLoader::ImageLoader() : images(Global::getSettings()["image_cache_size"].get<int>())
	{
	}

	// There is not a memory leak here since the images are being loaded here!
	tl::expected<Image, std::string> canvas::ImageLoader::try_load_image(std::filesystem::path file_path)
	{
		std::lock_guard<std::mutex> lock(mtx);
		if (this->images.exist(file_path))
			return this->images.get(file_path);
		std::string file_string = file_path.string();
		sk_sp<SkData> image_data = SkData::MakeFromFileName(file_string.c_str());
		if (!image_data) {
			return tl::make_unexpected(fmt::format("Failed to read image file! '{}'", file_string));
		}
		sk_sp<SkImage> image = SkImage::MakeFromEncoded(image_data);
		if (!image) {
			return tl::make_unexpected(fmt::format("Failed to create SkImage from encoded data! '{}'", file_string));
		}
		this->images.put(file_path, image);
		return image;
	}
}