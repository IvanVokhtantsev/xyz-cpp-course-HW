#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Sounds.h"
#include "UI.h"
#include "ScoreTable.h"
#include "Background.h"


namespace MedievalEvil
{
	struct Game;
	struct GameStateGameOverData
	{
		Sound sound;
		UserInterface userInterface;
		ScoreTable scoreTable[NUM_PLAYERS];
		Background background;
		sf::Font font;
		sf::SoundBuffer deathBuffer;
		sf::Texture backgroundGameTexture;
	};

	void InitGameStateGameOver(GameStateGameOverData & data, Game& game);
	void HandleGameStateGameOverWindowEvent(GameStateGameOverData& data, Game& game, const sf::Event& event);
	void UpdateGameStateGameOver(GameStateGameOverData & data, Game& game, float deltaTime);
	void DrawGameStateGameOver(GameStateGameOverData & data, Game& game, sf::RenderWindow& window);
	void ShutdownGameStateGameOver(GameStateGameOverData & data, Game& game);


}



