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
		Texture snapshot = this->snapshot();
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

	void Canvas::draw_image(Texture& image, SkRect dstRect)
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

	/*Canvas Canvas::crop(const SkRect& cropRect)
	{
		Canvas croppedCanvas = Canvas(cropRect.fRight - cropRect.fLeft, cropRect.fTop - cropRect.fBottom);
		Texture snapshot = this->snapshot();
		croppedCanvas.draw_image(snapshot, cropRect);
		return croppedCanvas;
	}

	Canvas Canvas::stretch(const SkPoint& stretchVector)
	{
		Canvas stretchedCanvas = Canvas(stretchVector.fX, stretchVector.fY);
		Texture snapshot = this->snapshot();
		stretchedCanvas.draw_image(snapshot, SkRect::MakeXYWH(0, 0, stretchVector.fX, stretchVector.fY));
		return stretchedCanvas;
	}*/

	/*Canvas Canvas::vertical_flip()
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas verticalFlippedCanvas = Canvas(width, height);
		SkCanvas* flippedCanvas = verticalFlippedCanvas.surface->getCanvas();

		flippedCanvas->translate(0, height);
		flippedCanvas->scale(1, -1);
		Texture snapshot = this->snapshot();
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
		Texture snapshot = this->snapshot();
		vertical_flipped_canvas.draw_image(snapshot, SkRect::MakeXYWH(0, 0, width, height));

		return vertical_flipped_canvas;
	}*/

	/*Canvas Canvas::skew(SkScalar sx, SkScalar sy)
	{
		int width = this->get_width();
		int height = this->get_height();
		Canvas skewed_canvas = Canvas(width, height);
		SkCanvas* skewed_sk_canvas = skewed_canvas.surface->getCanvas();
		skewed_sk_canvas->skew(sx, sy);
		Texture snapshot = this->snapshot();
		skewed_canvas.draw_image(snapshot, SkRect::MakeXYWH(width * ((sx / 3) * -1), 0, width, height));

		return skewed_canvas;
	}*/

	Texture Canvas::replace_pixels_to() {
		sf::Texture texture = this->snapshot();
		sf::Image image = texture.copyToImage();

		sf::Vector2u size = texture.getSize();

		auto width = size.x;
		auto height = size.y;

		// Modify the pixel values in the bitmap
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				sf::Color pixel_color = image.getPixel(x, y);
				if (pixel_color.a > 0) {
					image.setPixel(x, y, sf::Color{ 0,0,0,std::max(pixel_color.a - 150, 0) });
				}
			}
		}
		texture.update(image);
		return texture;
	}

	sf::Texture Canvas::snapshot()
	{
		sf::Texture texture;
		texture.create(this->window.getSize().x, this->window.getSize().y);
		texture.update(this->window);
		return texture;
	}

	void Canvas::clear()
	{
		this->window.clear();
	}

	tl::expected<nullptr_t, std::string> Canvas::try_save(std::filesystem::path file_path)
	{
		sf::Texture texture = this->snapshot();
		if (!texture.copyToImage().saveToFile(file_path.string()))
		{
			return tl::make_unexpected("Failed to create output file!");
		}
		return nullptr;
	}
}