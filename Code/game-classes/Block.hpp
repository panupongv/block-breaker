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

//Normal block, unbreakable
class Block : public Sprite
{
public:
	Block(const BlockData& block_data, bool endless = false);
    Block(std::string texture_name, float x, float y, bool endless = false);
	Block(BlockType type, float x, float y, bool endless = false);
   
	//Gameplay
	void update(Game& game);

	//Action when hitted by ball
	virtual void hitAction(Game& game);
	
	//Manage move speed(by frame)
	int getFrameToMove() const;
	void setFrameToMove(int frame_num);

	//Block type
	virtual BlockType getBlockType() const;
	//Return string of texture file to match type
	static std::string getTextureNameFromType(BlockType type);

public:
	//Size
	static constexpr int block_size_x = 50; 
	static constexpr int block_size_y = 18; 

	static constexpr int move_speed = 1;

private:
	//Set moving points
	void initializeMovementData(std::vector<sf::Vector2i> points);
	
private:
	//Mode specifier
	bool moving;
	bool endless = false;

	//Location points(if moving)
	sf::Vector2u first_point;
	sf::Vector2u second_point;

	//Frame counter for moving
	int frame_to_move;
	int frame_passed = 0;
};

//Break when hit
class BreakableBlock : public Block
{
public:
	BreakableBlock(const BlockData& block_data, bool endless = false);
	BreakableBlock(std::string texture_name, float x, float y, bool endless = false);

	void hitAction(Game& game);
	BlockType getBlockType() const;
};

//Break and create item when hit
class ItemBlock : public BreakableBlock
{
public:
	ItemBlock(const BlockData& block_data, bool endless = false);
	ItemBlock(std::string texture_name, float x, float y, bool endless = false);

	void hitAction(Game& game);
	BlockType getBlockType() const;
private:
	const int TYPE_NUM = 6;
	ItemType item_type;
};