#include "Item.hpp"

Item::Item(std::string texture_name, int frame_width, int frame_height, float x, float y)
	:
	Sprite(texture_name, frame_width, frame_height, 0, 0)
{
	setVX((rand() % 7) - 3);
	setVY(-3);
	setCenter(x, y);
}

void Item::update(Game & game)
{
	move();
	if (top() < game.upper_bound && getVY() > 0)
		setVY(0);
	if (left() < game.left_bound && getVX() < 0 || right() > game.right_bound && getVX() > 0)
		setVX(-getVX());
	if (collide(*(game.getPlayer())))
	{
		applyPower(game);
		game.pop(this);
	}
	if (top() > game.lower_bound)
		game.pop(this);
	setVY(getVY() + gravity);
}

Star::Star(float x, float y)
	:
	Item("star.png", 40, 40, x, y)
{
}

void Star::applyPower(Game & game)
{
	game.applyMarioBall();
}

Rocket::Rocket(float x, float y)
	:
	Item("rocket_item.png", 40, 40, x, y)
{
}

void Rocket::applyPower(Game & game)
{
	if (!game.getPlayer()->haveRocket())
	{
		game.add(new ShotRocket());
		game.getPlayer()->setHaveRocket(true);
	}
}

FastForward::FastForward(float x, float y)
	:
	Item("fast.png", 40, 40, x, y)
{
}

void FastForward::applyPower(Game & game)
{
	game.applyFastBall();
}

Beer::Beer(float x, float y)
	:
	Item("beer.png", 40, 40, x, y)
{
}

void Beer::applyPower(Game & game)
{
	game.applyDrunkPlayer();
}
