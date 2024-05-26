#include "ScoreTable.h"
#include "Game.h"
#include "Math.h"

namespace MedievalEvil
{
	void InitPlayerScoresTableText(ScoreTable& scoreTable, sf::Font & font)
	{
		scoreTable.nameText.setFont(font);
		scoreTable.nameText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.nameText.setFillColor(sf::Color::Green);

		scoreTable.scoreText.setFont(font);
		scoreTable.scoreText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.scoreText.setFillColor(sf::Color::Green);

		scoreTable.randomNameIndex = 5;
		scoreTable.nameText.setString("Player");
		scoreTable.score = 0;
		scoreTable.scoreText.setString(std::to_string(scoreTable.score));


		SetRelativeOrigin(scoreTable.nameText, 0.5f, 0.5f);
		SetRelativeOrigin(scoreTable.scoreText, 0.5f, 0.5f);

		scoreTable.nameTextPosition = { SCREEN_WIDTH * 0.45f,SCREEN_HEIGHT * 0.45f };
		scoreTable.scoreTextPosition = { SCREEN_WIDTH * 0.65f,SCREEN_HEIGHT * 0.45f };
	}

	void InitScoresTableText(ScoreTable& scoreTable, sf::Font & font)
	{
		scoreTable.nameText.setFont(font);
		scoreTable.nameText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.nameText.setFillColor(sf::Color::White);

		scoreTable.scoreText.setFont(font);
		scoreTable.scoreText.setCharacterSize(int(SCREEN_WIDTH / 25));
		scoreTable.scoreText.setFillColor(sf::Color::White);

		std::vector<std::string> names ={ "Luis","Mark","Leon","Theodore","Carlos","Jaden","Chester","Edmund","Leslie","Dave","August","Eddie","Michael","Isaiah","Billy","Roosevelt","Jonathan","Mathew","Harold","Jose","Sergio","Emmanuel","Douglas","Roberto","Manuel","Adrian","Tommy","Brian","Donald","Jimmy","Jimmie","Cooper","Dave","Jesse","Dewey","Connor","Oliver","Herman","Amos","Jerome","Shane","Oliver","Roy","Jerry","Irving","Tom","Chris","Thomas","Dana","Willie","Billy","Robert","Zachary","Adrian","Marcus","Jose","Justin","Duane","Roland","Donovan","Kevin","Craig","Patrick","Jon","Hayden","Ellis","Luther","Merle","Wayne","Raymond","Austin","Eddie","Eugene","Ronald","Woodrow","Tracy","Willie","Marion","Bill","Jonathon","Jeffrey","Lee","Adolph","Clifford","Perry","Leonard","Benjamin","Jerry","Jimmy","Michael","Eugene","Edgar","Archie","Jerry","Wallace","Gregory","Mark","Dave","Cory","Antonio" };
		
		scoreTable.randomNameIndex = 1 + rand() % (names.size());
		scoreTable.score = 1 + rand() % (MAX_SCORE);
		scoreTable.scoreText.setString(std::to_string(scoreTable.score));
		
		
		scoreTable.nameText.setString(names[scoreTable.randomNameIndex]);
		
		
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

