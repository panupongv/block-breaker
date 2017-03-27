#include "Player.hpp"

Player::Player()
	:
	Sprite("brick.png", 120, 30, 260, 570)
{ 
	alive = true;
	moving = true;
}

void Player::update(Game& game)
{
	setCenter(game.getMousePosition().x, 570 + 15);
}
