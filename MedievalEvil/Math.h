#pragma once

namespace sf
{
	class Sprite;
	class Text;
}

namespace MedievalEvil
{
	struct Border;

	struct Vector2D
	{
		float x = 0;
		float y = 0;
	};

	typedef Vector2D Position2D;

	struct Rectangle
	{
		Position2D position;
		Vector2D size;
	};

	struct Circle
	{
		Position2D position;
		float radius;
	};
	
	Position2D GetRandomPositionInRectangle(Border& border, const float size);

	char GetRandomChar();
	
	bool DoShapesCollide(const Rectangle& rect1, const Rectangle& rect2);
	bool DoShapesCollide(const Circle& circle1, const Circle& circle2);
	bool DoShapesCollide(const Rectangle& rect, const Circle& circle);

	void SetSpriteSize(sf::Sprite& sprite, const float desiredWidth, const float desiredHeight);
	
	void SetRelativeOrigin(sf::Sprite& sprite, const float originX, const float originY);
	void SetRelativeOrigin(sf::Text& text, const float originX, const float originY);
}
