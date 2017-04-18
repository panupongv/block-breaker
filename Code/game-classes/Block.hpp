#pragma once

#include "Game.hpp"
#include "Sprite.hpp"
#include "Item.hpp"
#include "Explosion.hpp"
#include "BlockData.hpp"

class Sprite;
class Game;
class Ball;
class Item;

const int TYPE_NUM = 4;
enum ItemType { ADDBALL, MARIOBALL, MACHINEGUN, EXPLOSIVE };

class Block : public Sprite
{
public:
	Block(const BlockData& block_data, bool endless = false);
    Block(std::string texture_name, float x, float y, bool endless = false);
	Block(BlockType type, float x, float y, bool endless = false);
   
	void update(Game& game);
	virtual void hitAction(Game& game);
	static std::string getTextureNameFromType(BlockType type);
	virtual BlockType getBlockType() const;
	int getFrameToMove() const;
	void setFrameToMove(int frame_num);
public:
	static constexpr int block_size_x = 50; //Just Assume
	static constexpr int block_size_y = 18;  //
	static constexpr int move_speed = 1;
protected:
	int frame_to_move; //20
	int frame_passed = 0;
	void initializeData(std::vector<sf::Vector2i> points);

private:
	bool endless = false;
	sf::Vector2u first_point;
	sf::Vector2u second_point;
};

class BreakableBlock : public Block
{
public:
	BreakableBlock(const BlockData& block_data, bool endless = false);
	BreakableBlock(std::string texture_name, float x, float y, bool endless = false);

	virtual void hitAction(Game& game);
	BlockType getBlockType() const;
};

class ItemBlock : public BreakableBlock
{
public:
	ItemBlock(const BlockData& block_data, bool endless = false);
	ItemBlock(std::string texture_name, float x, float y, bool endless = false);

	void hitAction(Game& game);
	BlockType getBlockType() const;
private:
	ItemType item_type;
};