#pragma once
#include "SFML/Audio.hpp"

namespace MedevilEvil
{
	struct Game;

	struct Sound
	{
		sf::Sound appleeat;
		sf::Sound death;
	};

	void InitAppleEatSound(Sound& sound,Game&game);
	void InitDeathSound(Sound& sound, Game& game);
	void PlayAppleEatSound(Sound& sound);
	void PlayDeathSound(Sound& sound);
}
