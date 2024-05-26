#pragma once
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "UI.h"

namespace MedievalEvil
{
	struct Game;
	struct GameStateMainMenuData
	{
		UserInterface userInterface;
		Background background;
		sf::Font font;
		sf::Texture backgroundMenuTexture;
	};


	void InitGameStateMainMenu(GameStateMainMenuData& data, Game& game);
	void UpdateGameStateMainMenu(GameStateMainMenuData& data, Game& game, float timeDelta);
	void HandleGameStateMainMenuWindowEvent(GameStateMainMenuData& data, Game& game, const sf::Event& event);
	void DrawGameStateMainMenu(GameStateMainMenuData& data, Game& game, sf::RenderWindow& window);
	void ShutdownGameStateMainMenu(GameStateMainMenuData& data, Game& game);
}
