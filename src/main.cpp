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

int main() {
    Canvas canvas = Canvas(200, 200);

    /*sk_sp<SkSurface> surface(SkSurface::MakeRasterN32Premul(200, 200));
    SkCanvas* canvas = surface->getCanvas();*/

    SkRect dstRect = SkRect::MakeXYWH(50, 50, 200, 200); // Left, top, width, height


    return 0;
}
