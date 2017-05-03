#pragma once

#include "Sprite.hpp"
#include "Game.hpp"

class Game;

class Player : public Sprite
{
public:
	Player(std::string texture_name = "paddle.png");
	void update(Game& game);

	//Player's upper bound 
	int getHitLine() const;

	//Part of ball collision (for further calculation in Ball class)
	int getHitZone(float x) const;

	//Displacement of x in current frame
	float getDeltaX() const;

	//Item flag status
	bool haveRocket() const;
	void setHaveRocket(bool status);
	bool isDrunk() const;
	void applyBeer();
private:
	//Initializing helper functions
	int getWidthByName(const std::string& texture_name) const;
	int getHeightByName(const std::string& texture_name) const;
	int getHitlineByName(const std::string& texture_name) const;
private:
	bool have_rocket;
	int drunk;

	const int hit_line;
	float center_line;
	float latest_pos;
	float delta_x;
};