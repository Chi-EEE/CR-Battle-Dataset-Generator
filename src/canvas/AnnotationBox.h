#ifndef ANNOTATIONBOX_H
#define ANNOTATIONBOX_H

#pragma once

#include "core/SkRect.h"
#include "Drawable.h"

namespace canvas {
    class AnnotationBox : public Drawable
    {
    public:
        AnnotationBox(std::string text, SkRect rect, SkColor color);
        ~AnnotationBox();
        void draw(Canvas& canvas) const;

    private:
        std::string text;
        SkRect rect;
        SkColor color;
    };
}

#endif