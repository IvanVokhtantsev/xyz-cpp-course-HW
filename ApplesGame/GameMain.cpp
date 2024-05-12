
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Constants.h"
#include "Game.h"


int main()
{
	using namespace MedevilEvil;
	
	const int seed = (const int)time(nullptr);
	srand(seed);
	
	static sf::Image icon;
	icon.loadFromFile(RESOURCES_PATH + "Apple.png");

	sf::RenderWindow window(sf::VideoMode((int)SCREEN_WIDTH, (int)SCREEN_HEIGHT), "Medieval evil");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);
	
	Game* game= new Game();
	InitGame(*game);
	
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		HandleWindowEvents(*game, window);

		UpdateGame(*game, deltaTime);

		window.clear();

		DrawGame(*game, window);

		window.display();
	}
	
	ShutdownGame(*game);
	delete game;
	game = nullptr;
	return 0;
}
