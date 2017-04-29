#pragma once

#include "enums.hpp"
#include "Sprite.hpp"
#include "Game.hpp"
#include <cmath>

class Game;
class Sprite;
class Block;

class Projectile : public Sprite
{
public:
	Projectile(std::string texture_name, int height, int width);
	virtual void update(Game& game) = 0;
	virtual void launch(Game& game) = 0;
protected:
	bool started;
};

class Ball : public Projectile
{
public:
	Ball(bool random = true);
	Ball(float x, float y);

	virtual void update(Game& game);
	void launch();
	void launch(Game& game);

	void marioBall();
	void accelerate();
private:
	float vxByAngle();
	float vyByAngle();

	void checkEdgeCollision(Game& game);
	void checkBlockCollision(Game& game);
	void checkPlayerCollision(Game& game);
private:
	bool started;

	int mario = 0;
	int hit_counter;
	int frame_counter;
	static constexpr int hit_to_accelerate = 2;

	int y_direction;
	float speed = 6;
	float speed_limit = 12;
	float angle;
};

class ShotRocket : public Projectile
{
public:
	ShotRocket();
	void update(Game& game);
	void launch(Game& game);
private:
	bool started;
};