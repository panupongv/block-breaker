#pragma once

#include "Sprite.hpp"

class Block : public Sprite
{
public:
	Block(std::string texture_name, int grid_x, int grid_y);
	void update();
	void checkCollision(); //Ball& ball
	void setGridPosition(int x, int y);
	static sf::Vector2u getBlockSize();
private:
	static constexpr int block_size_x = 100; //Just Assume 
	static constexpr int block_size_y = 30;  //
};