#include "Border.h"
#include <SFML/Graphics/Rect.hpp>

namespace MedevilEvil
{
	void InitBorder(Border& border)
	{
		border.floatrect = { SCREEN_WIDTH * BORDER_OFFSET, SCREEN_HEIGHT * (BORDER_OFFSET + UI_BLOCK_OFFSET),
			SCREEN_WIDTH * (1.f - BORDER_OFFSET), SCREEN_HEIGHT * (1.f - BORDER_OFFSET) };
		border.shape.setPosition(border.floatrect.left, border.floatrect.top);
		border.shape.setSize(sf::Vector2f(border.floatrect.width-border.floatrect.left, 
										border.floatrect.height - border.floatrect.top));
		border.shape.setOutlineColor(sf::Color::Black);
		border.shape.setFillColor(sf::Color::Transparent);
		border.shape.setOutlineThickness(BORDER_THICKNESS);
		
	}

	void DrawBorder(Border& border, sf::RenderWindow& window)
	{
		window.draw(border.shape);
	}
	
}
