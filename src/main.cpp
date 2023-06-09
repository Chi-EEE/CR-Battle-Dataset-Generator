#include <iostream>
#include "Canvas.h"

#include "core/SkBitmap.h"
#include "core/SkCanvas.h"
#include "core/SkData.h"
#include "core/SkImage.h"
#include "core/SkRect.h"
#include "core/SkStream.h"
#include "core/SkSurface.h"
#include "core/SkTypes.h"

using namespace canvas;

int main() {
    Canvas* canvas = new Canvas(200, 200);
    SkRect dstRect = SkRect::MakeXYWH(50, 50, 200, 200); // Left, top, width, height
    auto imageResult = Image::create("./assets/arena/Bone.png");
    if (imageResult.has_value()) {
        auto image = imageResult.value();
        canvas->drawImage(image, dstRect);
        canvas->save("./tests.png");
    }
    return 0;
}
