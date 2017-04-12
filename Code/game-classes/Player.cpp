#include "Player.hpp"

Player::Player()
	:
	Sprite("brick.png", 120, 15, 0, hit_line)
{ 
	setAlive(true);
	setMoving(true);
}

void Player::update(Game& game)
{
	setCenter(game.getMousePosition().x, hit_line + getFrameHeight() / 2);
}

int Player::getHitLine() const
{
	return hit_line;
}

int Player::getHitZone(float x) const
{
	if (center().x - 60 < x && x < center().x - 50)
		return 1;
	if (center().x - 50 < x && x < center().x - 30)
		return 2;
	if (center().x - 30 < x && x < center().x + 30)
		return 3;
	if (center().x + 30 < x && x < center().x + 50)
		return 4;
	if (center().x + 50 < x && x < center().x + 60)
		return 5;
	return 0;
}
