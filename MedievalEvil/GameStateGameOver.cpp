#include "GameStateGameOver.h"
#include <cassert>
#include "Game.h"
#include <iterator>

namespace MedievalEvil
{
	void InitGameStateGameOver(GameStateGameOverData & data, Game& game)
	{
		assert(data.deathBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));
		assert(data.font.loadFromFile(RESOURCES_PATH + "\\Fonts\\Bokor-Regular.ttf"));
		assert(data.backgroundGameTexture.loadFromFile(RESOURCES_PATH + "\\Background.png"));

		InitGameBackground(data.background, data.backgroundGameTexture);
		InitGameOverText(data.userInterface, data.font);
		InitInputHintText(data.userInterface, data.font);
		InitDeathSound(data.sound, data.deathBuffer);
		PlayDeathSound(data.sound);
		
		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			if (i == 0)
			{
				InitPlayerScoresTableText(data.scoreTable[i], data.font);
			}
			else
			{
				InitScoresTableText(data.scoreTable[i], data.font);
			}
		}
		auto it = std::find_if(std::begin(data.scoreTable), std::end(data.scoreTable), &FindPlayer);

		auto indexPlayer = std::distance(std::begin(data.scoreTable), it);

		data.scoreTable[indexPlayer].score = game.numEatenApples;
		data.scoreTable[indexPlayer].scoreText.setString(std::to_string(data.scoreTable[indexPlayer].score));
		SetRelativeOrigin(data.scoreTable[indexPlayer].scoreText, 0.5f, 0.5f);

		std::stable_sort(std::begin(data.scoreTable), std::end(data.scoreTable), &CompareScores);

		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			data.scoreTable[i].nameText.setPosition(sf::Vector2f(0.f, i * SCREEN_WIDTH / 25) + data.scoreTable[i].nameTextPosition);
			data.scoreTable[i].scoreText.setPosition(sf::Vector2f(0.f, i * SCREEN_WIDTH / 25) + data.scoreTable[i].scoreTextPosition);
		}
	}

	void HandleGameStateGameOverWindowEvent(GameStateGameOverData& data, Game& game, const sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				SwitchGameState(game, GameStateType::Playing);
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				SwitchGameState(game, GameStateType::MainMenu);
			}
		}
	}

	void UpdateGameStateGameOver(GameStateGameOverData & data, Game& game, float timeDelta)
	{

	}

	void DrawGameStateGameOver(GameStateGameOverData & data, Game& game, sf::RenderWindow& window)
	{
		DrawGameBackground(data.background, window);
		DrawInputHintText(data.userInterface, game, window);
		DrawGameOverText(data.userInterface, game, window);
		for (int i = 0; i < NUM_PLAYERS; ++i)
		{
			DrawScoresTableText(data.scoreTable[i], game, window);
		}
	}

	void ShutdownGameStateGameOver(GameStateGameOverData & data, Game& game)
	{

	}
}