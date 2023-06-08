#ifndef IMAGE_H
#define IMAGE_H

#pragma once

#include "tl/expected.hpp"
#include "core/SkData.h"
#include "core/SkImage.h"
#include <string>

class Image
{
public:
    static tl::expected<Image, std::string> create();
    ~Image();

private:
    Image();

};

#endif