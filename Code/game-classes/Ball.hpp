#pragma once

#include "enums.hpp"
#include "Sprite.hpp"
#include "Game.hpp"
#include <cmath>

class Game;
class Sprite;

//Abstract
class Projectile : public Sprite
{
public:
	Projectile(std::string texture_name, int height, int width);
	virtual void launch(Game& game) = 0;
protected:
	bool started;
};

//Game ball
class Ball : public Projectile
{
public:
	Ball(bool random = true);
	Ball(float x, float y);

	void update(Game& game);
	void launch();
	void launch(Game& game);

	//Penetrating ball
	void marioBall();
	//No speed limit ball
	void fastBall();

private:
	//Calculate speed vector by angle
	float vxByAngle();
	float vyByAngle();

	//Collisions
	void checkEdgeCollision(Game& game);
	void checkBlockCollision(Game& game);
	void checkPlayerCollision(Game& game);
	
	//Increase speed
	void accelerate();

private:
	int mario;
	int fast;
	int hit_counter;
	int frame_counter;
	const int HIT_TO_ACCELERATE = 2;

	int y_direction;
	float speed = 6;
	float speed_limit = 12;
	float speed_record;
	float angle;
};

//Shootable rocket (not dropped item)
class ShotRocket : public Projectile
{
public:
	ShotRocket();
	void update(Game& game);
	void launch(Game& game);
};