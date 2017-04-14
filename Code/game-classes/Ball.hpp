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
	Ball(std::string texture_name = "ball.png", int width = 20, int height = 20, bool random = true);
	Ball(float x, float y);

	virtual void update(Game& game);
	virtual void launch();
	
	void marioBall();
private:
	float vxByAngle();
	float vyByAngle();

	void checkEdgeCollision(Game& game);
	void checkBlockCollision(Game& game);
	void checkPlayerCollision(Game& game);
	void accelerate();
private:
	bool started;
	int mario = 0;

	int hit_counter;
	int frame_counter;
	static constexpr int hit_to_accelerate = 2;

	int y_direction;
	float speed = 5;
	float speed_limit = 10;
	float angle;
};

class ShotRocket : public Ball
{
public:
	ShotRocket();
	void update(Game& game);
	void launch();
private:
	bool started;
};