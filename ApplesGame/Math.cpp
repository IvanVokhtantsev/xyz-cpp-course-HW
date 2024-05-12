#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Border.h"
#include "Math.h"

namespace MedevilEvil
{
	Position2D GetRandomPositionInRectangle(Border&border,const float size)
	{
		Position2D result;
		result.x = border.floatrect.left+ size/2+rand() / (float)RAND_MAX *(border.floatrect.width - border.floatrect.left-size);
		result.y = border.floatrect.top+ size/2+rand() / (float)RAND_MAX * (border.floatrect.height- border.floatrect.top-size);
		return result;
	}

	char GetRandomChar()
	{
		return (char) (33+rand()%(126-33+1));
	}

	bool DoShapesCollide(const Rectangle& rect1, const Rectangle& rect2)
	{
		return rect1.position.x < rect2.position.x + rect2.size.x &&
			rect1.position.x + rect1.size.x > rect2.position.x &&
			rect1.position.y < rect2.position.y + rect2.size.y &&
			rect1.position.y + rect1.size.y > rect2.position.y;
	}

	bool DoShapesCollide(const Circle& circle1, const Circle& circle2)
	{
		float dx = circle1.position.x - circle2.position.x;
		float dy = circle1.position.y - circle2.position.y;
		float distance = sqrt(dx * dx + dy * dy);
		return distance < circle1.radius + circle2.radius;
	}

	bool DoShapesCollide(const Rectangle& rect, const Circle& circle)
	{
		float dx = circle.position.x - std::max(rect.position.x, std::min(circle.position.x, rect.position.x + rect.size.x));
		float dy = circle.position.y - std::max(rect.position.y, std::min(circle.position.y, rect.position.y + rect.size.y));
		return (dx * dx + dy * dy) < (circle.radius * circle.radius);
	}

	void SetSpriteSize(sf::Sprite& sprite, const float desiredWidth, const float desiredHeight)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sf::Vector2f scale = { desiredWidth / spriteRect.width, desiredHeight / spriteRect.height };
		sprite.setScale(scale);
	}
	
	void SetRelativeOrigin(sf::Sprite& sprite, const float originX, const float originY)
	{
		sf::FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}

	void SetRelativeOrigin(sf::Text& text, const float originX, const float originY)
	{
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(originX * (textRect.width), originY * (textRect.height));
	}
}
