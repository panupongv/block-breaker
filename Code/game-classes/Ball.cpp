#include "Ball.hpp"

Projectile::Projectile(std::string texture_name, int height, int width)
	:
	Sprite(texture_name, height, width),
	started(false)
{
}

Ball::Ball(bool random)
	:
	Projectile("ball.png", 20, 20),
	angle(((rand() % 80) - 40) * random),
	mario(0),
	fast(0),
	hit_counter(0),
	frame_counter(0),
	started(false)
{
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
			mario--;
			if (!mario) setFrame(0);
		}
		if (fast)
		{
			fast--;
			if (!fast)
			{
				speed = speed_record;
				setMovement(vxByAngle(), vyByAngle());
			}
		}
		else
		{
			if (speed < 5)
				speed = 5;
			if (speed > speed_limit)
				speed = speed_limit;
			setMovement(vxByAngle(), vyByAngle());
		}
		if (hit_counter >= hit_to_accelerate)
			accelerate();
	}
	else
	{ 
		setCenter(game.getPlayer()->center().x, game.getPlayer()->getHitLine() - getFrameHeight()/2 + 1);
	}
}


void Ball::checkEdgeCollision(Game & game)
{
	if ((left() <= game.left_bound && getVX() < 0) || (right() >= game.right_bound && getVX() > 0))
	{
		game.getSoundPlayer().playBounceSound();
		angle *= -1;
		setMovement(-getVX(), getVY());
	}
	if ((top() <= game.upper_bound && getVY() < 0))
	{
		game.getSoundPlayer().playBounceSound();
		y_direction = 1;
		setMovement(getVX(), -getVY());
	}
	if (top() > game.lower_bound)
		game.pop(this);
}

void Ball::checkBlockCollision(Game& game)
{
	std::vector<Block*> block_list = game.getBlockList();
	for (int i = 0; i < block_list.size(); i++)
	{
		float dx, dy;
		dx = block_list[i]->center().x - center().x;
		dy = block_list[i]->center().y - center().y;
		bool v_right = getVX() > 0, v_down = getVY() > 0;
		if (collide(*block_list[i]))
		{
			if (mario)
			{
				game.getSoundPlayer().playBreakableBlockSound();
				game.pop(block_list[i]);
				return;
			}
			else if (collideHorizontally(*block_list[i]) && ((dx > 0 && v_right == true) || (dx < 0 && v_right == false)))
			{
				move(-getVX(), 0);
				setMovement(-getVX(), getVY());
				angle *= -1;
			}
			else if (collideVertically(*block_list[i]) && ((dy > 0 && v_down == true) || (dy < 0 && v_down == false)))
			{
				move(0, -getVY());
				setMovement(getVX(), -getVY());
				y_direction *= -1;
			}
			game.getSoundPlayer().playBounceSound();
			block_list[i]->hitAction(game);
			return;
		}
	}
}

void Ball::checkPlayerCollision(Game& game)
{
	Player* player = game.getPlayer();
	if (bottom() >= player->getHitLine() && bottom() <= player->getHitLine() + player->getFrameHeight() * 0.75f && getVY() > 0)
	{
		y_direction = -1;
		switch (player->getHitZone(center().x))
		{
		case 1: 
		{
			angle = -60; setMovement(vxByAngle(), vyByAngle()); game.getSoundPlayer().playBounceSound();
		}break;
		case 2:
		{
			angle = -30; setMovement(vxByAngle(), vyByAngle()); game.getSoundPlayer().playBounceSound();
		}break;
		case 3:
		{
			setMovement(getVX(), -getVY()); game.getSoundPlayer().playBounceSound();
		}break;
		case 4:
		{
			angle = (static_cast<int>(angle) % 90) * 0.8f; setMovement(vxByAngle(), vyByAngle()); game.getSoundPlayer().playBounceSound();
		}break;
		case 5: 
		{
			angle = 30; setMovement(vxByAngle(), vyByAngle()); game.getSoundPlayer().playBounceSound();
		}break;
		case 6:
		{
			angle = 60; setMovement(vxByAngle(), vyByAngle()); game.getSoundPlayer().playBounceSound();
		}break;
		default: y_direction = 1;
			break;
		}
		if (y_direction == -1)
		{
			hit_counter++;
			setVX(getVX() + player->getDeltaX() / 6.0f);
		}
		speed = sqrt(pow(getVX(), 2) + pow(getVY(), 2));
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

void Ball::launch(Game& game)
{
	if(!started)
		game.getSoundPlayer().playBallLaunchSound();
	launch();
}

void Ball::accelerate()
{
	if (speed < speed_limit)
		speed += 0.1f;
	setMovement(vxByAngle(), vyByAngle());
	hit_counter = 0;
}

void Ball::marioBall()
{
	mario = 180;
}

void Ball::fastBall()
{
	fast = 300;
	speed_record = speed;
	speed = 15;
	setMovement(vxByAngle(), vyByAngle());
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
	Projectile("rocket.png", 50, 126)
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
		if (bottom() < game.upper_bound)
		{
			game.pop(this);
			return;
		}
		std::vector<Block*> block_list = game.getBlockList();
		for (int i = 0; i < block_list.size(); i++)
		{
			if (collide(*block_list[i]))
			{
				game.add(new Explosion(game, center().x, center().y));
				game.pop(this);
				break;
			}
		}
	}
	else
	{
		setCenter(game.getPlayer()->center().x, game.getPlayer()->top() + 23);
	}
}

void ShotRocket::launch(Game& game)
{
	if (!started)
	{
		started = true;
		game.getSoundPlayer().playRocketLaunchSound();
	}
}

