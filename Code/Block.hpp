#pragma once

#include "Sprite.hpp"
#include "BlockData.hpp"

class Block : public Sprite
{
public:
    Block(const BlockData& block_data) : Block(getTextureNameFromType(block_data.getType()),block_data){};
    Block(std:: string texture_name, const BlockData& block_data);
	Block(std::string texture_name, float x, float y);
	void update();
	void checkCollision(); //Ball& ball
	void setGridPosition(int x, int y);
	static sf::Vector2u getBlockSize();
private:
	static constexpr int block_size_x = 100; //Just Assume
	static constexpr int block_size_y = 30;  //

	float move_speed = 0.1;
	bool moving;
    
    std::string getTextureNameFromType(BlockType type);
};