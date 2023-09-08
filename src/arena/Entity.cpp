#include "Entity.h"

using namespace canvas;

namespace arena {
	Entity::Entity(std::string name, std::filesystem::path file_path, int x, int y, bool is_air) : name(name), file_path(file_path), x(x), y(y), is_air(is_air)
	{

	}

	Entity::~Entity()
	{

	}
}