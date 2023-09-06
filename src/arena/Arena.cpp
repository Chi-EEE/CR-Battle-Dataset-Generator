#include "Arena.h"

namespace arena {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side(blue_side), red_side(red_side), canvas(canvas)
	{
	}

	tl::expected<Arena, std::string> Arena::create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side)
	{
		ImageLoader& image_loader = ImageLoader::getInstance();
		std::string arena_type_name = arena_type.to_string();
		std::transform(arena_type_name.begin(), arena_type_name.end(), arena_type_name.begin(), ::tolower);
		std::filesystem::path assetDirectory(Global::getJson()["assetDirectory"].get<std::string>());

		std::string time = "default";
		if (Random::getInstance().randomIntFromInterval(0, 1)) time = "overtime";

		std::string path;

		size_t n = 1;
		std::default_random_engine generator(std::random_device{}());
		std::uniform_real_distribution<double> distribution(0.0, 1.0);

		for (const auto& entry : std::filesystem::directory_iterator(assetDirectory / "arenas" / arena_type_name / time)) {
			if (!entry.is_directory()) {
				if (distribution(generator) < 1.0 / n) {
					path = entry.path().string();
				}
				n++;
			}
		}


		auto image_result = image_loader.load_image(path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
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
		ImageLoader& image_loader = ImageLoader::getInstance();
		std::string arenaFile = fmt::format("./assets/towers/princess/Blue-{}.png", this->blue_side.to_string());
		auto imageResult = image_loader.load_image(arenaFile);
		if (!imageResult.has_value()) {
			return tl::make_unexpected(imageResult.error());
		}
		auto image = imageResult.value();
		return image;
	}

	tl::expected<Image, std::string> Arena::get_blue_king_tower()
	{
		ImageLoader& image_loader = ImageLoader::getInstance();
		std::string arenaFile = fmt::format("./assets/towers/king/Blue-{}.png", this->blue_side.to_string());
		auto imageResult = image_loader.load_image(arenaFile);
		if (!imageResult.has_value()) {
			return tl::make_unexpected(imageResult.error());
		}
		auto image = imageResult.value();
		return image;
	}

	tl::expected<nullptr_t, std::string> Arena::draw_blue_side()
	{
		draw_blue_princess_tower(257, 1182);
		draw_blue_princess_tower(823, 1182);
		draw_blue_king_tower(540, 1322);
		return nullptr;
	}

	tl::expected<nullptr_t, std::string> Arena::draw_blue_king_tower(int x, int y)
	{
		auto princess_tower_result = get_blue_king_tower();
		if (!princess_tower_result.has_value()) return tl::make_unexpected(princess_tower_result.error());
		Image princess_tower_image = princess_tower_result.value();
		double princess_tower_width = princess_tower_image.get_width() * 1.71;
		double princess_tower_height = princess_tower_image.get_height() * 1.71;
		SkRect left_princess_tower_rect = SkRect::MakeXYWH(x - (princess_tower_width / 2), y - (princess_tower_height / 2), princess_tower_width, princess_tower_height);
		Canvas shadow_princess_tower_canvas = Canvas(princess_tower_width, princess_tower_height);
		shadow_princess_tower_canvas.draw_image(princess_tower_image, SkRect::MakeXYWH(0, 0, princess_tower_width, princess_tower_height));
		double new_height = std::floor(shadow_princess_tower_canvas.get_height() * 0.71751412429378531073446327683616);
		shadow_princess_tower_canvas = shadow_princess_tower_canvas.stretch(SkPoint::Make(princess_tower_width, new_height));
		shadow_princess_tower_canvas = shadow_princess_tower_canvas.vertical_flip();
		shadow_princess_tower_canvas = shadow_princess_tower_canvas.skew(-0.25, 0);
		SkRect left_princess_shadow_rect = SkRect::MakeXYWH(left_princess_tower_rect.x() - 15, left_princess_tower_rect.y() + 70, shadow_princess_tower_canvas.get_width(), shadow_princess_tower_canvas.get_height());
		this->canvas.draw_image(shadow_princess_tower_canvas.replace_pixels_to(), left_princess_shadow_rect);
		this->canvas.draw_image(princess_tower_image, left_princess_tower_rect);
		return nullptr;
	}

	tl::expected<nullptr_t, std::string> Arena::draw_blue_princess_tower(int x, int y)
	{
		auto princess_tower_result = get_blue_princess_tower();
		if (!princess_tower_result.has_value()) return tl::make_unexpected(princess_tower_result.error());
		Image princess_tower_image = princess_tower_result.value();
		double princess_tower_width = princess_tower_image.get_width() * 1.69;
		double princess_tower_height = princess_tower_image.get_height() * 1.69;
		SkRect left_princess_tower_rect = SkRect::MakeXYWH(x - (princess_tower_width / 2), y - (princess_tower_height / 2), princess_tower_width, princess_tower_height);
		Canvas shadow_princess_tower_canvas = Canvas(princess_tower_width, princess_tower_height);
		shadow_princess_tower_canvas.draw_image(princess_tower_image, SkRect::MakeXYWH(0, 0, princess_tower_width, princess_tower_height));
		double new_height = std::floor(shadow_princess_tower_canvas.get_height() * 0.71751412429378531073446327683616);
		shadow_princess_tower_canvas = shadow_princess_tower_canvas.stretch(SkPoint::Make(princess_tower_width, new_height));
		shadow_princess_tower_canvas = shadow_princess_tower_canvas.vertical_flip();
		shadow_princess_tower_canvas = shadow_princess_tower_canvas.skew(-0.25, 0);
		SkRect left_princess_shadow_rect = SkRect::MakeXYWH(left_princess_tower_rect.x() - 15, left_princess_tower_rect.y() + 70, shadow_princess_tower_canvas.get_width(), shadow_princess_tower_canvas.get_height());
		this->canvas.draw_image(shadow_princess_tower_canvas.replace_pixels_to(), left_princess_shadow_rect);
		this->canvas.draw_image(princess_tower_image, left_princess_tower_rect);
		return nullptr;
	}

	tl::expected<nullptr_t, std::string> Arena::draw_red_side()
	{
		ImageLoader& image_loader = ImageLoader::getInstance();
		std::string arenaFile = fmt::format("./assets/towers/princess/Red-{}.png", red_side.to_string());
		auto imageResult = image_loader.load_image(arenaFile);
		if (!imageResult.has_value()) return tl::make_unexpected(imageResult.error());
		auto image = imageResult.value();
		this->canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width() * 1.69, image.get_height() * 1.69));
		return nullptr;
	}
}