#include "Game.hpp"
#include "Entity.hpp"
#include "Screen.hpp"
#include "Sound.hpp"
#include "Event.hpp"

// Player
void Player::move()
{
	float dx = 0, dy = 0;
	if (event->state[SDL_SCANCODE_RIGHT])
		dx += speed;
	if (event->state[SDL_SCANCODE_LEFT])
		dx -= speed;
	if (event->state[SDL_SCANCODE_UP])
		dy -= speed;
	if (event->state[SDL_SCANCODE_DOWN])
		dy += speed;

	float len = std::sqrt(dx * dx + dy * dy);
	if (len > 0)
	{
		dx /= len;
		dy /= len;
	}
	x += dx * speed;
	y += dy * speed;

	if (x <= 0)
		x = 0;
	if (x + 64 - 10 > Game::win_w)
		x = Game::win_w + 10 - 64;
	if (y <= 0)
		y = 0;
	if (y + 64 > Game::win_h)
		y = Game::win_h - 64;
}

void Player::attack()
{
}

void Player::takeDamage()
{
}

// Enemy
void Enemy::move()
{
	float dx = players[0]->x - x;
	float dy = players[0]->y - y;
	float hyp = std::sqrt(dx * dx + dy * dy);
	dx /= hyp;
	dy /= hyp;
	x += dx * speed;
	y += dy * speed;
}

void Enemy::attack()
{
}

void Enemy::takeDamage()
{
}

void Enemy::spawn()
{
	if (players[0]->x < Game::win_w / 2)
		x = std::rand() % (Game::win_w / 2) + Game::win_w / 2;
	else
		x = std::rand() % (Game::win_w / 2);

	if (players[0]->y < Game::win_h / 2)
		y = std::rand() % (Game::win_h / 2) + Game::win_h / 2;
	else
		y = std::rand() % (Game::win_h / 2);
}