#pragma once

#include "Sprite.hpp"

class Game;
class Player;

const int TYPE_NUM = 4;
enum ItemType {ADDBALL, MARIOBALL, MACHINEGUN, EXPLOSIVE};

class Item : public Sprite
{
public:
	Item(Block* block);
	void update(Game& game);
	void applyPower(Game& game);
private:
	ItemType type;
};
