#include <iostream>
#include "tl/expected.hpp"
#include "canvas/Canvas.h"
#include "arena/Arena.h"

using namespace canvas;
using namespace arena;

int main() {
	auto arenaResult = Arena::create(ArenaType::Training_Camp, TowerSkin::Default, TowerSkin::Default);
	if (arenaResult.has_value()) {
		Arena arena = arenaResult.value();
		auto result = arena.save("./testArena.png");
		if (!result.has_value()) {
			std::cerr << "An error has occurred while trying to save the arena: " << result.error() << '\n';
		}
	}
	else {
		std::cerr << "An error has occurred: " << arenaResult.error() << '\n';
	}
	return 0;
}