#pragma once
#include <SFML/Graphics.hpp>
#include "Constants.h"

namespace MedievalEvil
{
	struct Game;

	struct ScoreTable
	{
		int score = 0;
		int randomNameIndex = 0;
		sf::Vector2f nameTextPosition;
		sf::Vector2f scoreTextPosition;
		sf::Text nameText;
		sf::Text scoreText;
	};
	

	void InitPlayerScoresTableText(ScoreTable& scoreTable, sf::Font & font);

	void InitScoresTableText(ScoreTable& scoreTable, sf::Font & font);

	bool FindPlayer (const ScoreTable&player);

	bool CompareScores(const ScoreTable& score1, const ScoreTable& score2);

	void DrawScoresTableText(ScoreTable& scoreTable, const Game& game, sf::RenderWindow& window);

}
