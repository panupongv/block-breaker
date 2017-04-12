#pragma once

#include "Sprite.hpp"
#include "Game.hpp"

class Game;

class Player : public Sprite
{
public:
	Player();
	void update(Game& game);
	int getHitLine() const;
	int getHitZone(float x) const;
private:
	unsigned int status;
	const int hit_line = 590;
};