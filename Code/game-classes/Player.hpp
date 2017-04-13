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
private:
	int getWidthByName(const std::string& texture_name) const;
	int getHeightByName(const std::string& texture_name) const;
	int getHitlineByName(const std::string& texture_name) const;
private:
	unsigned int status;
	const int hit_line;
};