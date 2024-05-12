#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace MedevilEvil
{
	struct Game;

	struct Background
	{
		sf::Sprite menu;
		sf::Sprite game;

	};

	void InitMenuBackground(Background& background, const Game& game);
	void DrawMenuBackground(Background& background, sf::RenderWindow& window);
	void InitGameBackground(Background& background, const Game& game);
	void DrawGameBackground(Background& background, sf::RenderWindow& window);
}
