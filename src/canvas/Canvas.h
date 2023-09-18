#ifndef CANVAS_H
#define CANVAS_H

#pragma once

#include <iostream>

#include "Image.h"

#include "tl/expected.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

namespace canvas {
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
		void draw_canvas(Canvas canvas, SkRect dstRect);
		void draw_image(Texture& image, SkRect dstRect);
		void draw_text(std::string string, int x, int y);
		void draw_rect(SkRect dst, SkPaint box);
		Canvas crop(const SkRect& cropRect);
		Canvas stretch(const SkPoint& stretchVector);
		Canvas vertical_flip();
		Canvas horizonal_flip();
		Canvas skew(SkScalar sx, SkScalar sy);
		Texture replace_pixels_to();
		sf::Texture snapshot();
		tl::expected<nullptr_t, std::string> try_save(std::filesystem::path file_path);
		void clear();

	private:
		sf::RenderWindow window;
	};
}

#endif