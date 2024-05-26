#pragma once
#include "Constants.h"
#include <SFML/Graphics.hpp>

namespace MedievalEvil
{
	struct Border
	{
		sf::RectangleShape shape;
		sf::FloatRect floatrect;
	};

	void InitBorder(Border&border);
	void DrawBorder(Border& border, sf::RenderWindow& window);
}
