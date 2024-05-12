#include "Rock.h"
#include "Game.h"

namespace MedevilEvil
{
	void InitRock(Rock& rock, Game& game)
	{
		rock.sprite.setTexture(game.rockTexture);
		SetSpriteSize(rock.sprite, ROCK_SIZE, ROCK_SIZE);
		SetRelativeOrigin(rock.sprite, 0.5f, 0.5f);
	}

	void SetRockPosition(Rock& rock, const Position2D& position)
	{
		rock.position = position;
	}

	Rectangle GetRockCollider(const Rock& rock)
	{
		return { { rock.position.x - ROCK_SIZE / 2.f, rock.position.y - ROCK_SIZE / 2.f },
					{ ROCK_SIZE, ROCK_SIZE } };
	}


	void DrawRock(Rock& rock, sf::RenderWindow& window)
	{
		rock.sprite.setPosition(rock.position.x, rock.position.y);
		window.draw(rock.sprite);
	}
}

