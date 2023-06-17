#include "../canvas/Image.h"
#ifndef BUILDING_H
#define BUILDING_H

#pragma once

using namespace canvas;

namespace arena {
    class Building
    {
    public:
        Building(Image image);
        ~Building();
        void draw();
    private:

    };
}
#endif