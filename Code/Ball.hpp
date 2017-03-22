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
	void launch();
private:
	bool started;
};
