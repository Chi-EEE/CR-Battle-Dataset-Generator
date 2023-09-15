#include "Entity.h"

namespace arena {
	Entity::Entity(pEntityData entity_data, std::filesystem::path file_path) : entity_data(entity_data), file_path(file_path), texture(ImageLoader::get_instance().try_load_image(file_path).value())
	{
		float entity_width = this->texture.get_width() * 1.161616;
		float entity_height = this->texture.get_height() * 1.161616;

		this->size = { entity_width, entity_height };

		this->rect = SkRect::MakeXYWH(0, 0, this->size.x, this->size.y);
	}

	void Entity::addSpawnCharacter(std::shared_ptr<Entity> spawn_character)
	{
		this->spawn_character = spawn_character;
	}

	void Entity::setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->rect = SkRect::MakeXYWH(this->x - (this->size.x / 2), this->y - (this->size.y / 2), this->size.x, this->size.y);
	}

	void Entity::draw(Canvas& canvas)
	{
		canvas.draw_image(this->texture, rect);
	}

	// If the annotation box is not visible, then you would need to run a script to get rid of transparent area around the entity
	void Entity::draw_annotation_box(Canvas& canvas)
	{
		SkV3 average_color = EntityColorManager::getInstance().get_average_color(this->entity_data, this->texture);
		SkPaint box;
		box.setColor(SkColorSetARGB(255, average_color.x, average_color.y, average_color.z));
		box.setStyle(SkPaint::Style::kStroke_Style);
		box.setStrokeWidth(1.0f);
		canvas.draw_rect(this->rect, box);
		canvas.draw_text(this->entity_data->getName(), this->rect.fLeft, this->rect.fBottom);
	}

	void Entity::draw_shadow(Canvas& canvas)
	{
		Canvas entity_shadow_canvas = Canvas(this->size.x, this->size.y);
		entity_shadow_canvas.draw_image(this->texture, SkRect::MakeXYWH(0, 0, this->size.x, this->size.y));

		double new_height = std::floor(entity_shadow_canvas.get_height() * 0.71751412429378531073446327683616);
		entity_shadow_canvas = entity_shadow_canvas.stretch(SkPoint::Make(this->size.x, this->size.y));
		entity_shadow_canvas = entity_shadow_canvas.vertical_flip();
		entity_shadow_canvas = entity_shadow_canvas.skew(-this->entity_data->getShadowSkew() / 50.0f, 0);
		SkRect entity_shadow_rect = SkRect::MakeXYWH(
			this->rect.left() + this->entity_data->getShadowX(),
			this->rect.top() + this->size.y + this->entity_data->getShadowY(),
			entity_shadow_canvas.get_width() + this->entity_data->getShadowX(),
			entity_shadow_canvas.get_height() + this->entity_data->getShadowY()
		);

		canvas.draw_image(entity_shadow_canvas.replace_pixels_to(), entity_shadow_rect);
	}

	Entity::~Entity()
	{

	}
}