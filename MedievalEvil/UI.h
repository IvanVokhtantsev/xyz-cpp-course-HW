#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace MedievalEvil
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
	void InitMenuText(UserInterface& userInterface, sf::Font & font);
	void InitMenuSettingsText(UserInterface& userInterface, sf::Font & font);
	void InitMenuHintText(UserInterface& userInterface, sf::Font & font);
	void InitScoreText(UserInterface& userInterface, sf::Font & font);
	void InitGameOverText(UserInterface& userInterface, sf::Font & font);
	void InitInputHintText(UserInterface& userInterface, sf::Font & font);


	void DrawMenuText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawMenuSettingsText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawMenuHintText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawScoreText(UserInterface& userInterface, int& numEatenApples, sf::RenderWindow& window);
	void DrawGameOverText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);
	void DrawInputHintText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window);

}
