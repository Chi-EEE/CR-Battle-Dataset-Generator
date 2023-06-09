#include "Canvas.h"

namespace canvas {
	Canvas::Canvas(int width, int height)
	{
		surface = SkSurface::MakeRasterN32Premul(width, height);
		//canvas = std::make_unique<SkCanvas>(surface->getCanvas());
	}

	Canvas::~Canvas()
	{

	}

	void Canvas::drawImage(Image image, SkRect dstRect)
	{
		surface->getCanvas()->drawImageRect(image.getImage(), dstRect, SkSamplingOptions());
	}

	void Canvas::clear()
	{
		surface->getCanvas()->clear(SK_ColorTRANSPARENT);
	}

	tl::expected<nullptr_t, std::string> Canvas::save(std::string fileName)
	{
		sk_sp<SkImage> imageFromSurface(surface->makeImageSnapshot());
		if (!imageFromSurface) {
			return tl::make_unexpected("Failed to create image snapshot!");
		}

		sk_sp<SkData> imageEncoded = imageFromSurface->encodeToData();
		if (!imageEncoded) {
			return tl::make_unexpected("Failed to encode image to PNG!");
		}

		SkFILEWStream fileStream(fileName.c_str());
		if (!fileStream.isValid()) {
			return tl::make_unexpected("Failed to create output file!");
		}
		fileStream.write(imageEncoded->data(), imageEncoded->size());
		return nullptr;
	}
}