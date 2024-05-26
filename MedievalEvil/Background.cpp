#include "Background.h"
#include "Game.h"

namespace MedievalEvil
{
	void InitMenuBackground(Background& background, sf::Texture& texture)
	{
		{
			background.menu.setTexture(texture);
			SetSpriteSize(background.menu, SCREEN_WIDTH, SCREEN_HEIGHT);
		}
		
	}
	void DrawMenuBackground(Background& background, sf::RenderWindow& window)
	{
		window.draw(background.menu);
	}

	void InitGameBackground(Background& background, sf::Texture & texture)
	{
		{
			background.game.setTexture(texture);
			SetSpriteSize(background.game, SCREEN_WIDTH, SCREEN_HEIGHT);
		}

	}
	void DrawGameBackground(Background& background, sf::RenderWindow& window)
	{
		window.draw(background.game);
	}
}
