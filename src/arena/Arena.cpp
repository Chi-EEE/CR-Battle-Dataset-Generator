#include "Arena.h"

namespace arena {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side(blue_side), red_side(red_side), canvas(canvas)
	{
	}

	tl::expected<Arena, std::string> Arena::create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side)
	{
		std::string arenaFile = fmt::format("./assets/arena/{}.png", arena_type.to_string());
		auto imageResult = Image::fromFile(arenaFile);
		if (!imageResult.has_value()) {
			return tl::make_unexpected(imageResult.error());
		}
		auto image = imageResult.value();
		Canvas canvas = Canvas(image.get_width(), image.get_height());
		canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width(), image.get_height()));
		return Arena(arena_type, blue_side, red_side, canvas);
	}

	Arena::~Arena()
	{

	}

	Arena Arena::clone()
	{
		return Arena(this->arena_type, blue_side, red_side, this->canvas.clone());
	}

	tl::expected<nullptr_t, std::string> Arena::save(std::string fileName)
	{
		auto blue_side = this->draw_blue_side();
		if (!blue_side.has_value()) return blue_side;
		return this->canvas.save(fileName);
	}

	tl::expected<Image, std::string> Arena::get_blue_princess_tower()
	{
		std::string arenaFile = fmt::format("./assets/towers/princess/Blue-{}.png", blue_side.to_string());
		auto imageResult = Image::fromFile(arenaFile);
		if (!imageResult.has_value()) {
			return tl::make_unexpected(imageResult.error());
		}
		auto image = imageResult.value();
		return image;
	}

	tl::expected<nullptr_t, std::string> Arena::draw_blue_side()
	{
		auto princess_tower_result = get_blue_princess_tower();
		if (!princess_tower_result.has_value()) return tl::make_unexpected(princess_tower_result.error());
		auto princess_tower_image = princess_tower_result.value();
		auto princess_tower_width = princess_tower_image.get_width() * 1.69;
		auto princess_tower_height = princess_tower_image.get_height() * 1.69;
		auto left_princess_tower_rect = SkRect::MakeXYWH(257 - (princess_tower_width / 2), 1182 - (princess_tower_height / 2), princess_tower_width, princess_tower_height);
		auto flipped_canvas = Canvas(princess_tower_width, princess_tower_height);
		flipped_canvas.draw_image(princess_tower_image, SkRect::MakeXYWH(0, 0, princess_tower_width, princess_tower_height));
		flipped_canvas = flipped_canvas.stretch(SkPoint::Make(flipped_canvas.get_width() * 0.43, flipped_canvas.get_height() * 0.43));
		flipped_canvas = flipped_canvas.vertical_flip();
		auto left_princess_shadow_rect = SkRect::MakeXYWH(left_princess_tower_rect.x() - 10, left_princess_tower_rect.y() + 50, left_princess_tower_rect.width(), left_princess_tower_rect.height());
		this->canvas.draw_image(flipped_canvas.replace_pixels_to(), left_princess_shadow_rect);
		this->canvas.draw_image(princess_tower_image, left_princess_tower_rect);
		return nullptr;
	}

	tl::expected<nullptr_t, std::string> Arena::draw_red_side()
	{
		std::string arenaFile = fmt::format("./assets/towers/princess/Red-{}.png", red_side.to_string());
		auto imageResult = Image::fromFile(arenaFile);
		if (!imageResult.has_value()) return tl::make_unexpected(imageResult.error());
		auto image = imageResult.value();
		this->canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width() * 1.69, image.get_height() * 1.69));
		return nullptr;
	}
}