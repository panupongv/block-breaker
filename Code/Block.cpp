#include "Block.hpp"

Block::Block(std::string texture_name, const BlockData & block_data)
:
	Sprite(texture_name, block_size_x, block_size_y,
       block_data.getStartGrid().x * block_size_x, block_data.getStartGrid().y * block_size_y)
{
	initializeData(block_data.getMovement());
	getSprite().setColor(block_data.getColor());
}

Block::Block(std::string texture_name, float x, float y, bool endless)
: Sprite(texture_name, block_size_x, block_size_y, x , y ) 
{
	if (endless)
	{
		this->endless = true;
	}
}

Block::Block(const BlockData & block_data)
	:
	Block(getTextureNameFromType(block_data.getType()), block_data.getStartGrid().x * block_size_x, block_data.getStartGrid().y * block_size_y)
{
}

Block::Block(BlockType type, float x, float y)
	:
	Block(getTextureNameFromType(type), x, y)
{
}

void Block::update(Game& game)
{
	if (!endless)
	{
		if (!moving) return;
		move(getVX(), getVY());
		if ((left() >= second_point.x && getVX() > 0) || (left() <= first_point.x && getVX() < 0)
			|| (top() >= second_point.y && getVY() > 0) || top() <= first_point.y && getVY() < 0)
		{
			setMovement(-getVX(), -getVY());
			//std::cout << "bounce" << std::endl;
		}
	}
	else
	{
		move(0, 0.1f);
	}
}

//void Block::checkCollision() //Ball& ball
//{
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

//}

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

sf::Vector2i Block::getBlockSize()
{
	return sf::Vector2i(block_size_x, block_size_y);
}


std::string Block::getTextureNameFromType(BlockType type)
{
    switch (type) {
        case normal:
            return "brick.png";
        case item:
            return "kuy item";
        case breakable :
            return "breakable kuy";
        default:
            return "";
    }
}

void Block::initializeData(vector<sf::Vector2i> points)
{
	alive = true;
	if (points.size() != 0)
	{
		sf::Vector2i point1 = points[0], point2 = points[1];
		float vx = 0, vy = 0;
		if (point1.x != point2.x) //move horizontally
		{
			if (point1.x < point2.x) //right first
			{
				first_point = sf::Vector2u(point1.x * block_size_x, point1.y * block_size_y);
				second_point = sf::Vector2u(point2.x * block_size_x, point2.y * block_size_y);
				vx = move_speed;
			}
			else // left first
			{
				first_point = sf::Vector2u(point2.x * block_size_x, point2.y * block_size_y);
				second_point = sf::Vector2u(point1.x * block_size_x, point1.y * block_size_y);
				vx = -move_speed;
			}
			vy = 0;
		}
		else if (point1.y != point2.y) // move vertically
		{

			if (point1.y < point2.y) //down first
			{
				first_point = sf::Vector2u(point1.x * block_size_x, point1.y * block_size_y);
				second_point = sf::Vector2u(point2.x * block_size_x, point2.y * block_size_y);
				vy = move_speed;
			}
			else //up first
			{
				first_point = sf::Vector2u(point2.x * block_size_x, point2.y * block_size_y);
				second_point = sf::Vector2u(point1.x * block_size_x, point1.y * block_size_y);
				vx = -move_speed;
			}
			vx = 0;
		}
		setMovement(vx, vy);
		moving = true;
	}
	else
	{
		first_point = second_point = sf::Vector2u(left(), top());
		moving = false;
		setMovement(0, 0);
	}
}

