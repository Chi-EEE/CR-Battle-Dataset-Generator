//#include <iostream>
//#include "tl/expected.hpp"
//#include "canvas/Canvas.h"
//#include "arena/Arena.h"
//
//using namespace canvas;
//using namespace arena;
//
//int main() {
//	auto arenaResult = Arena::create(ArenaType::Training_Camp, TowerSkin::Default, TowerSkin::Default);
//	if (arenaResult.has_value()) {
//		Arena arena = arenaResult.value();
//		auto result = arena.save("./testArena.png");
//		if (!result.has_value()) {
//			std::cerr << "An error has occurred while trying to save the arena: " << result.error() << '\n';
//		}
//	}
//	else {
//		std::cerr << "An error has occurred: " << arenaResult.error() << '\n';
//	}
//	return 0;
//}

#include <iostream>
#include "SupercellFlash.h"

using namespace std;
using namespace sc;

int main(int argc, char* argv[]) {
    if (argc != 1) {
        cout << "Failed to get filename";
    }

    SupercellSWF swf;

    try {
        swf.load(argv[0]);
    }
    catch (const std::exception& err) {
        cout << "Failed to load file. Error: " << err.what() << endl;
    }

    cout << "File has: " << endl;
    cout << swf.exports.size() << " export names" << endl;
    cout << swf.textures.size() << " textures" << endl;
    cout << swf.textFields.size() << " textfields" << endl;
    cout << swf.shapes.size() << " shapes" << endl;
    cout << swf.movieClips.size() << " movieclips" << endl;

    return 0;
}