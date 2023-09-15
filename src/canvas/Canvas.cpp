#include "Canvas.h"

namespace canvas {
	Canvas::Canvas(int width, int height)
	{
		this->surface = SkSurface::MakeRasterN32Premul(width, height);
	}

	Canvas Canvas::clone()
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas canvas = Canvas(width, width);
		Image snapshot = this->snapshot();
		canvas.draw_image(snapshot, SkRect::MakeLTRB(0, 0, width, height));
		return canvas;
	}

	Canvas::~Canvas()
	{
	}

	void Canvas::draw_canvas(Canvas canvas, SkRect dstRect)
	{
		surface->getCanvas()->drawImageRect(canvas.surface->makeImageSnapshot(), dstRect, SkSamplingOptions());
	}

	void Canvas::draw_image(Image &image, SkRect dstRect)
	{
		surface->getCanvas()->drawImageRect(image.get_image(), dstRect, SkSamplingOptions());
	}

	void Canvas::draw_text(std::string string, int x, int y)
	{
		SkFont defaultFont = SkFont(SkTypeface::MakeDefault());
		this->surface->getCanvas()->drawString(string.c_str(), x, y, defaultFont, SkPaint::SkPaint(SkColor4f::FromColor(SK_ColorBLACK)));
	}

	void Canvas::draw_rect(SkRect dstRect, SkPaint paint) {
		this->surface->getCanvas()->drawRect(dstRect, paint);
	}

	Canvas Canvas::crop(const SkRect& cropRect)
	{
		Canvas croppedCanvas = Canvas(cropRect.fRight - cropRect.fLeft, cropRect.fTop - cropRect.fBottom);
		Image snapshot = this->snapshot();
		croppedCanvas.draw_image(snapshot, cropRect);
		return croppedCanvas;
	}

	Canvas Canvas::stretch(const SkPoint& stretchVector)
	{
		Canvas stretchedCanvas = Canvas(stretchVector.fX, stretchVector.fY);
		Image snapshot = this->snapshot();
		stretchedCanvas.draw_image(snapshot, SkRect::MakeXYWH(0, 0, stretchVector.fX, stretchVector.fY));
		return stretchedCanvas;
	}

	Canvas Canvas::vertical_flip()
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas verticalFlippedCanvas = Canvas(width, height);
		SkCanvas* flippedCanvas = verticalFlippedCanvas.surface->getCanvas();

		flippedCanvas->translate(0, height);
		flippedCanvas->scale(1, -1);
		Image snapshot = this->snapshot();
		verticalFlippedCanvas.draw_image(snapshot, SkRect::MakeXYWH(0, 0, width, height));

		return verticalFlippedCanvas;
	}

	Canvas Canvas::horizonal_flip()
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas vertical_flipped_canvas = Canvas(width, height);
		SkCanvas* flipped_sk_canvas = vertical_flipped_canvas.surface->getCanvas();

		flipped_sk_canvas->translate(width, 0);
		flipped_sk_canvas->scale(-1, 1);
		Image snapshot = this->snapshot();
		vertical_flipped_canvas.draw_image(snapshot, SkRect::MakeXYWH(0, 0, width, height));

		return vertical_flipped_canvas;
	}

	Canvas Canvas::skew(SkScalar sx, SkScalar sy)
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas skewed_canvas = Canvas(width, height);
		SkCanvas* skewed_sk_canvas = skewed_canvas.surface->getCanvas();
		skewed_sk_canvas->skew(sx, sy);
		Image snapshot = this->snapshot();
		skewed_canvas.draw_image(snapshot, SkRect::MakeXYWH(width * ((sx / 3) * -1), 0, width, height));

		return skewed_canvas;
	}

	Image Canvas::replace_pixels_to() {
		auto image = this->surface->makeImageSnapshot();
		SkBitmap bitmap;
		SkImageInfo info = SkImageInfo::MakeN32Premul(image->width(), image->height());
		bitmap.allocPixels(info);

		SkCanvas canvas(bitmap);
		canvas.drawImage(image, 0, 0);

		// Modify the pixel values in the bitmap
		for (int y = 0; y < info.height(); y++) {
			for (int x = 0; x < info.width(); x++) {
				SkPMColor* pixel = bitmap.getAddr32(x, y);
				uint8_t alpha = SkColorGetA(*pixel);

				if (alpha > 0) {
					uint8_t newAlpha = std::max(alpha - 150, 0);
					*pixel = SkColorSetARGB(newAlpha, 0, 0, 0);  // Set to semi-transparent black
				}
			}
		}

		return SkImage::MakeFromBitmap(bitmap);
	}

	sk_sp<SkImage> Canvas::snapshot()
	{
		return this->surface->makeImageSnapshot();
	}

	void Canvas::clear()
	{
		surface->getCanvas()->clear(SK_ColorTRANSPARENT);
	}

	tl::expected<nullptr_t, std::string> Canvas::try_save(std::filesystem::path file_path)
	{
		sk_sp<SkImage> imageFromSurface(surface->makeImageSnapshot());
		if (!imageFromSurface) {
			return tl::make_unexpected("Failed to create image snapshot!");
		}

		sk_sp<SkData> imageEncoded = imageFromSurface->encodeToData();
		if (!imageEncoded) {
			return tl::make_unexpected("Failed to encode image to PNG!");
		}

		SkFILEWStream fileStream(file_path.string().c_str());
		if (!fileStream.isValid()) {
			return tl::make_unexpected("Failed to create output file!");
		}
		fileStream.write(imageEncoded->data(), imageEncoded->size());
		return nullptr;
	}
}