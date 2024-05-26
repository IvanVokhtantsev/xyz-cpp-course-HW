#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace MedievalEvil
{
	struct Game;

	struct Background
	{
		sf::Sprite menu;
		sf::Sprite game;

	};

	void InitMenuBackground(Background& background, sf::Texture& texture);
	void DrawMenuBackground(Background& background, sf::RenderWindow& window);
	void InitGameBackground(Background& background, sf::Texture & texture);
	void DrawGameBackground(Background& background, sf::RenderWindow& window);
}
