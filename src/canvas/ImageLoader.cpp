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

		auto image_result = Image::try_from_file(file_path);
		if (image_result.has_value()) {
			this->images.insert(std::make_pair(file_path, image_result.value()));
		}
		return image_result;
	}
}