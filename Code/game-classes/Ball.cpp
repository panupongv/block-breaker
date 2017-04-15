#include "Ball.hpp"

Ball::Ball(std::string texture_name, int width, int height, bool random)
	:
	Sprite(texture_name, width, height, 0, 0),
	angle(((rand() % 60) - 30) * random),
	hit_counter(0),
	frame_counter(0),
	started(false)
{
		//Sprite::Sprite("ball.png", 70, 70, 250, 500);
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
		if (mario)
		{
			frame_counter++;
			if (frame_counter == 5)
			{
				frame_counter = 0;
				nextFrame();
			}
		}
		if (hit_counter >= hit_to_accelerate)
			accelerate();
	}
	else
	{ 
		setCenter(game.getMousePosition().x, game.getPlayer()->getHitLine() - getFrameHeight()/2 + 1);
	}
}

void Ball::checkEdgeCollision(Game & game)
{
	if ((left() <= game.left_bound && getVX() < 0) || (right() >= game.right_bound && getVX() > 0))
	{
		angle *= -1;
		setMovement(-getVX(), getVY());
		hit_counter++;
	}
	if ((top() <= game.upper_bound && getVY() < 0))
	{
		//angle = ((90 + abs(angle)) + 90) * angle / abs(angle);
		//setMovement(vxByAngle(), vyByAngle());
		y_direction = 1;
		setMovement(getVX(), -getVY());
		hit_counter++;
	}
	if (top() > game.lower_bound)
		game.pop(this);
}

void Ball::checkBlockCollision(Game& game)
{
	std::vector<Block*> block_list = game.getBlockList();
	for (int i = 0; i < block_list.size(); i++)
	{
		if (collide(*block_list[i]))
		{
			if (mario)
			{
				game.pop(block_list[i]);
				mario--;
				if (!mario) setFrame(0);
				hit_counter++;
				return;
			}
			else if (collideVertically(*block_list[i]))
			{
				setMovement(getVX(), -getVY());
				y_direction *= -1;
			}
			else if(collideHorizontally(*block_list[i]))
			{
				setMovement(-getVX(), getVY());
				angle *= -1;
			}
			hit_counter++;
			block_list[i]->hitAction(game);
			return;
		}
	}
}

void Ball::checkPlayerCollision(Game& game)
{
	Player* player = game.getPlayer();
	if (bottom() >= player->getHitLine() && bottom() <= player->getHitLine() + player->getFrameHeight() / 2.0f && getVY() > 0)
	{
		y_direction = -1;
		switch (player->getHitZone(center().x))
		{
		case 1: 
		{
			angle = -60; setMovement(vxByAngle(), vyByAngle()); 
		}break;
		case 2:
		{
			angle = -30; setMovement(vxByAngle(), vyByAngle());
		}break;
		case 3:
		{
			setMovement(getVX(), -getVY());
		}break;
		case 4:
		{
			angle = (static_cast<int>(angle) % 90) * 0.75f; setMovement(vxByAngle(), vyByAngle());
		}break;
		case 5: 
		{
			angle = 30; setMovement(vxByAngle(), vyByAngle());
		}break;
		case 6:
		{
			angle = 60; setMovement(vxByAngle(), vyByAngle());
		}break;
		default: y_direction = 1;
			break;
		}
		if (y_direction == -1)
		{
			hit_counter++;
			setVX(getVX() + player->getDeltaX() / 5.0f);
		}
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
	if (speed < speed_limit)
		speed += 0.1f;
	hit_counter = 0;
}

void Ball::marioBall()
{
	mario = 5;
}

float Ball::vxByAngle()
{
	return speed * sin(angle * 3.14159f / 180.0f);
}
	
float Ball::vyByAngle()
{
	return speed * cos(angle * 3.14159f / 180.0f) * y_direction;
}

ShotRocket::ShotRocket()
	:
	Ball("rocket.png", 50, 126, false)
{
	started = false;
	setMovement(0, -1);
}

void ShotRocket::update(Game & game)
{
	if (started)
	{
		move();
		if(getVY() * 1.2 < 18)
			setVY(getVY() * 1.2);
		std::vector<Block*> block_list = game.getBlockList();
		if (bottom() < game.upper_bound)
			game.pop(this);
		for (int i = 0; i < block_list.size(); i++)
		{
			if (collide(*block_list[i]))
			{
				game.add(new Explosion(center().x, center().y));
				game.pop(this);
				break;
			}
		}
	}
	else
	{
		setCenter(game.getMousePosition().x, game.getPlayer()->top() + 23);
	}
}

void ShotRocket::launch()
{
	if (!started) started = true;
}
