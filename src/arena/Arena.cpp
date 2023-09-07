#include "Arena.h"

namespace arena {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Canvas canvas) : arena_type(arena_type), blue_side(blue_side), red_side(red_side), canvas(canvas)
	{
#pragma region Blue
		{
			auto result = try_get_arena_tower_path("princess", "blue", this->blue_side);
			if (!result.has_value()) throw std::exception(result.error().c_str());
			this->entities.push_back(Entity(result.value(), 171, 788, false));
		}
		{
			auto result = try_get_arena_tower_path("princess", "blue", this->blue_side);
			if (!result.has_value()) throw std::exception(result.error().c_str());
			this->entities.push_back(Entity(result.value(), 548, 788, false));
		}
		{
			auto result = try_get_arena_tower_path("king", "blue", this->blue_side);
			if (!result.has_value()) throw std::exception(result.error().c_str());
			this->entities.push_back(Entity(result.value(), 360, 875, false));
		}
#pragma endregion Initalize Blue Side
#pragma region Red
		{
			auto result = try_get_arena_tower_path("princess", "red", this->red_side);
			if (!result.has_value()) throw std::exception(result.error().c_str());
			this->entities.push_back(Entity(result.value(), 171, 262, false));
		}
		{
			auto result = try_get_arena_tower_path("princess", "red", this->red_side);
			if (!result.has_value()) throw std::exception(result.error().c_str());
			this->entities.push_back(Entity(result.value(), 548, 262, false));
		}
		{
			auto result = try_get_arena_tower_path("king", "red", this->red_side);
			if (!result.has_value()) throw std::exception(result.error().c_str());
			this->entities.push_back(Entity(result.value(), 360, 167, false));
		}
#pragma endregion Initalize Red Side
	}

	tl::expected<std::filesystem::path, std::string> Arena::try_get_arena_tower_path(std::string character, std::string team_side, TowerSkin tower_skin)
	{
		std::string blue_side_name = tower_skin.to_string();
		std::transform(blue_side_name.begin(), blue_side_name.end(), blue_side_name.begin(), ::tolower);
		std::filesystem::path asset_directory(Global::get_json()["assetDirectory"].get<std::string>());
		std::filesystem::path arena_tower_file = asset_directory / "essentials" / character / team_side / "tower" / blue_side_name / "01.png";
		if (!std::filesystem::exists(arena_tower_file)) return tl::make_unexpected(fmt::format("Unable to find the arena tower path containing: {}, {}, {}", character, team_side));
		return arena_tower_file;
	}

	tl::expected<Arena, std::string> Arena::try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side)
	{
		Random& random = Random::get_instance();
		ImageLoader& image_loader = ImageLoader::get_instance();
		std::string arena_type_name = arena_type.to_string();
		std::transform(arena_type_name.begin(), arena_type_name.end(), arena_type_name.begin(), ::tolower);
		std::filesystem::path assetDirectory(Global::get_json()["assetDirectory"].get<std::string>());

		std::string time = "default";
		if (random.random_int_from_interval(0, 1)) time = "overtime";

		auto arena_file_path_result = random.try_get_random_file_from_directory(assetDirectory / "arenas" / arena_type_name / time);
		if (!arena_file_path_result.has_value()) {
			return tl::make_unexpected(arena_file_path_result.error());
		}
		std::string arena_file_path = arena_file_path_result.value();

		auto image_result = image_loader.try_load_image(arena_file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		Canvas canvas = Canvas(image.get_width(), image.get_height());
		canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width(), image.get_height()));
		return Arena(arena_type, blue_side, red_side, canvas);
	}

	void Arena::draw()
	{
		std::sort(this->entities.begin(), this->entities.end(), [](const auto& e1, const auto& e2) -> bool {
			return e1.y < e2.y;
		});
		for (auto entity : this->entities) {
			auto result = try_draw_entity(entity);
			if (!result.has_value()) throw std::exception(result.error().c_str());
		}
	}

	Arena::~Arena()
	{

	}

	Arena Arena::clone()
	{
		return Arena(this->arena_type, blue_side, red_side, this->canvas.clone());
	}

	tl::expected<nullptr_t, std::string> Arena::try_save(std::string file_name)
	{
		return this->canvas.try_save(file_name);
	}

	tl::expected<Image, std::string> Arena::try_get_image(Entity entity)
	{
		ImageLoader& image_loader = ImageLoader::get_instance();
		auto image_result = image_loader.try_load_image(entity.file_path);
		if (!image_result.has_value()) {
			return tl::make_unexpected(image_result.error());
		}
		auto image = image_result.value();
		return image;
	}

	tl::expected<nullptr_t, std::string> Arena::try_draw_entity(Entity entity)
	{
		auto image_result = try_get_image(entity);
		if (!image_result.has_value()) return tl::make_unexpected(image_result.error());

		Image image = image_result.value();
		double entity_width = image.get_width() * 1.161616;
		double entity_height = image.get_height() * 1.161616;

		SkRect entity_rect = SkRect::MakeXYWH(entity.x - (entity_width / 2), entity.y - (entity_height / 2), entity_width, entity_height);

		Canvas entity_canvas = Canvas(entity_width, entity_height);
		entity_canvas.draw_image(image, SkRect::MakeXYWH(0, 0, entity_width, entity_height));

		double new_height = std::floor(entity_canvas.get_height() * 0.71751412429378531073446327683616);
		entity_canvas = entity_canvas.stretch(SkPoint::Make(entity_width, new_height));
		entity_canvas = entity_canvas.vertical_flip();
		entity_canvas = entity_canvas.skew(-0.25, 0);
		SkRect entity_shadow_rect = SkRect::MakeXYWH(entity_rect.x() - (entity_width / 7), entity_rect.y() + (entity_height / 2.75), entity_canvas.get_width(), entity_canvas.get_height());

		this->canvas.draw_image(entity_canvas.replace_pixels_to(), entity_shadow_rect);
		this->canvas.draw_image(image, entity_rect);
		return nullptr;
	}
}