#include "Ball.hpp"

Ball::Ball()
	:
	Sprite("ball.png", 20, 20, 0, 0),
	angle((rand() % 60) - 30),
	//angle(90),
	started(false)
{
		//Sprite::Sprite("ball.png", 70, 70, 250, 500);
	setAlive(true);
	setMoving(true);
}

Ball::Ball(float x, float y)
	:
	Ball()
{
	setCenter(x, y);
	launch();
}

void Ball::update(Game& game)
{
	if (started)
	{
		move(getVX(), getVY());
		checkEdgeCollision(game);
		checkBlockCollision(game);
		checkPlayerCollision(game);
	}
	else
	{ 
		setCenter(game.getMousePosition().x, game.getPlayer()->top() - getFrameHeight()/2 + 1);
	}
}

void Ball::checkEdgeCollision(Game & game)
{
	if ((left() <= game.left_bound && getVX() < 0) || (right() >= game.right_bound && getVX() > 0))
	{
		//angle = 180 - angle;
		setMovement(-getVX(), getVY());
		std::cout << (angle *= -1) << std::endl;
	}
	if ((top() <= game.upper_bound && getVY() < 0))
	{
		//angle = ((90 + abs(angle)) + 90) * angle / abs(angle);
		//setMovement(vxByAngle(), vyByAngle());
		y_direction = 1;
		setMovement(getVX(), -getVY());
	}
	if (top() > game.lower_bound)
		game.pop(this);
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
				//angle = ((90 + abs(angle)) + 90) * angle / abs(angle);
				//angle = 180 - angle;
				//setMovement(vxByAngle(), vyByAngle());
				setMovement(getVX(), -getVY());
				y_direction *= -1;
			}
			else if(collideHorizontally(*block_list[i]))
			{
				//angle = 180 - angle;
				//setMovement(vxByAngle(), vyByAngle());
				setMovement(-getVX(), getVY());
				angle *= -1;
			}
			block_list[i]->hitAction(game);
			break;
		}
	}
}

void Ball::checkPlayerCollision(Game& game)
{
	Player* player = game.getPlayer();
	if (bottom() >= player->getHitLine() && getVY() > 0)
	{
		switch (player->getHitZone(center().x))
		{
		case 1: 
		{
			y_direction = -1;
			angle = -60; setMovement(vxByAngle(), vyByAngle()); 
		}break;
		case 2:
		{
			y_direction = -1;
			angle = -30; setMovement(vxByAngle(), vyByAngle());
		}break;
		case 3:
		{
			y_direction = -1;
			setMovement(getVX(), -getVY());
		}break;
		case 4:
		{
			y_direction = -1;
			angle = 0; setMovement(vxByAngle(), vyByAngle());
		}break;
		case 5: 
		{
			y_direction = -1;
			angle = 30; setMovement(vxByAngle(), vyByAngle());
		}break;
		case 6:
		{
			y_direction = -1;
			angle = 60; setMovement(vxByAngle(), vyByAngle());
		}break;
		default: break;
		}
		std::cout << angle << std::endl;
		/*switch (player->getHitZone(center().x))
		{
		case 1: setMovement(-abs(getVX() * 2), -(getVY() - 3));
			break;
		case 2: setMovement(getVX() - 6, -(getVY() * 1.1));
			break;
		case 3: setMovement(getVX(), -getVY());
			break;
		case 4: setMovement(getVX() + 6, -(getVY() *1.1));
			break;
		case 5: setMovement(abs(getVX() * 2), -(getVY() - 3));
			break;
		default: break;
		}*/
	}
}

void Ball::launch()
{
	if (!started)
	{
		started = true;
		y_direction = -1;
		setMovement(vxByAngle(), vyByAngle());
	}
}

void Ball::accelerate()
{

}

float Ball::vxByAngle()
{
	return speed * sin(angle * 3.14159f / 180.0f);
}
	
float Ball::vyByAngle()
{
	return speed * cos(angle * 3.14159f / 180.0f) * y_direction;
}

