#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace MedevilEvil
{
	struct Game;

	struct UserInterface
	{
		sf::Text menuText;
		sf::Text menuSettingsText;
		sf::Text menuHintText;
		sf::Text scoreText;
		sf::Text gameOverText;
		sf::Text inputHintText;
	};
	void InitMenuText(UserInterface& userInterface, const Game& game);
	void InitMenuSettingsText(UserInterface& userInterface, const Game& game);
	void InitMenuHintText(UserInterface& userInterface, const Game& game);
	void InitScoreText(UserInterface& userInterface, const Game& game);
	void InitGameOverText(UserInterface& userInterface, const Game& game);
	void InitInputHintText(UserInterface& userInterface, const Game& game);


	void DrawMenuText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawMenuSettingsText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawMenuHintText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawScoreText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawGameOverText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawInputHintText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);

}
