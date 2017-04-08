#pragma once

#include "Game.hpp"
#include "Sprite.hpp"
#include "BlockData.hpp"

//class Sprite;
class Game;
class Ball;

class Block : public Sprite
{
public:
    Block(std::string texture_name, const BlockData& block_data);
    Block(std::string texture_name, float x, float y, bool endless = false);
	Block(const BlockData& block_data);
	Block(BlockType type, float x, float y);
    
	void update(Game& game);

    void setGridPosition(int x, int y);
    static sf::Vector2i getBlockSize();

protected:
    std::string getTextureNameFromType(BlockType type);
    static const int block_size_x = 50; //Just Assume
    static const int block_size_y = 18;  //

private:
	bool endless = false;

	sf::Vector2u first_point;
	sf::Vector2u second_point;

    float move_speed = 0.1f;

	void initializeData(vector<sf::Vector2i> points);
};