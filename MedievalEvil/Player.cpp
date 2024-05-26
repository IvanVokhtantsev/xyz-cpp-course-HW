#include "Player.h"
#include "Game.h"

namespace MedievalEvil
{
	void InitPlayer(Player& player, sf::Texture & texture)
	{
		// Init player state
		player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
		player.speed = INITIAL_SPEED;
		player.direction = PlayerDirection::Right;

		// Init player sprite
		player.sprite.setTexture(texture);
		SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetRelativeOrigin(player.sprite, 0.5f, 0.5f);
	}

	void SetPlayerDirection(Player& player, PlayerDirection direction)
	{
		player.direction = direction;
	}

	void SetPlayerPosition(Player& player, const Position2D& position)
	{
		player.position = position;
	}

	void SetPlayerSpeed(Player& player, float speed)
	{
		player.speed = speed;
	}

	float GetPlayerSpeed(const Player& player)
	{
		return player.speed;
	}

	Rectangle GetPlayerCollider(const Player& player)
	{
		return { { player.position.x - PLAYER_SIZE / 2.f, player.position.y - PLAYER_SIZE / 2.f },
			{ PLAYER_SIZE, PLAYER_SIZE } };
	}

	void UpdatePlayer(Player& player, float deltaTime)
	{
		switch (player.direction)
		{
		case PlayerDirection::Right:
		{
			player.position.x += player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			player.position.y -= player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			player.position.x -= player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			player.position.y += player.speed * deltaTime;
			break;
		}
		}
	}

	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.position.x, player.position.y);
		window.draw(player.sprite);

		if (player.direction == PlayerDirection::Right)
		{
			SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
		}
		else if (player.direction == PlayerDirection::Left)
		{
			SetSpriteSize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
		}
	}
}

