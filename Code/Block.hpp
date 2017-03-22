#pragma once

#include "Sprite.hpp"
#include "BlockData.hpp"

class Block : public Sprite
{
public:
    Block(std::string texture_name, const BlockData& block_data);
    Block(std::string texture_name, float x, float y);
    Block(const BlockData& block_data);
    Block(BlockType type , float x , float y);
    
    virtual void update();
    void checkCollision(); //Ball& ball
    void setGridPosition(int x, int y);
    static sf::Vector2u getBlockSize();

protected:
    std::string getTextureNameFromType(BlockType type);
    static constexpr int block_size_x = 100; //Just Assume
    static constexpr int block_size_y = 30;  //

private:
	sf::Vector2u first_point;
	sf::Vector2u second_point;

    float move_speed = 0.1;
    bool moving;
};