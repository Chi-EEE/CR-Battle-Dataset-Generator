#include "Character.h"
using namespace CSV::Logic;

namespace arena {
	Character::Character(std::string name, std::filesystem::path file_path, int x, int y, bool is_air) : Entity(name, file_path, x, y, is_air)
	{

	}

	tl::expected<Character, std::string> Character::create(std::string name, std::filesystem::path file_path, int x, int y, bool is_air)
	{
		ImageLoader& image_loader = ImageLoader::get_instance();
		auto image_result = image_loader.try_load_image(file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		return Character(name, file_path, x, y, is_air);
	}

	void Character::draw(Canvas& canvas)
	{
		CSV::AbstractTable* entity_data_table = CSV::CSV::getInstance().getTable(CSV::File::Entity);

		std::vector<EntityData> entity_data_entries = static_cast<CSV::Table<EntityData>*>(entity_data_table)->getEntries();

		std::optional<EntityData> maybe_entity_data = std::nullopt;
		for (auto entity_data : entity_data_entries)
		{
			if (entity_data.getName() == this->name) {
				maybe_entity_data = std::make_optional<EntityData>(entity_data);
			}
		}
		auto entity_data = maybe_entity_data.value();

		Image image = ImageLoader::get_instance().try_load_image(this->file_path).value();

		double entity_width = image.get_width() * 1.161616;
		double entity_height = image.get_height() * 1.161616;

		SkRect entity_rect = SkRect::MakeXYWH(this->x - (entity_width / 2), this->y - (entity_height / 2), entity_width, entity_height);

		Canvas entity_canvas = Canvas(entity_width, entity_height);
		entity_canvas.draw_image(image, SkRect::MakeXYWH(0, 0, entity_width, entity_height));

		double new_height = std::floor(entity_canvas.get_height() * 0.71751412429378531073446327683616);
		entity_canvas = entity_canvas.stretch(SkPoint::Make(entity_width, new_height));
		entity_canvas = entity_canvas.vertical_flip();
		entity_canvas = entity_canvas.skew(-entity_data.getShadowSkew() / 100, 0);
		SkRect entity_shadow_rect = SkRect::MakeXYWH(entity_rect.x() - (entity_width / 7), entity_rect.y() + (entity_height / 2.75), entity_canvas.get_width(), entity_canvas.get_height());

		canvas.draw_image(entity_canvas.replace_pixels_to(), entity_shadow_rect);
		canvas.draw_image(image, entity_rect);
	}

	Character::~Character()
	{

	}
}