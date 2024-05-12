#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Constants.h"
#include "Math.h"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "Background.h"
#include "UI.h"
#include "Border.h"
#include "Sounds.h"
#include "ScoreTable.h"


namespace MedevilEvil
{
	enum class GameState
	{
		None = 0,
		Menu,
		Playing,
		GameOver,
	};


	struct Game
	{
		Player player;
		Rock rocks[NUM_ROCKS];
		Background background;
		UserInterface userInterface;
		Border border;
		Sound sound;
		ScoreTable scoreTable[NUM_PLAYERS];
		std::vector<Apple> apples;
		
		std::vector<GameState> gameStateStack;

		int numEatenApples = 0;
		int maskSettings = 0;

		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::Texture backgroundMenuTexture;
		sf::Texture backgroundGameTexture;
		sf::Font font;
		sf::SoundBuffer appleeatBuffer;
		sf::SoundBuffer deathBuffer;

	};
	void HandleInput(Game& game);
	void HandleWindowEvents(Game& game, sf::RenderWindow& window);
	
	void InitGame(Game& game);
	void UpdateGame(Game& game, float deltaTime);
	void DrawGame(Game& game, sf::RenderWindow& window);
	void ShutdownGame(Game& game);

	void PushGameState(Game& game, GameState state);
	void PopGameState(Game& game);
	void SwitchGameState(Game& game, GameState newstate);
	void SwitchGameStateInternal(Game& game, GameState oldState, GameState newState);
	GameState GetCurrentGameState(const Game& game);

	void InitPlayingState(Game& game);
	void UpdatePlayingState(Game& game, float deltaTime);
	void DrawPlayingState(Game& game, sf::RenderWindow& window);
	void ShutdownPlayingState(Game& game);
	
	void InitGameOverState(Game& game);
	void UpdateGameOverState(Game& game, float deltaTime);
	void DrawGameOverState(Game& game, sf::RenderWindow& window);
	void ShutdownGameOverState(Game& game);


	void InitMenuState(Game& game);
	void UpdateMenuState(Game& game, float timeDelta);
	void DrawMenuState(Game& game, sf::RenderWindow& window);
	void ShutdownMenuState(Game& game);
	
}


