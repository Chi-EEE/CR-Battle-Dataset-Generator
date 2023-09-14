#include "Entity.h"

using namespace canvas;

namespace arena {
	Entity::Entity(pEntityData entity_data, std::filesystem::path file_path) : entity_data(entity_data), file_path(file_path)
	{

	}

	void Entity::addSpawnCharacter(std::shared_ptr<Entity> spawn_character)
	{
		this->spawn_character = spawn_character;
	}

	void Entity::setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Entity::~Entity()
	{

	}
}