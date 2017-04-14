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
	void marioBall();
private:
	float vxByAngle();
	float vyByAngle();
private:
	bool started;
	int mario = 0;
	int hit_counter;
	static constexpr int hit_to_accelerate = 3;

	int y_direction;
	float speed = 5;
	float speed_limit = 10;
	float angle;
};
