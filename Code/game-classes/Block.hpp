#pragma once

#include "Game.hpp"
#include "Sprite.hpp"
#include "BlockData.hpp"

class Sprite;
class Game;
class Ball;

class Block : public Sprite
{
public:
	Block(const BlockData& block_data, bool endless = false);
    Block(std::string texture_name, float x, float y, bool endless = false);
	Block(BlockType type, float x, float y, bool endless = false);
    
	void update(Game& game);
	virtual void hitAction(Game& game);

	static int getFrameToMove();
	static std::string getTextureNameFromType(BlockType type);
public:
	static constexpr int block_size_x = 50; //Just Assume
	static constexpr int block_size_y = 18;  //
	static constexpr int move_speed = 1;
	static constexpr int frame_to_move = 5;
protected:
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
};

class ItemBlock : public BreakableBlock
{
public:
	ItemBlock(const BlockData& block_data, bool endless = false);
	ItemBlock(std::string texture_name, float x, float y, bool endless = false);

	void hitAction(Game& game);
};