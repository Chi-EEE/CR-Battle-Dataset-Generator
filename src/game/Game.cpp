#include "Game.h"

namespace game {
	Game::Game()
	{

	}

	Game::~Game()
	{

	}

	sf::Texture Game::snapshot()
	{
		sf::Texture texture;
		texture.create(this->window.getSize().x, this->window.getSize().y);
		texture.update(this->window);
		return texture;
	}

	void Game::draw(Arena& arena)
	{
		this->window.draw(arena);
	}

	tl::expected<nullptr_t, std::string> Game::try_save(std::filesystem::path file_path)
	{
		sf::Texture texture = this->snapshot();
		if (!texture.copyToImage().saveToFile(file_path.string()))
		{
			return tl::make_unexpected("Failed to create output file!");
		}
		return nullptr;
	}

	void Game::clear()
	{
		this->window.clear();
	}

}