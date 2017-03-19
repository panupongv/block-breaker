#include "Block.hpp"

Block::Block(std::string texture_name, float x, float y)
	:
	Sprite(texture_name, block_size_x, block_size_y, x , y )
{
}

Block::Block(std::string texture_name, const BlockData & block_data)
	:
	Sprite(texture_name, block_size_x, block_size_y,
		   block_data.getStartGrid().x * block_size_x, block_data.getStartGrid().y * block_size_y)
{
	getSprite().setColor(block_data.getColor());
	if (block_data.getMovement().size() != 0)
	{
		moving = true;
	}
}

void Block::update()
{

}

void Block::checkCollision() //Ball& ball
{
	//Praman nee
	//Corner bounce diew kid eek tee

	/*if(ball.right() >= left() && ball.left() <= right())
	{
		if (ball.top() <= bottom() || ball.bottom() >= top())
			ball.bounceVertically();
	}
	
	if (ball.top() <= top() && ball.bottom >= bottom())
	{
		if (ball.left() < right() || ball.right > left())
			ball.bounceHorizontally();
	}*/

}

void Block::setGridPosition(int x, int y)
{
	if (static_cast<int> (top()) % static_cast<int> (block_size_y) != 0)
	{
		//use floor or ceil to match grid
	}
	if (static_cast<int> (left()) % static_cast<int> (block_size_x) != 0)
	{
		//use floor or ceil to match grid
	}
}

sf::Vector2u Block::getBlockSize()
{
	return sf::Vector2u(block_size_x, block_size_y);
}
