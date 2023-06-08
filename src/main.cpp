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
    sk_sp<SkData> imageData = SkData::MakeFromFileName("./assets/arena/Bone.png");
    if (!imageData) {
        std::cout << "Failed to read image file!" << std::endl;
        return -1;
    }

    sk_sp<SkImage> image = SkImage::MakeFromEncoded(imageData);
    if (!image) {
        std::cout << "Failed to create SkImage from encoded data!" << std::endl;
        return -1;
    }

    /*sk_sp<SkSurface> surface(SkSurface::MakeRasterN32Premul(200, 200));
    SkCanvas* canvas = surface->getCanvas();*/

    SkRect dstRect = SkRect::MakeXYWH(50, 50, 200, 200); // Left, top, width, height

    canvas->clear(SK_ColorTRANSPARENT);
    canvas->drawImageRect(image, dstRect, SkSamplingOptions());

    sk_sp<SkImage> imageFromSurface(surface->makeImageSnapshot());
    if (!imageFromSurface) {
        std::cout << "Failed to create image snapshot!" << std::endl;
        return -1;
    }

    sk_sp<SkData> imageEncoded = imageFromSurface->encodeToData();
    if (!imageEncoded) {
        std::cout << "Failed to encode image to PNG!" << std::endl;
        return -1;
    }

    SkFILEWStream fileStream("./test.png");
    if (!fileStream.isValid()) {
        std::cout << "Failed to create output file!" << std::endl;
        return -1;
    }

    fileStream.write(imageEncoded->data(), imageEncoded->size());

    std::cout << "Image saved successfully!" << std::endl;

    return 0;
}
