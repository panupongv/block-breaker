#pragma once

#include "Sprite.hpp"
#include "Game.hpp"
#include "Player.hpp"

class Game;
class Player;

class Item : public Sprite
{
public:
	Item(Game& game, Block* block);
	void update(Game& game);
	virtual void applyPower(Player* player);
};
