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
	sk_sp<SkImage> getImage() {
		return image;
	}

private:
	Image(sk_sp<SkData> imageData, sk_sp<SkImage> image);
	sk_sp<SkData> imageData;
	sk_sp<SkImage> image;
};

#endif