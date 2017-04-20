#include "Item.hpp"

Item::Item(std::string texture_name, int frame_width, int frame_height, float x, float y)
	:
	Sprite(texture_name, frame_width, frame_height, 0, 0)
{
	int choice = rand() % 2;
	if (choice) setVX(-2);
	else setVX(2);
	setVY(-3);
	setCenter(x, y);
	std::cout << center().x << ", " << center().y << ", " << getVX() << ", " << getVY() << std::endl;
}

void Item::update(Game & game)
{
	move();
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
