#pragma once
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Player.h"
#include "Apple.h"
#include "Rock.h"
#include "UI.h"
#include "Border.h"
#include "Background.h"
#include "Sounds.h"

namespace MedievalEvil
{
	struct Game;
	
	struct GameStatePlayingData
	{
		Player player;
		Rock rocks[NUM_ROCKS];
		Border border;
		Sound sound;
		Background background;
		UserInterface userInterface;
		std::vector<Apple> apples;

		sf::Font font;
		sf::Texture playerTexture;
		sf::Texture appleTexture;
		sf::Texture rockTexture;
		sf::Texture backgroundGameTexture;
		sf::SoundBuffer appleEatBuffer;

	};

	void InitGameStatePlaying(GameStatePlayingData& data, Game& game);
	void HandleGameStatePlayingWindowEvent(GameStatePlayingData& data, Game& game, const sf::Event& event);
	void UpdateGameStatePlaying(GameStatePlayingData& data, Game& game, float deltaTime);
	void DrawGameStatePlaying(GameStatePlayingData& data, Game& game, sf::RenderWindow& window);
	void ShutdownGameStatePlaying(GameStatePlayingData& data, Game& game);
}

