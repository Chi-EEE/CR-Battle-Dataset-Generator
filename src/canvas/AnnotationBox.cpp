#include "AnnotationBox.h"

namespace canvas {
	AnnotationBox::AnnotationBox(std::string text, SkRect rect, SkColor color): text(text), rect(rect), color(color)
	{
		
	}

	AnnotationBox::~AnnotationBox()
	{

	}

	void AnnotationBox::draw(Canvas& canvas) const
	{
		SkPaint box;
		box.setColor(color);
		box.setStyle(SkPaint::Style::kStroke_Style);
		box.setStrokeWidth(1.0f);
		canvas.draw_rect(this->rect, box);
		canvas.draw_text(this->text, this->rect.fLeft, this->rect.fBottom);
	}
}