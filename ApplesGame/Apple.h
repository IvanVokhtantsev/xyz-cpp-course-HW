#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace MedevilEvil
{
	struct Game;
	
	struct Apple
	{
		Position2D position;

		bool isAppleEaten = false;

		sf::Sprite sprite;
	};

	void InitApple(Apple& apple, Game&game);
	void SetApplePosition(Apple& apple, const Position2D& position);
	Circle GetAppleCollider(const Apple& apple);
	void DrawApple(Apple&apple, sf::RenderWindow& window);
}

