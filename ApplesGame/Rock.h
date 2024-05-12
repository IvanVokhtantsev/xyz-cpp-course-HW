#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Math.h"

namespace MedevilEvil
{
	struct Game;

	struct Rock
	{
		Position2D position;
		sf::Sprite sprite;
	};

	void InitRock(Rock& rock, Game&game);
	void SetRockPosition(Rock& rock, const Position2D& position);
	Rectangle GetRockCollider(const Rock& rock);
	void DrawRock(Rock&rock,sf::RenderWindow&window);

}

