#include "Arena.h"

using namespace arena::data;
using namespace csv;

namespace arena::logic {
	Arena::Arena(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side, Texture texture) : arena_type(arena_type), blue_side_tower_skin(blue_side), red_side_tower_skin(red_side), texture(texture)
	{
		auto& entity_data_indexer = EntityDataManager::getInstance();

		auto princess_tower = entity_data_indexer.getEntityDataByName("PrincessTower");
		auto king_tower = entity_data_indexer.getEntityDataByName("KingTower");

		add_arena_tower(princess_tower, "princess", "blue", this->blue_side_tower_skin, 171, 788);
		add_arena_tower(princess_tower, "princess", "blue", this->blue_side_tower_skin, 548, 788);
		add_arena_tower(king_tower, "king", "blue", this->blue_side_tower_skin, 360, 875);

		add_arena_tower(princess_tower, "princess", "red", this->red_side_tower_skin, 171, 262);
		add_arena_tower(princess_tower, "princess", "red", this->red_side_tower_skin, 548, 262);
		add_arena_tower(king_tower, "king", "red", this->red_side_tower_skin, 360, 167);
	}

	void Arena::add_arena_tower(pEntityData entity_data, std::string character, std::string team_side, TowerSkin tower_skin, int x, int y)
	{
		auto result = try_get_arena_tower_texture(character, team_side, tower_skin);
		if (!result.has_value()) throw std::exception(result.error().c_str());
		auto building_instance_result = Entity::create(entity_data, result.value());
		if (!building_instance_result.has_value()) throw std::exception(building_instance_result.error().c_str());
		pEntity building = std::make_shared<Entity>(building_instance_result.value());
		building->setPosition(x, y);
		this->ground_entities.push_back(building);
	}

	tl::expected<Texture, std::string> Arena::try_get_arena_tower_texture(std::string character, std::string team_side, TowerSkin tower_skin)
	{
		std::string blue_side_name = tower_skin.to_string();
		std::transform(blue_side_name.begin(), blue_side_name.end(), blue_side_name.begin(), ::tolower);
		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());
		std::filesystem::path arena_tower_file_path = asset_directory / "essentials" / character / team_side / "tower" / blue_side_name / "01.png";
		if (!std::filesystem::exists(arena_tower_file_path)) return tl::make_unexpected(fmt::format("Unable to find the arena tower path containing: {}, {}, {}", character, team_side));
		auto maybe_texture = TextureLoader::get_instance().try_load_image(arena_tower_file_path);
		return maybe_texture;
	}

	tl::expected<Arena, std::string> Arena::try_create(ArenaType arena_type, TowerSkin blue_side, TowerSkin red_side)
	{
		Random& random = Random::get_instance();
		TextureLoader& texture_loader = TextureLoader::get_instance();
		std::string arena_type_name = arena_type.to_string();
		std::transform(arena_type_name.begin(), arena_type_name.end(), arena_type_name.begin(), ::tolower);

		std::filesystem::path asset_directory(Global::get_json()["asset_directory"].get<std::string>());

		std::string time = "default";
		if (random.random_int_from_interval(0, 1)) time = "overtime";

		auto arena_file_path_result = random.try_get_random_file_from_directory(asset_directory / "arenas" / arena_type_name / time);
		if (!arena_file_path_result.has_value()) {
			return tl::make_unexpected(arena_file_path_result.error());
		}
		std::filesystem::path arena_file_path = arena_file_path_result.value();

		auto texture_result = texture_loader.try_load_image(arena_file_path);
		if (!texture_result.has_value()) {
			return tl::make_unexpected(texture_result.error());
		}
		auto texture = texture_result.value();

		return Arena(arena_type, blue_side, red_side, texture);
	}

	bool Arena::try_add_entity(pEntity entity)
	{
		for (auto entity : this->ground_entities) {
			double distance = sqrt(pow(entity->x - entity->x, 2) + pow(entity->y - entity->y, 2)) * 32;
			bool inside_bounds = distance <= (entity->entity_data->getCollisionRadius() * Global::scale) + (entity->entity_data->getCollisionRadius() * Global::scale);
			spdlog::debug("CurrentName:{}|Name:{}|Distance:{}|Inside_Bounds:{}", entity->entity_data->getName(), entity->entity_data->getName(), distance, inside_bounds);
			if (inside_bounds)
				return false;
		}
		for (auto entity : this->air_entities) {
			double distance = sqrt(pow(entity->x - entity->x, 2) + pow(entity->y - entity->y, 2)) * 32;
			bool inside_bounds = distance <= (entity->entity_data->getCollisionRadius() * 4 * Global::scale) + (entity->entity_data->getCollisionRadius() * Global::scale);
			spdlog::debug("CurrentName:{}|Name:{}|Distance:{}|Inside_Bounds:{}", entity->entity_data->getName(), entity->entity_data->getName(), distance, inside_bounds);
			if (inside_bounds)
				return false;
		}
		if (entity->entity_data->getFlyingHeight()) {
			this->air_entities.push_back(entity);
		}
		else {
			this->ground_entities.push_back(entity);
		}
		return true;
	}

	Arena::~Arena()
	{

	}

	Arena Arena::clone()
	{
		return Arena(this->arena_type, this->blue_side_tower_skin, this->red_side_tower_skin, this->texture);
	}
	void Arena::before_draw() {
		std::sort(this->ground_entities.begin(), this->ground_entities.end(), [](const pEntity& entity_1, const pEntity& entity_2) -> bool
			{
				return entity_1->y < entity_2->y;
			}
		);
		std::sort(this->air_entities.begin(), this->air_entities.end(), [](const pEntity& entity_1, const pEntity& entity_2) -> bool
			{
				return entity_1->y < entity_2->y;
			}
		);
	}
	void Arena::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (auto& entity : this->ground_entities) {
			target.draw(*entity, states);
		}
		for (auto& entity : this->air_entities) {
			target.draw(*entity, states);
		}
		if (Global::get_json()["display_bounding_boxes"].get<bool>()) {
			for (auto& entity : this->ground_entities) {
				AnnotationBox annotation_box{ entity->entity_data->getName(), entity->rect };
				target.draw(annotation_box, states);
			}
			for (auto& entity : this->air_entities) {
				AnnotationBox annotation_box{ entity->entity_data->getName(), entity->rect };
				target.draw(annotation_box, states);
			}
		}
	}
}