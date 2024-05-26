#include "GameStatePlaying.h"
#include <cassert>
#include "Game.h"

namespace MedievalEvil
{


	void InitGameStatePlaying(GameStatePlayingData& data, Game& game)
	{
		assert(data.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(data.appleTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(data.rockTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(data.backgroundGameTexture.loadFromFile(RESOURCES_PATH + "\\Background.png"));
		assert(data.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Bokor-Regular.ttf"));

		InitGameBackground(data.background, data.backgroundGameTexture);
		InitBorder(data.border);
		InitScoreText(data.userInterface, data.font);
		InitPlayer(data.player, data.playerTexture);

		for (Rock& rock : data.rocks)
		{
			InitRock(rock, data.rockTexture);
		}

		InitAppleEatSound(data.sound, data.appleEatBuffer);
		
		
		SetPlayerPosition(data.player, { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f });
		SetPlayerSpeed(data.player, INITIAL_SPEED);
		SetPlayerDirection(data.player, PlayerDirection::Right);

		data.apples.clear();

		int numApples = 1 + rand() % (MAXNUM_APPLES);
		data.apples.resize(numApples);


		for (Apple& apple : data.apples)
		{
			InitApple(apple, data.appleTexture);
			SetApplePosition(apple, GetRandomPositionInRectangle(data.border, APPLE_SIZE));

		}


		for (Rock& rock : data.rocks)
		{
			SetRockPosition(rock, GetRandomPositionInRectangle(data.border, ROCK_SIZE));
		}
		game.numEatenApples = 0;

	}

	void HandleGameStatePlayingWindowEvent(GameStatePlayingData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				SwitchGameState(game, GameStateType::MainMenu);
			}
		}
	}


	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float deltaTime)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			data.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			data.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			data.player.direction = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			data.player.direction = PlayerDirection::Down;
		}

		UpdatePlayer(data.player, deltaTime);

		// Find player collisions with apples
		for (Apple& apple : data.apples)
		{
			if (!apple.isAppleEaten && DoShapesCollide(GetPlayerCollider(data.player), GetAppleCollider(apple)))
			{
				if ((game.maskSettings & (1)) == (1))
				{
					apple.isAppleEaten = true;
				}
				else
				{
					apple.position = GetRandomPositionInRectangle(data.border, APPLE_SIZE);
				}

				++game.numEatenApples;

				if ((game.maskSettings & (1 << 1)) != (1 << 1))
				{
					data.player.speed += ACCELERATION;
				}

				PlayAppleEatSound(data.sound);
			}
		}

		// Find player collisions with rocks
		for (Rock& rock : data.rocks)
		{
			if (DoShapesCollide(GetPlayerCollider(data.player), GetRockCollider(rock)))
			{
				SwitchGameState(game, GameStateType::GameOver);
			}
		}
		// Check screen borders collision
		if (data.player.position.x - PLAYER_SIZE / 2.f < data.border.floatrect.left
			|| data.player.position.x + PLAYER_SIZE / 2.f > data.border.floatrect.width
			|| data.player.position.y - PLAYER_SIZE / 2.f < data.border.floatrect.top
			|| data.player.position.y + PLAYER_SIZE / 2.f > data.border.floatrect.height)
		{
			SwitchGameState(game, GameStateType::GameOver);
		}
	}

	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window)
	{
		DrawGameBackground(data.background, window);

		DrawBorder(data.border, window);

		DrawScoreText(data.userInterface, game.numEatenApples, window);

		DrawPlayer(data.player, window);

		for (Apple& apple : data.apples)
		{
			if (!apple.isAppleEaten)
			{
				DrawApple(apple, window);
			}
		}

		for (Rock& rock : data.rocks)
		{
			DrawRock(rock, window);
		}
	}

	void ShutdownGameStatePlaying(GameStatePlayingData& data, Game& game)
	{

	}
}