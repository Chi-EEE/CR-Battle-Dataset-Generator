#ifndef ANNOTATIONBOX_H
#define ANNOTATIONBOX_H

#pragma once

#include "core/SkRect.h"
#include "Drawable.h"

namespace canvas {
    // If the annotation box is not visible, then you would need to run a script to get rid of transparent area around the entity
    class AnnotationBox : public Drawable
    {
    public:
        AnnotationBox(std::string text, SkRect rect, SkColor color);
        ~AnnotationBox();
        void draw(Canvas& canvas) override;

    private:
        std::string text;
        SkRect rect;
        SkColor color;
    };
}

#endif