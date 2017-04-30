#include "Player.hpp"

Player::Player(std::string texture_name)
	:
	Sprite(texture_name, getWidthByName(texture_name), getHeightByName(texture_name), 250, 500),
	hit_line(getHitlineByName(texture_name)),
	center_line(Game::left_bound + Game::game_width / 2.0f),
	drunk(0)
{ 
	setAlive(true);
	setMoving(true);
	setHaveRocket(false);
}

void Player::update(Game& game)
{
	latest_pos = center().x;
	if (game.getMousePosition().x - getFrameWidth() / 2.0f < game.left_bound)
	{
		if (drunk)
			setCenter(game.right_bound - getFrameWidth() / 2.0f, hit_line + getFrameHeight() / 2);
		else
			setCenter(game.left_bound + getFrameWidth() / 2.0f, hit_line + getFrameHeight() / 2);
	}
	else if (game.getMousePosition().x + getFrameWidth() / 2.0f > game.right_bound)
	{
		if (drunk)
			setCenter(game.left_bound + getFrameWidth() / 2.0f, hit_line + getFrameHeight() / 2);
		else
			setCenter(game.right_bound - getFrameWidth() / 2.0f, hit_line + getFrameHeight() / 2);
	}
	else
	{
		if (drunk)
		{
			float mouse_x = game.getMousePosition().x;
			if (mouse_x < center_line)
				setCenter(game.right_bound - (mouse_x + game.left_bound) , hit_line + getFrameHeight() / 2);
			else
				setCenter(game.left_bound + game.right_bound - mouse_x , hit_line + getFrameHeight() / 2);
		}
		else
			setCenter(game.getMousePosition().x, hit_line + getFrameHeight() / 2);
	}
	delta_x = center().x - latest_pos;

	if (drunk)
	{
		drunk--;
		if(!drunk)
			game.setMousePosition(center().x, center().y);
	}
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

bool Player::haveRocket() const
{
	return have_rocket;
}

void Player::setHaveRocket(bool status)
{
	have_rocket = status;
}

void Player::applyBeer()
{
	drunk = 420;
}

int Player::getWidthByName(const std::string & texture_name) const
{
	if (texture_name == "paddle.png")
		return 120;
	if (texture_name == "bread.png" || texture_name == "catpad2.png" || texture_name == "crocodile.png")
		return 200;
	return 120;
}

int Player::getHeightByName(const std::string & texture_name) const
{
	if (texture_name == "paddle.png")
		return 15;
	if (texture_name == "bread.png")
		return 30;
	if (texture_name == "catpad2.png")
		return 37;
	if (texture_name == "crocodile.png")
		return 62;
	return 0;
}

int Player::getHitlineByName(const std::string & texture_name) const
{
	if (texture_name == "paddle.png")
		return 590;
	if (texture_name == "bread.png")
		return 580;
	if (texture_name == "catpad2.png")
		return 575;
	if (texture_name == "crocodile.png")
		return 575;
	return 590;
}
