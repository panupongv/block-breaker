#pragma once

#include "Sprite.hpp"
#include "Game.hpp"

class Game;
class Sprite;
class Block;

class Ball : public Sprite
{
public:
	Ball();
	void update(Game& game);
	void checkBlockCollision(Game& game);
	void checKPlayerCollision(Sprite* player);
	void launch();
private:
	bool started;
};
