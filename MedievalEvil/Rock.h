#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace MedievalEvil
{
	struct Game;

	struct Rock
	{
		Position2D position;
		sf::Sprite sprite;
	};

	void InitRock(Rock& rock, sf::Texture& texture);
	void SetRockPosition(Rock& rock, const Position2D& position);
	Rectangle GetRockCollider(const Rock& rock);
	void DrawRock(Rock&rock,sf::RenderWindow&window);

}

