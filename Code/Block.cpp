#include "Block.hpp"

Block::Block(const BlockData & block_data)
:
Block(getTextureNameFromType(block_data.getType()),block_data) {}

Block::Block(std::string texture_name, const BlockData & block_data)
:
Sprite(texture_name, block_size_x, block_size_y,
       block_data.getStartGrid().x * block_size_x, block_data.getStartGrid().y * block_size_y)
{
    if (block_data.getMovement().size() != 0)
    {
        sf::Vector2i point1 = block_data.getMovement()[0], point2 = block_data.getMovement()[1];
        moving = true;
        float vx = 0, vy = 0;
        if (point1.x != point2.x)
        {
            vx = move_speed; //Speed
            vy = 0;
        }
        else if (point1.y != point2.y)
        {
            vx = 0;
            vy = move_speed;
        }
        setMovement(vx, vy);
    }
    else
    {
        moving = false;
        setMovement(0, 0);
    }
    
    getSprite().setColor(block_data.getColor());
}

Block::Block(std::string texture_name, float x, float y)
	:
	Sprite(texture_name, block_size_x, block_size_y, x , y )
{
}

void Block::update()
{
	move(getVX(), getVY());

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


std::string getTextureNameFromType(BlockType type)
{
    switch (type) {
        case normal:
            return "normal kuy";
        case item:
            return "kuy item";
        case breakable :
            return "breakable kuy";
        default:
            return "";
    }
}
