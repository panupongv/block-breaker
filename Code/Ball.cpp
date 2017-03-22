#include "Ball.hpp"

Ball::Ball()
	:
	Sprite("ball.png", 75, 75, 0, 0),
	started(false)
{
	//Sprite::Sprite("ball.png", 70, 70, 250, 500);
	getSprite().scale(50.0f / 75, 50.0f / 75);
}

void Ball::update(Game& game)
{
	if (started)
	{
		move(getVX(), getVY());
		//Collision with edges
		if ((left() <= 0 && getVX() < 0) || (right() >= 600 && getVX() > 0))
			setMovement(-getVX(), getVY());
		if ((top() <= 0 && getVY() < 0) || (bottom() >= 600 && getVY() > 0))
			setMovement(getVX(), -getVY());
	}
	else
	{
		setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
	}
}

void Ball::launch()
{
	started = true;
	setMovement(0.125, 0.2);
}
