#include "Character.h"

namespace character {
	Character::Character()
	{
		this->orientation = static_cast<Orientation>(Random::getInstance().randomIntFromInterval(0, 9));
	}

	Character::~Character()
	{

	}
}