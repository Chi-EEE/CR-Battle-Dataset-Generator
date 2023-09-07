#include "Character.h"

namespace character {
	Character::Character()
	{
		this->orientation = static_cast<Orientation>(Random::get_instance().random_int_from_interval(0, 9));
	}

	Character::~Character()
	{

	}
}