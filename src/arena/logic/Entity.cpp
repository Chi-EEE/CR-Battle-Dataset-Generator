#include "Entity.h"

using namespace canvas;

namespace arena {
	Entity::Entity(pEntityData entity_data, std::filesystem::path file_path, int x, int y, bool is_air) : entity_data(entity_data), file_path(file_path), x(x), y(y), is_air(is_air)
	{

	}

	Entity::~Entity()
	{

	}
}