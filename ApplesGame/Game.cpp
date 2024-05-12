#include "Game.h"
#include <cassert>
#include <algorithm>

namespace MedevilEvil
{
	void HandleInput(Game& game)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			game.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			game.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			game.player.direction = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			game.player.direction = PlayerDirection::Down;
		}
	}

	void HandleWindowEvents(Game& game, sf::RenderWindow& window)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				if (GetCurrentGameState(game) == GameState::Menu)
				{
					window.close();
					break;
				}
				else
				{
					SwitchGameState(game, GameState::Menu); 
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				SwitchGameState(game, GameState::Playing);
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num1)
			{
				game.maskSettings = game.maskSettings & ~(1);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num2)
			{
				game.maskSettings = game.maskSettings | (1);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num3)
			{
				game.maskSettings = game.maskSettings & ~(1 << 1);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Num4)
			{
				game.maskSettings = game.maskSettings | (1 << 1);
			}

		}
	}


	void InitGame(Game& game)
	{
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.rockTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(game.backgroundMenuTexture.loadFromFile(RESOURCES_PATH + "\\Menu.png"));
		assert(game.backgroundGameTexture.loadFromFile(RESOURCES_PATH + "\\Background.png"));
		assert(game.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Bokor-Regular.ttf"));
		assert(game.appleeatBuffer.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));
		assert(game.deathBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));

		InitMenuBackground(game.background, game);
		InitGameBackground(game.background, game);
		InitBorder(game.border);
		InitMenuText(game.userInterface, game);
		InitMenuSettingsText(game.userInterface, game);
		InitMenuHintText(game.userInterface, game);
		InitInputHintText(game.userInterface, game);
		InitScoreText(game.userInterface, game);
		InitGameOverText(game.userInterface, game);
		InitPlayer(game.player, game);

		for (Rock& rock : game.rocks)
		{
			InitRock(rock, game);
		}

		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			if (i == 0)
			{
				InitPlayerScoresTableText(game.scoreTable[i], game);
			}
			else
			{
				InitScoresTableText(game.scoreTable[i], game);
			}
		}

		InitAppleEatSound(game.sound, game);
		InitDeathSound(game.sound, game);

		int maskSettings = 0;
		game.gameStateStack.push_back(GameState::Menu);

		PushGameState(game, GameState::Menu);


	}

	void UpdateGame(Game& game, float timeDelta)
	{
		GameState gameState = game.gameStateStack.back();
		switch (gameState)
		{
		case GameState::Playing:
			UpdatePlayingState(game, timeDelta);
			break;
		case GameState::GameOver:
			UpdateGameOverState(game, timeDelta);
			break;
		case GameState::Menu:
			UpdateMenuState(game, timeDelta);
			break;
		default:
			break;
		}

	}

	void DrawGame(Game& game, sf::RenderWindow& window)
	{
		GameState gameState = game.gameStateStack.back();
		switch (gameState)
		{
		case GameState::Playing:
			DrawPlayingState(game, window);
			break;
		case GameState::GameOver:
			DrawGameOverState(game, window);
			break;
		case GameState::Menu:
			DrawMenuState(game, window);
			break;
		default:
			break;
		}

		
	}

	void ShutdownGame(Game& game)
	{
		while (game.gameStateStack.size() > 0)
		{
			PopGameState(game);
		}
	}

	void PushGameState(Game& game, GameState state)
	{
		GameState oldState = GameState::None;
		if (game.gameStateStack.size() > 0)
		{
			oldState = game.gameStateStack.back();
		}

		SwitchGameStateInternal(game, oldState, state);
		game.gameStateStack.push_back(state);
	}

	void PopGameState(Game& game)
	{
		GameState oldState = GameState::None;
		if (game.gameStateStack.size() > 0)
		{
			oldState = game.gameStateStack.back();
		}

		game.gameStateStack.pop_back();
		GameState state = GameState::None;
		if (game.gameStateStack.size() > 0)
		{
			state = game.gameStateStack.back();
		}

		SwitchGameStateInternal(game, oldState, state);
	}

	void SwitchGameState(Game& game, GameState newState)
	{
		if (game.gameStateStack.size() > 0)
		{
			GameState oldState = game.gameStateStack.back();
			game.gameStateStack.pop_back();
			game.gameStateStack.push_back(newState);
			SwitchGameStateInternal(game, oldState, newState);
		}
		else
		{
			PushGameState(game, newState);
		}
	}

	void SwitchGameStateInternal(Game& game, GameState oldState, GameState newState)
	{
		switch (oldState)
		{
		case GameState::Playing:
		{
			ShutdownPlayingState(game);
			break;
		}
		case GameState::GameOver:
		{
			ShutdownGameOverState(game);
			break;
		}
		case GameState::Menu:
		{
			ShutdownMenuState(game);
			break;
		}
		}

		switch (newState)
		{
		case MedevilEvil::GameState::Playing:
		{
			InitPlayingState(game);
			break;
		}
		case MedevilEvil::GameState::GameOver:
		{
			InitGameOverState(game);
			break;
		}
		case GameState::Menu:
		{
			InitMenuState(game);
			break;
		}
		default:
		{
			break;
		}
		}
	}

	GameState GetCurrentGameState(const Game& game)
	{
		if (game.gameStateStack.size() > 0)
		{
			return game.gameStateStack.back();
		}
		else
		{
			return GameState::None;
		}
	}


	void InitPlayingState(Game& game)
	{
		SetPlayerPosition(game.player, { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f });
		SetPlayerSpeed(game.player, INITIAL_SPEED);
		SetPlayerDirection(game.player, PlayerDirection::Right);

		game.apples.clear();

		int numApples = 1 + rand() % (MAXNUM_APPLES);
		game.apples.resize(numApples);


		for (Apple& apple : game.apples)
		{
			InitApple(apple, game);
			SetApplePosition(apple, GetRandomPositionInRectangle(game.border, APPLE_SIZE));

		}


		for (Rock& rock : game.rocks)
		{
			SetRockPosition(rock, GetRandomPositionInRectangle(game.border, ROCK_SIZE));
		}
		game.numEatenApples = 0;

	}

	void UpdatePlayingState(Game& game, float deltaTime)
	{
		HandleInput(game);

		UpdatePlayer(game.player, deltaTime);

		// Find player collisions with apples
		for (Apple& apple : game.apples)
		{
			if (!apple.isAppleEaten && DoShapesCollide(GetPlayerCollider(game.player), GetAppleCollider(apple)))
			{
				if ((game.maskSettings & (1)) == (1))
				{
					apple.isAppleEaten = true;
				}
				else
				{
					apple.position = GetRandomPositionInRectangle(game.border, APPLE_SIZE);
				}

				++game.numEatenApples;

				if ((game.maskSettings & (1 << 1)) != (1 << 1))
				{
					game.player.speed += ACCELERATION;
				}

				PlayAppleEatSound(game.sound);
			}
		}

		// Find player collisions with rocks
		for (Rock& rock : game.rocks)
		{
			if (DoShapesCollide(GetPlayerCollider(game.player), GetRockCollider(rock)))
			{
				SwitchGameState(game, GameState::GameOver);
			}
		}
		// Check screen borders collision
		if (game.player.position.x - PLAYER_SIZE / 2.f < game.border.floatrect.left
			|| game.player.position.x + PLAYER_SIZE / 2.f > game.border.floatrect.width
			|| game.player.position.y - PLAYER_SIZE / 2.f < game.border.floatrect.top
			|| game.player.position.y + PLAYER_SIZE / 2.f > game.border.floatrect.height)
		{
			SwitchGameState(game, GameState::GameOver);
		}
	}

	void DrawPlayingState(Game& game, sf::RenderWindow& window)
	{
		DrawGameBackground(game.background, window);

		DrawBorder(game.border, window);

		DrawScoreText(game.userInterface, game, window);

		DrawPlayer(game.player, window);

		for (Apple& apple : game.apples)
		{
			if (!apple.isAppleEaten)
			{
				DrawApple(apple, window);
			}
		}

		for (Rock& rock : game.rocks)
		{
			DrawRock(rock, window);
		}
	}
	
	void ShutdownPlayingState(Game& game)
	{

	}



	void InitGameOverState(Game& game)
	{
		PlayDeathSound(game.sound);

		auto it = std::find_if(std::begin(game.scoreTable), std::end(game.scoreTable), &FindPlayer);

		auto indexPlayer = std::distance(std::begin(game.scoreTable), it);
		game.scoreTable[indexPlayer].score = game.numEatenApples;
		game.scoreTable[indexPlayer].scoreText.setString(std::to_string(game.scoreTable[indexPlayer].score));
		SetRelativeOrigin(game.scoreTable[indexPlayer].scoreText, 0.5f, 0.5f);

		std::stable_sort(std::begin(game.scoreTable), std::end(game.scoreTable), &CompareScores);

		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			game.scoreTable[i].nameText.setPosition(sf::Vector2f(0.f, i * SCREEN_WIDTH / 25) + game.scoreTable[i].nameTextPosition);
			game.scoreTable[i].scoreText.setPosition(sf::Vector2f(0.f, i * SCREEN_WIDTH / 25) + game.scoreTable[i].scoreTextPosition);
		}
	}

	void UpdateGameOverState(Game& game, float timeDelta)
	{

	}

	void DrawGameOverState(Game& game, sf::RenderWindow& window)
	{
		DrawGameBackground(game.background, window);
		DrawInputHintText(game.userInterface, game, window);
		DrawGameOverText(game.userInterface, game, window);
		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			DrawScoresTableText(game.scoreTable[i], game, window);
		}
	}

	void ShutdownGameOverState(Game& game)
	{

	}



	void InitMenuState(Game& game)
	{

	}

	void UpdateMenuState(Game& game, float timeDelta)
	{

	}

	void DrawMenuState(Game& game, sf::RenderWindow& window)
	{
		DrawMenuBackground(game.background, window);
		DrawMenuText(game.userInterface, game, window);
		DrawMenuSettingsText(game.userInterface, game, window);
		DrawMenuHintText(game.userInterface, game, window);
	}

	void ShutdownMenuState(Game& game)
	{

	}

}
