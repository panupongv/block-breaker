#pragma once

#include "Sprite.hpp"
#include "Game.hpp"
#include <cstdlib>

class Game;
class Player;

class Item : public Sprite
{
public:
	Item(std::string texture_name, int frame_width, int frame_height, float x, float y);
	void update(Game& game);
	virtual void applyPower(Game& game) = 0;
private:
	const float gravity = 0.25;
};

class Star : public Item
{
public:
	Star(float x, float y);
	void applyPower(Game& game);
};

class Rocket : public Item
{
public:
	Rocket(float x, float y);
	void applyPower(Game& game);
};
