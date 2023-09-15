#include "Character.h"

namespace arena {
	Character::Character(pEntityData entity_data, std::filesystem::path file_path) : Entity(entity_data, file_path)
	{

	}

	tl::expected<Character, std::string> Character::create(pEntityData entity_data, std::filesystem::path file_path)
	{
		ImageLoader& image_loader = ImageLoader::get_instance();
		auto image_result = image_loader.try_load_image(file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		return Character(entity_data, file_path);
	}

	void Character::draw(Canvas& canvas)
	{
		Image image = ImageLoader::get_instance().try_load_image(this->file_path).value();
		SkRect entity_rect = SkRect::MakeXYWH(this->x - (size.x / 2), this->y - (size.y / 2), size.x, size.y);

		if (Global::get_json()["display_bounding_boxes"].get<bool>()) {
			SkV3 average_color = EntityColorManager::getInstance().get_average_color(this->entity_data, image);
			SkPaint box;
			box.setColor(SkColorSetARGB(255, average_color.x, average_color.y, average_color.z));
			box.setStyle(SkPaint::Style::kStroke_Style);
			box.setStrokeWidth(1.0f);
			canvas.draw_rect(SkRect::MakeXYWH(this->x, this->, this->size.x, this->size.y), box);
		}

#ifdef ENABLE_SHADOWS // Code is broken and I'll fix when working on shadows
		Canvas entity_shadow_canvas = Canvas(entity_width, entity_height);
		entity_shadow_canvas.draw_image(image, SkRect::MakeXYWH(0, 0, entity_width, entity_height));

		double new_height = std::floor(entity_shadow_canvas.get_height() * 0.71751412429378531073446327683616);
		entity_shadow_canvas = entity_shadow_canvas.stretch(SkPoint::Make(entity_width, new_height));
		entity_shadow_canvas = entity_shadow_canvas.vertical_flip();
		entity_shadow_canvas = entity_shadow_canvas.skew(-entity_data.getShadowSkew() / 50.0f, 0);
		SkRect entity_shadow_rect = SkRect::MakeXYWH(entity_rect.left() + entity_data.getShadowX(), entity_rect.top() + entity_height + entity_data.getShadowY(), entity_shadow_canvas.get_width() + entity_data.getShadowX(), entity_shadow_canvas.get_height() + entity_data.getShadowY());

		canvas.draw_image(entity_shadow_canvas.replace_pixels_to(), entity_shadow_rect);
#endif
		canvas.draw_image(image, entity_rect);
	}

	Character::~Character()
	{

	}
}