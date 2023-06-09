#include "Canvas.h"

namespace canvas {
	Canvas::Canvas(int width, int height)
	{
		this->surface = SkSurface::MakeRasterN32Premul(width, height);
		//canvas = std::make_unique<SkCanvas>(surface->getCanvas());
	}

	Canvas Canvas::clone()
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas canvas = Canvas(width, width);
		canvas.draw_image(this->snapshot(), SkRect::MakeLTRB(0, 0, width, height));
		return canvas;
	}

	Canvas::~Canvas()
	{
	}

	void Canvas::draw_image(Image image, SkRect dstRect)
	{
		surface->getCanvas()->drawImageRect(image.getImage(), dstRect, SkSamplingOptions());
	}

	Canvas Canvas::crop(const SkRect& cropRect)
	{
		Canvas croppedCanvas = Canvas(cropRect.fRight - cropRect.fLeft, cropRect.fTop - cropRect.fBottom);
		croppedCanvas.draw_image(this->surface->makeImageSnapshot(), cropRect);
		return croppedCanvas;
	}

	Canvas Canvas::stretch(const SkPoint& stretchVector)
	{
		Canvas stretchedCanvas = Canvas(stretchVector.fX, stretchVector.fY);
		stretchedCanvas.draw_image(this->surface->makeImageSnapshot(), SkRect::MakeXYWH(0, 0, stretchVector.fX, stretchVector.fY));
		return stretchedCanvas;
	}

	sk_sp<SkImage> Canvas::snapshot()
	{
		return this->surface->makeImageSnapshot();
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