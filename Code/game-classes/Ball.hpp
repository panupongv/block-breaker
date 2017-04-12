#pragma once

#include "Sprite.hpp"
#include "Game.hpp"
#include <cmath>

class Game;
class Sprite;
class Block;

class Ball : public Sprite
{
public:
	Ball();
	Ball(float x, float y);
	void update(Game& game);
	void checkBlockCollision(Game& game);
	void checkPlayerCollision(Game& game);
	void launch();
	void accelerate();
private:
	bool started;
	float launch_speed_x = 3;
	float launch_speed_y = -5;
};
