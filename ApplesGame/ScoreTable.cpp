#include "ScoreTable.h"
#include "Game.h"
#include "Math.h"

namespace MedevilEvil
{
	void InitPlayerScoresTableText(ScoreTable& scoreTable, const Game& game)
	{
		scoreTable.nameText.setFont(game.font);
		scoreTable.nameText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.nameText.setFillColor(sf::Color::Green);

		scoreTable.scoreText.setFont(game.font);
		scoreTable.scoreText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.scoreText.setFillColor(sf::Color::Green);

		scoreTable.nameLength = 5;
		scoreTable.nameText.setString("Player");
		scoreTable.score = 0;
		scoreTable.scoreText.setString(std::to_string(scoreTable.score));


		SetRelativeOrigin(scoreTable.nameText, 0.5f, 0.5f);
		SetRelativeOrigin(scoreTable.scoreText, 0.5f, 0.5f);

		scoreTable.nameTextPosition = { SCREEN_WIDTH * 0.45f,SCREEN_HEIGHT * 0.45f };
		scoreTable.scoreTextPosition = { SCREEN_WIDTH * 0.65f,SCREEN_HEIGHT * 0.45f };
	}

	void InitScoresTableText(ScoreTable& scoreTable, const Game& game)
	{
		scoreTable.nameText.setFont(game.font);
		scoreTable.nameText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.nameText.setFillColor(sf::Color::White);

		scoreTable.scoreText.setFont(game.font);
		scoreTable.scoreText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.scoreText.setFillColor(sf::Color::White);
		
		scoreTable.nameLength = 1 + rand() % (MAX_NAME_LENGTH);
		scoreTable.score = 1 + rand() % (MAX_SCORE);
		scoreTable.scoreText.setString(std::to_string(scoreTable.score));
		
		for (int i = 0; i < scoreTable.nameLength; ++i)
		{
			scoreTable.nameText.setString(GetRandomChar() + scoreTable.nameText.getString());
		}
		
		SetRelativeOrigin(scoreTable.nameText, 0.5f, 0.5f);
		SetRelativeOrigin(scoreTable.scoreText, 0.5f, 0.5f);
		
		scoreTable.nameTextPosition = { SCREEN_WIDTH * 0.45f,SCREEN_HEIGHT * 0.45f };
		scoreTable.scoreTextPosition = { SCREEN_WIDTH * 0.65f,SCREEN_HEIGHT * 0.45f };
	}

	bool FindPlayer (const ScoreTable& player)
	{
		return (player.nameText.getString() == "Player");
	}

	bool CompareScores(const ScoreTable& score1, const ScoreTable& score2)
	{
		return score1.score > score2.score;
	}

	void DrawScoresTableText(ScoreTable& scoreTable, const Game& game, sf::RenderWindow& window)
	{
		window.draw(scoreTable.nameText);
		window.draw(scoreTable.scoreText);
	}
}
