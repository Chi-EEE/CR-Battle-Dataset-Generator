#include <iostream>
#include "canvas/Canvas.h"
#include "arena/Arena.h"

using namespace canvas;
using namespace arena;

int main() {
    auto arenaResult = Arena::create(ArenaType::Training, TowerSkin::Default, TowerSkin::Default);
    if (arenaResult.has_value()) {
        Arena arena = arenaResult.value();
        arena.save("./testArena.png");
    }
    else {
        std::cerr << "An error has occurred: " << arenaResult.error() << '\n';
    }
    return 0;
}