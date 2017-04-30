#pragma once

#include "Sprite.hpp"
#include "Game.hpp"

class Game;

class Player : public Sprite
{
public:
	Player(std::string texture_name = "paddle.png");
	void update(Game& game);
	int getHitLine() const;
	int getHitZone(float x) const;
	float getDeltaX() const;
	bool haveRocket() const;
	void setHaveRocket(bool status);
	void applyBeer();
private:
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