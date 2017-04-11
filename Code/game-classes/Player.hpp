#pragma once

#include "Sprite.hpp"
#include "Game.hpp"

class Game;

class Player : public Sprite
{
public:
	Player();
	void update(Game& game);
//private:
};