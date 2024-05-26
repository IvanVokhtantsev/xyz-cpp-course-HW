#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace MedievalEvil
{
	const std::string RESOURCES_PATH = "Resources/";
	const float SCREEN_WIDTH = (float)sf::VideoMode::getDesktopMode().width/2.f;
	const float SCREEN_HEIGHT = (float)sf::VideoMode::getDesktopMode().height/2.f;
	
	const float INITIAL_SPEED = SCREEN_WIDTH / 7.f; // Pixels per second
	const float PLAYER_SIZE = SCREEN_WIDTH / 20.f;
	const float ACCELERATION = SCREEN_WIDTH / 100.f; // Pixels per second

	const int NUM_PLAYERS = 7;
	const int MAX_NAME_LENGTH = 20;
	const int MAX_SCORE = 100;

	const int MAXNUM_APPLES = 30;
	const float APPLE_SIZE = SCREEN_WIDTH / 40.f;

	const int NUM_ROCKS = 5;
	const float ROCK_SIZE = SCREEN_WIDTH / 30.f;

	const float BORDER_THICKNESS = 0.f;
	const float BORDER_OFFSET = 0.f;
	const float UI_BLOCK_OFFSET = 0.30f;
}

