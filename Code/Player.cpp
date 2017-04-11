#include "Player.hpp"

Player::Player()
	:
	Sprite("brick.png", 120, 30, 260, 570)
{ 
	setAlive(true);
	setMoving(true);
}

void Player::update(Game& game)
{
	setCenter(game.getMousePosition().x, 570 + 15);
}
