#include "UI.h"
#include "Game.h"
#include "Math.h"

namespace MedevilEvil
{
	void InitMenuText(UserInterface& userInterface, const Game& game)
	{
		userInterface.menuText.setFont(game.font);
		userInterface.menuText.setCharacterSize(int(SCREEN_WIDTH / 10));
		userInterface.menuText.setStyle(sf::Text::Bold);
		userInterface.menuText.setFillColor(sf::Color::Color(16, 25, 59, 255));
		userInterface.menuText.setString("Medieval evil");
		SetRelativeOrigin(userInterface.menuText, 0.5f, 0.5f);
		userInterface.menuText.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.1f);
	}

	void InitMenuSettingsText(UserInterface& userInterface, const Game& game)
	{
		userInterface.menuSettingsText.setFont(game.font);
		userInterface.menuSettingsText.setCharacterSize(int(SCREEN_WIDTH / 30));
		userInterface.menuSettingsText.setStyle(sf::Text::Bold);
		userInterface.menuSettingsText.setFillColor(sf::Color::Color(36, 45, 79, 255));
		userInterface.menuSettingsText.setLineSpacing(0.6f);
		userInterface.menuSettingsText.setString("Infinite mode: \n1-On (defalt)/ 2-Off \nPlayer acceleration: \n3-On (defalt)/ 4-Off ");
		SetRelativeOrigin(userInterface.menuSettingsText, 0.f, 0.5f);
		userInterface.menuSettingsText.setPosition(SCREEN_WIDTH * 0.05f, SCREEN_HEIGHT * 0.45f);
	}

	void InitMenuHintText(UserInterface& userInterface, const Game& game)
	{
		userInterface.menuHintText.setFont(game.font);
		userInterface.menuHintText.setCharacterSize(int(SCREEN_WIDTH / 40));
		userInterface.menuHintText.setFillColor(sf::Color::White);
		userInterface.menuHintText.setString("Arrow keys - Move, Enter - Start, Esc - Exit");
		SetRelativeOrigin(userInterface.menuHintText, 0.5f, 0.5f);
		userInterface.menuHintText.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.97f);
	}

	void InitScoreText(UserInterface& userInterface, const Game& game)
	{
		userInterface.scoreText.setFont(game.font);
		userInterface.scoreText.setCharacterSize(int(SCREEN_WIDTH / 40));
		userInterface.scoreText.setFillColor(sf::Color::Color(36, 45, 79, 255));
		userInterface.scoreText.setString("Apples eaten: ");
		SetRelativeOrigin(userInterface.scoreText, 0.f, 0.5f);
		userInterface.scoreText.setPosition(SCREEN_WIDTH * 0.75f, SCREEN_HEIGHT * UI_BLOCK_OFFSET * 1 / 6);
	}

	void InitGameOverText(UserInterface& userInterface, const Game& game)
	{
		userInterface.gameOverText.setFont(game.font);
		userInterface.gameOverText.setCharacterSize(int(SCREEN_WIDTH / 10));
		userInterface.gameOverText.setStyle(sf::Text::Bold);
		userInterface.gameOverText.setFillColor(sf::Color::Red);
		userInterface.gameOverText.setString("GAME OVER");
		SetRelativeOrigin(userInterface.gameOverText, 0.5f, 0.5f);
		userInterface.gameOverText.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3f);
	}


	void InitInputHintText(UserInterface& userInterface, const Game& game)
	{
		userInterface.inputHintText.setFont(game.font);
		userInterface.inputHintText.setCharacterSize(int(SCREEN_WIDTH / 50));
		userInterface.inputHintText.setFillColor(sf::Color::White);
		userInterface.inputHintText.setString("Enter - Restart, Esc - Menu");
		SetRelativeOrigin(userInterface.inputHintText, 0.5f, 0.5f);
		userInterface.inputHintText.setPosition(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.95f);
	}

	void DrawMenuText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window)
	{
		window.draw(userInterface.menuText);
	}

	void DrawMenuSettingsText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window)
	{
		window.draw(userInterface.menuSettingsText);
	}

	void DrawMenuHintText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window)
	{
		window.draw(userInterface.menuHintText);
	}

	void DrawScoreText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window)
	{
		userInterface.scoreText.setString("Apples eaten: " + std::to_string(game.numEatenApples));
		window.draw(userInterface.scoreText);
	}

	void DrawGameOverText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window)
	{
		window.draw(userInterface.gameOverText);
	}


	void DrawInputHintText(UserInterface& userInterface, const Game& game, sf::RenderWindow& window)
	{
		window.draw(userInterface.inputHintText);
	}
}
