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
private:
	int getWidthByName(const std::string& texture_name) const;
	int getHeightByName(const std::string& texture_name) const;
	int getHitlineByName(const std::string& texture_name) const;
private:
	bool have_rocket;
	const int hit_line;
	float latest_pos;
	float delta_x;
};