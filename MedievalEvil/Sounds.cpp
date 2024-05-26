#include "Sounds.h"
#include "Game.h"


namespace MedievalEvil
{

	void InitAppleEatSound(Sound& sound, sf::SoundBuffer & soundBuffer)
	{
		sound.appleeat.setBuffer(soundBuffer);
	}

	void InitDeathSound(Sound& sound, sf::SoundBuffer & soundBuffer)
	{
		sound.death.setBuffer(soundBuffer);
	}

	void PlayAppleEatSound(Sound& sound)
	{
		sound.appleeat.play();
	}

	void PlayDeathSound(Sound& sound)
	{
		sound.death.play();
	}
}
