#include "Arena.h"

namespace arena {
	Arena::Arena(ArenaType arena_type, Canvas canvas) : arena_type(arena_type), canvas(canvas)
	{
	}

	tl::expected<Arena, std::string> Arena::create(ArenaType arena_type)
	{
		std::string arenaFile;
		switch (arena_type)
		{
		case Training:
			arenaFile = "./assets/arena/Training.png";
			break;
		default:
			break;
		}
		auto imageResult = Image::fromFile(arenaFile);
		if (!imageResult.has_value()) {
			return tl::make_unexpected(imageResult.error());
		}
		auto image = imageResult.value();
		Canvas canvas = Canvas(image.get_width(), image.get_height());
		canvas.draw_image(image, SkRect::MakeXYWH(0, 0, image.get_width(), image.get_height()));
		canvas.save("./tests.png");
		return Arena(arena_type, canvas);
	}

	Arena::~Arena()
	{

	}

	Arena Arena::clone()
	{
		return Arena(this->arena_type, this->canvas.clone());
	}
	tl::expected<nullptr_t, std::string> Arena::save(std::string fileName)
	{
		return this->canvas.save(fileName);
	}
}