#include "Background.h"
#include "Game.h"

namespace MedevilEvil
{
	void InitMenuBackground(Background& background, const Game& game)
	{
		{
			background.menu.setTexture(game.backgroundMenuTexture);
			SetSpriteSize(background.menu, SCREEN_WIDTH, SCREEN_HEIGHT);
		}
		
	}
	void DrawMenuBackground(Background& background, sf::RenderWindow& window)
	{
		window.draw(background.menu);
	}

	void InitGameBackground(Background& background, const Game& game)
	{
		{
			background.game.setTexture(game.backgroundGameTexture);
			SetSpriteSize(background.game, SCREEN_WIDTH, SCREEN_HEIGHT);
		}

	}
	void DrawGameBackground(Background& background, sf::RenderWindow& window)
	{
		window.draw(background.game);
	}
}
