#ifndef CANVAS_H
#define CANVAS_H

#pragma once

#include <iostream>

#include "Image.h"

#include "tl/expected.hpp"

#include "core/SkBitmap.h"
#include "core/SkCanvas.h"
#include "core/SkData.h"
#include "core/SkImage.h"
#include "core/SkRect.h"
#include "core/SkStream.h"
#include "core/SkSurface.h"
#include "core/SkTypes.h"

class Canvas
{
public:
	Canvas(int width, int height);
	~Canvas();
	void drawImage(Image image, SkRect dstRect);

private:
	void clear();
	tl::expected<void, std::string> save(std::string fileName);

	sk_sp<SkSurface> surface;
	std::unique_ptr<SkCanvas> canvas;
};

#endif