#pragma once

#include "Sprite.hpp"
#include "Game.hpp"
#include <cstdlib>

class Game;
class Player;

//Item's abstract
class Item : public Sprite
{
public:
	Item(std::string texture_name, int frame_width, int frame_height, float x, float y);
	void update(Game& game);

	//Apply power to game's attribute when collected
	virtual void applyPower(Game& game) = 0;
private:
	const float gravity = 0.25;
};

//Mario ball (penetrating ball)
class Star : public Item
{
public:
	Star(float x, float y);
	void applyPower(Game& game);
};

//Provide player shootable rocket
class Rocket : public Item
{
public:
	Rocket(float x, float y);
	void applyPower(Game& game);
};

//No speed for all balls
class FastForward : public Item
{
public:
	FastForward(float x, float y);
	void applyPower(Game& game);
};

//Drunk player (reverse control)
class Beer : public Item
{
public:
	Beer(float x, float y);
	void applyPower(Game& game);
};
