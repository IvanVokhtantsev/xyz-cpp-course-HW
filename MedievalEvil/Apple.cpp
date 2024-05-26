#include "Apple.h"
#include "Game.h"

namespace MedievalEvil
{
	void InitApple(Apple& apple, sf::Texture & texture)
	{
		apple.sprite.setTexture(texture);
		SetSpriteSize(apple.sprite, APPLE_SIZE, APPLE_SIZE);
		SetRelativeOrigin(apple.sprite, 0.5f, 0.5f);
		apple.isAppleEaten = false;

	}
	void SetApplePosition(Apple& apple, const Position2D& position)
	{
		apple.position = position;
	}

	Circle GetAppleCollider(const Apple& apple)
	{
		return { apple.position, APPLE_SIZE / 2.f };
	}

	void DrawApple(Apple& apple, sf::RenderWindow& window)
	{
		apple.sprite.setPosition(apple.position.x, apple.position.y);
		window.draw(apple.sprite);
	}
}

