#include "Ball.hpp"

Ball::Ball()
	:
	Sprite("ball.png", 50, 50, 0, 0),
	started(false)
{
		//Sprite::Sprite("ball.png", 70, 70, 250, 500);
	alive = true;
	moving = true;
}

void Ball::update(Game& game)
{
	if (started)
	{
		move(getVX(), getVY());
		//Collide with edges
		if ((left() <= 0 && getVX() < 0) || (right() >= game.getWindowSize().x && getVX() > 0))
			setMovement(-getVX(), getVY());
		if ((top() <= 0 && getVY() < 0) || (bottom() >= game.getWindowSize().y && getVY() > 0))
			setMovement(getVX(), -getVY());
		checkBlockCollision(game);
		checkPlayerCollision(game.getPlayer());

	}
	else
	{ 
		setCenter(game.getMousePosition().x, game.getMousePosition().y);
	}
}

void Ball::checkBlockCollision(Game& game)
{
	vector<Sprite*> block_list = game.getBlockList();
	const int list_size = block_list.size();
	for (int i = 0; i < list_size; i++)
	{
		if (!block_list[i]->isAlive()) continue;
		if (collide(*block_list[i]))
		{
			
			//block_list[i]->inactivate();
			if (collideVertically(*block_list[i]))
			{
				move(0, -getVY());
				setMovement(getVX(), -getVY());
			}
			else
			{
				move(-getVX(), 0);
				setMovement(-getVX(), getVY());
			}
			game.popBlock(block_list[i]);
		}
	}
}

void Ball::checkPlayerCollision(Sprite* player)
{

	if (collideVertically(*player))
	{
		move(0, -getVY());
		setMovement(getVX(), -getVY());
	}
	else if (collideHorizontally(*player))
	{
		move(-getVX(), 0);
		setMovement(-getVX(), getVY());
	}
}

void Ball::launch()
{
	started = true;
	setMovement(10, -15);
}
