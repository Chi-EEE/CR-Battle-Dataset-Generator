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
    // The first argument (argv[0]) is the program name
    // The following arguments (argv[1] onwards) are the file paths

    // Check if any file paths were provided
    if (argc > 1) {
        // Iterate over the file paths
        for (int i = 1; i < argc; ++i) {
            SupercellSWF swf;
            try {
                swf.load(argv[i]);
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
        }
    }
    else {
        std::cout << "No file paths provided." << std::endl;
    }

    return 0;
}