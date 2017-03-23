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
		checKPlayerCollision(game.getPlayer());

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
		if (getSprite().getGlobalBounds().intersects(block_list[i]->getSprite().getGlobalBounds()))
		{

			block_list[i]->inactivate();
			game.removeBlock();
			if (center().x > block_list[i]->left() && center().x < block_list[i]->right())
			{
				move(0, -getVY());
				setMovement(getVX(), -getVY());
			}
			else
			{
				move(-getVX(), 0);
				setMovement(-getVX(), getVY());
			}

		}
	}
}

void Ball::checKPlayerCollision(Sprite* player)
{
	if (getSprite().getGlobalBounds().intersects(player->getSprite().getGlobalBounds()))
	{
		if (center().x > player->left() && center().x < player->right())
		{
			move(0, -getVY());
			setMovement(getVX(), -getVY());
		}
		else
		{
			move(-getVX(), 0);
			setMovement(-getVX(), getVY());
		}
	}
}

void Ball::launch()
{
	started = true;
	setMovement(0.125f, -0.2f);
}
