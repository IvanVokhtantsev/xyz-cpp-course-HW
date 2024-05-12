#include "Sounds.h"
#include "Game.h"


namespace MedevilEvil
{

	void InitAppleEatSound(Sound& sound, Game& game)
	{
		sound.appleeat.setBuffer(game.appleeatBuffer);
	}

	void InitDeathSound(Sound& sound, Game& game)
	{
		sound.death.setBuffer(game.deathBuffer);
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
