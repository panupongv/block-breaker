#include "Ball.hpp"

Ball::Ball()
	:
	Sprite("ball.png", 20, 20, 0, 0),
	started(false)
{
		//Sprite::Sprite("ball.png", 70, 70, 250, 500);
	setAlive(true);
	setMoving(true);
}

void Ball::update(Game& game)
{
	if (started)
	{
		move(getVX(), getVY());
		//Collide with edges
		if ((left() <= game.left_bound && getVX() < 0) || (right() >= game.right_bound && getVX() > 0))
			setMovement(-getVX(), getVY());
		if ((top() <= game.upper_bound && getVY() < 0) || (bottom() >= game.lower_bound && getVY() > 0))
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
	std::vector<Block*> block_list = game.getBlockList();
	const int list_size = block_list.size();
	for (int i = 0; i < list_size; i++)
	{
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
			block_list[i]->hitAction(game);
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
	setMovement(3, -5);
}
