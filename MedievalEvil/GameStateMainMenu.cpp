#include "GameStateMainMenu.h"
#include <cassert>
#include "Game.h"

namespace MedievalEvil
{
	void InitGameStateMainMenu(GameStateMainMenuData& data, Game& game)
	{
		assert(data.backgroundMenuTexture.loadFromFile(RESOURCES_PATH + "\\Menu.png"));
		assert(data.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Bokor-Regular.ttf"));
		InitMenuBackground(data.background, data.backgroundMenuTexture);
		InitMenuText(data.userInterface, data.font);
		InitMenuSettingsText(data.userInterface, data.font);
		InitMenuHintText(data.userInterface, data.font);
	}

	void UpdateGameStateMainMenu(GameStateMainMenuData& data, Game& game, float timeDelta)
	{

	}

	void HandleGameStateMainMenuWindowEvent(GameStateMainMenuData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				SwitchGameState(game, GameStateType::Playing);
			}
			if (event.key.code == sf::Keyboard::Num1)
			{
				game.maskSettings = game.maskSettings & ~(1);
			}
			if (event.key.code == sf::Keyboard::Num2)
			{
				game.maskSettings = game.maskSettings | (1);
			}
			if (event.key.code == sf::Keyboard::Num3)
			{
				game.maskSettings = game.maskSettings & ~(1 << 1);
			}
			if (event.key.code == sf::Keyboard::Num4)
			{
				game.maskSettings = game.maskSettings | (1 << 1);
			}
		}
	}

	void DrawGameStateMainMenu(GameStateMainMenuData& data, Game& game, sf::RenderWindow& window)
	{
		DrawMenuBackground(data.background, window);
		DrawMenuText(data.userInterface, game, window);
		DrawMenuSettingsText(data.userInterface, game, window);
		DrawMenuHintText(data.userInterface, game, window);
	}

	void ShutdownGameStateMainMenu(GameStateMainMenuData& data, Game& game)
	{

	}
}