#include "Building.h"

namespace arena {
	Building::Building(pEntityData entity_data, std::filesystem::path file_path): Entity(entity_data, file_path)
	{
	}

	tl::expected<Building, std::string> Building::create(pEntityData entity_data, std::filesystem::path file_path)
	{
		ImageLoader& image_loader = ImageLoader::get_instance();
		auto image_result = image_loader.try_load_image(file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		return Building(entity_data, file_path);
	}

	void Building::draw(Canvas& canvas)
	{
		Image image = ImageLoader::get_instance().try_load_image(this->file_path).value();
		SkRect entity_rect = SkRect::MakeXYWH(this->x - (size.x / 2), this->y - (size.y / 2), size.x, size.y);
#ifdef ENABLE_SHADOWS
		Canvas entity_shadow_canvas = Canvas(entity_width, entity_height);
		entity_shadow_canvas.draw_image(image, SkRect::MakeXYWH(0, 0, entity_width, entity_height));

		double new_height = std::floor(entity_shadow_canvas.get_height() * 0.71751412429378531073446327683616);
		entity_shadow_canvas = entity_shadow_canvas.stretch(SkPoint::Make(entity_width, new_height));
		entity_shadow_canvas = entity_shadow_canvas.vertical_flip();
		entity_shadow_canvas = entity_shadow_canvas.skew(-0.25, 0);
		SkRect entity_shadow_rect = SkRect::MakeXYWH(entity_rect.x() - (entity_width / 7), entity_rect.y() + (entity_height / 2.75), entity_shadow_canvas.get_width(), entity_shadow_canvas.get_height());

		canvas.draw_image(entity_shadow_canvas.replace_pixels_to(), entity_shadow_rect);
#endif
		canvas.draw_image(image, entity_rect);
	}

	Building::~Building()
	{

	}
}