#ifndef CANVAS_H
#define CANVAS_H

#pragma once

#include <iostream>

#include "Drawable.h"

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
#include "core/SkTypeface.h"
#include "core/SkFont.h"

namespace canvas {
	class Drawable;

	class Canvas
	{
	public:
		Canvas(int width, int height);
		Canvas clone();
		~Canvas();
		int get_width() {
			return this->surface->width();
		}
		int get_height() {
			return this->surface->height();
		}
		void draw_canvas(Canvas canvas, SkRect dstRect, SkPaint* paint = nullptr);
		void draw_image(Image& image, SkRect dstRect, SkPaint* paint = nullptr);
		void draw_text(std::string string, int x, int y);
		void draw_rect(SkRect dst, SkPaint box);
		void draw(Drawable &drawable);
		Canvas crop(const SkRect& cropRect);
		Canvas stretch(const SkPoint& stretchVector);
		Canvas vertical_flip();
		Canvas horizonal_flip();
		Canvas skew(SkScalar sx, SkScalar sy);
		Image replace_pixels_to();
		sk_sp<SkImage> snapshot();
		tl::expected<nullptr_t, std::string> try_save(std::filesystem::path file_path);
		void clear();

	private:
		sk_sp<SkSurface> surface;
	};
}

#endif