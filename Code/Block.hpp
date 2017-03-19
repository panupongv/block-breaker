#pragma once

#include "Sprite.hpp"
#include "BlockData.hpp"

class Block : public Sprite
{
public:
	Block(std::string texture_name, int grid_x, int grid_y);
	Block(std::string texture_name, const BlockData& block_data);
	void update();
	void checkCollision(); //Ball& ball
	void setGridPosition(int x, int y);
	static sf::Vector2u getBlockSize();
private:
	static constexpr int block_size_x = 100; //Just Assume 
	static constexpr int block_size_y = 30;  //

	bool moving;
};