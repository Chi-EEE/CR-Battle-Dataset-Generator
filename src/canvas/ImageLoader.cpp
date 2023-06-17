#include "ImageLoader.h"

namespace canvas {
	ImageLoader::ImageLoader()
	{

	}

	tl::expected<Image, std::string> canvas::ImageLoader::load_image(std::string file_name)
	{
		auto it = this->images.find(file_name);
		if (it != this->images.end())
			return it->second;

		auto image_result = Image::fromFile(file_name);
		if (image_result.has_value()) {
			this->images.insert(std::make_pair(file_name, image_result.value()));
		}
		return image_result;
	}
}