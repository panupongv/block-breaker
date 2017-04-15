#include "Player.hpp"

Player::Player(std::string texture_name)
	:
	Sprite(texture_name, getWidthByName(texture_name), getHeightByName(texture_name), 250, getHitlineByName(texture_name)),
	hit_line(getHitlineByName(texture_name))
{ 
	setAlive(true);
	setMoving(true);
}

void Player::update(Game& game)
{
	latest_pos = center().x;
	if(game.getMousePosition().x - getFrameWidth()/2.0f >= game.left_bound && game.getMousePosition().x + getFrameWidth() / 2.0f <= game.right_bound)
		setCenter(game.getMousePosition().x, hit_line + getFrameHeight() / 2);
	delta_x = center().x - latest_pos;
}

int Player::getHitLine() const
{
	return hit_line;
}

int Player::getHitZone(float x) const
{
	float center_x = center().x;
	int frame_width = getFrameWidth();
	if (center_x - frame_width * 0.5f <= x && x < center_x - frame_width * 0.4f)
		return 1;  
	if (center_x - frame_width * 0.4f <= x && x < center_x - frame_width * 0.25f)
		return 2;  
	if (center_x - frame_width * 0.25f <= x && x < center_x - frame_width * 0.075f)
		return 3;  
	if (center_x - frame_width * 0.075f <= x && x <= center_x + frame_width * 0.075f)
		return 4;
	if (center_x + frame_width * 0.075f < x && x <= center_x + frame_width * 0.25f)
		return 3;
	if (center_x + frame_width * 0.25f < x && x <= center_x + frame_width * 0.4f)
		return 5;
	if (center_x + frame_width * 0.4f < x && x <= center_x + frame_width * 0.5f)
		return 6;
	return 0;
}

float Player::getDeltaX() const
{
	return delta_x;
}

int Player::getWidthByName(const std::string & texture_name) const
{
	if (texture_name == "paddle.png")
		return 120;
	if (texture_name == "catpad.png")
		return 200;
	return 120;
}

int Player::getHeightByName(const std::string & texture_name) const
{
	if (texture_name == "paddle.png")
		return 15;
	if (texture_name == "catpad.png")
		return 37;
	return 30;
}

int Player::getHitlineByName(const std::string & texture_name) const
{
	if (texture_name == "paddle.png")
		return 590;
	if (texture_name == "catpad.png")
		return 575;
	return 0;
}
