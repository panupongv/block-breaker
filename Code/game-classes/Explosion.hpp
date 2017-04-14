#pragma once

#include "Sprite.hpp"
#include "Game.hpp"

class Game;

class Explosion: public Sprite
{
public:
	Explosion(float x, float y);
	void update(Game& game);
private:
	int frame_counter;
	const int frame_to_update = 3;
	const int frame_limit = 9;
};