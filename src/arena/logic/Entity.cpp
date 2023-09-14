#include "Entity.h"

namespace arena {
	Entity::Entity(pEntityData entity_data, std::filesystem::path file_path) : entity_data(entity_data), file_path(file_path)
	{
		Image image = ImageLoader::get_instance().try_load_image(this->file_path).value();
		float entity_width = image.get_width() * 1.161616;
		float entity_height = image.get_height() * 1.161616;
		this->size = { entity_width, entity_height };
	}

	void Entity::addSpawnCharacter(std::shared_ptr<Entity> spawn_character)
	{
		this->spawn_character = spawn_character;
	}

	void Entity::setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Entity::draw_bounding_box(Canvas& canvas, SkColor& color, SkRect& entity_rect)
	{
		SkPaint boxPaint;
		boxPaint.setColor(SkColorSetARGB(0xFF, 0xFF, 0x00, 0x00));
		boxPaint.setStyle(SkPaint::Style::kStroke_Style);
		boxPaint.setStrokeWidth(2.0f);
		canvas.draw_rect(entity_rect, boxPaint);
	}

	Entity::~Entity()
	{

	}
}