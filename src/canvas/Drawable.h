#ifndef DRAWABLE_H
#define DRAWABLE_H

#pragma once

#include "Canvas.h"

namespace canvas {
	class Canvas;

	struct Drawable {
		virtual void draw(Canvas& canvas) = 0;
	};
}

#endif