#include "Entity.h"

namespace arena::logic {
	tl::expected<Entity, std::string> Entity::create(pEntityData entity_data, Image image)
	{
		return Entity(entity_data, image);
	}

	Entity::Entity(pEntityData entity_data, Image image) : entity_data(entity_data), image(image)
	{
		float scale = (this->entity_data->getScale() / 100.0f);
		float entity_width = (this->image.get_width() * scale) * Global::scale;
		float entity_height = (this->image.get_height() * scale) * Global::scale;

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
		Canvas entity_canvas(this->size.x, this->size.y);
		entity_canvas.draw_image(this->image, SkRect{0, 0, this->size.x, this->size.y}, nullptr);

		SkPaint paint;
		paint.setBlendMode(SkBlendMode::kPlus);
		paint.setColor(SK_ColorRED);
		entity_canvas.draw_rect(SkRect{ 0, 0, this->size.x, this->size.y }, paint);

		SkPaint normal;
		normal.setBlendMode(SkBlendMode::kDstIn);
		entity_canvas.draw_image(this->image, SkRect{0, 0, this->size.x, this->size.y}, &normal);

		canvas.draw_canvas(entity_canvas, this->rect);
	}

	void Entity::draw_shadow(Canvas& canvas)
	{
		Canvas entity_shadow_canvas = Canvas(this->size.x, this->size.y);
		entity_shadow_canvas.draw_image(this->image, SkRect::MakeXYWH(0, 0, this->size.x, this->size.y), nullptr);

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

		canvas.draw_image(entity_shadow_canvas.replace_pixels_to(), entity_shadow_rect, nullptr);
	}

	Entity::~Entity()
	{

	}
}