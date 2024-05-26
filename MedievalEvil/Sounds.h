#pragma once
#include "SFML/Audio.hpp"

namespace MedievalEvil
{
	struct Game;

	struct Sound
	{
		sf::Sound appleeat;
		sf::Sound death;
	};

	void InitAppleEatSound(Sound& sound, sf::SoundBuffer & soundbuffer);
	void InitDeathSound(Sound& sound, sf::SoundBuffer & soundbuffer);
	void PlayAppleEatSound(Sound& sound);
	void PlayDeathSound(Sound& sound);
}
