#include "Character.h"

namespace arena {
	Character::Character(pEntityData entity_data, std::filesystem::path file_path) : Entity(entity_data, file_path)
	{

	}

	tl::expected<Character, std::string> Character::create(pEntityData entity_data, std::filesystem::path file_path)
	{
		ImageLoader& image_loader = ImageLoader::get_instance();
		auto image_result = image_loader.try_load_image(file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		return Character(entity_data, file_path);
	}

	Character::~Character()
	{

	}
}