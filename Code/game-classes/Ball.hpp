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
	void checkEdgeCollision(Game& game);
	void checkBlockCollision(Game& game);
	void checkPlayerCollision(Game& game);
	void launch();
	void accelerate();
private:
	float vxByAngle();
	float vyByAngle();
private:
	bool started;
	int y_direction;
	float speed = 5;
	float angle;
};
