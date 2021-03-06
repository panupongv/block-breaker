#include "Block.hpp"

Block::Block(const BlockData& block_data, bool endless)
	: 
	Block(getTextureNameFromType(block_data.getType()), block_data.getStartGrid().x * block_size_x, block_data.getStartGrid().y * block_size_y)
{
	setColor(block_data.getColor());
	initializeMovementData(block_data.getMovement());
}

Block::Block(std::string texture_name, float x, float y, bool endless)
: Sprite(texture_name, block_size_x, block_size_y, x , y ),
  endless(endless)
{
	if (endless)
		frame_to_move = 20;
	else
		frame_to_move = 5;
}

Block::Block(BlockType type , float x , float y, bool endless)
: Block(getTextureNameFromType(type),x,y,endless)
{ 
}

void Block::update(Game& game)
{
	if (frame_passed >= frame_to_move)
	{
		if (!endless)
		{
			move();
			if ((left() >= second_point.x && getVX() > 0) || (left() <= first_point.x && getVX() < 0)
				|| (top() >= second_point.y && getVY() > 0) || top() <= first_point.y && getVY() < 0)
			{
				setMovement(-getVX(), -getVY());
			}
		}
		else
		{
			move(0, move_speed);
		}
		frame_passed = 0;
	}
	frame_passed++;

}

void Block::hitAction(Game & game)
{
	game.getSoundPlayer().playNormalBlockSound();
}

std::string Block::getTextureNameFromType(BlockType type)
{
    switch (type) {
        case normal:
            return "normal.png";
        case breakable:
            return "breakable.png";
        case item :
            return "item.png";
        default:
            return "";
    }
}

BlockType Block::getBlockType() const
{
	return normal;
}

int Block::getFrameToMove() const
{
	return frame_to_move;
}

void Block::setFrameToMove(int frame_num)
{
	if(frame_num >= 1)
		frame_to_move = frame_num;
}

void Block::initializeMovementData(std::vector<sf::Vector2i> points)
{
	if(points.size() == 2)
	{
		sf::Vector2i point1 = points[0], point2 = points[1];
		float vx = 0, vy = 0;
		if (point1.x != point2.x) 
		{
			if (point1.x < point2.x) 
			{
				first_point = sf::Vector2u(Game::left_bound + point1.x * block_size_x, Game::upper_bound + point1.y * block_size_y);
				second_point = sf::Vector2u(Game::left_bound + point2.x * block_size_x, Game::upper_bound + point2.y * block_size_y);
				vx = move_speed;
			}
			else 
			{
				first_point = sf::Vector2u(Game::left_bound + point2.x * block_size_x, Game::upper_bound + point2.y * block_size_y);
				second_point = sf::Vector2u(Game::left_bound + point1.x * block_size_x, Game::upper_bound + point1.y * block_size_y);
				vx = -move_speed;
			}
			vy = 0;
		}
		else if (point1.y != point2.y) 
		{

			if (point1.y < point2.y) 
			{
				first_point = sf::Vector2u(Game::left_bound + point1.x * block_size_x, Game::upper_bound + point1.y * block_size_y);
				second_point = sf::Vector2u(Game::left_bound + point2.x * block_size_x, Game::upper_bound + point2.y * block_size_y);
				vy = move_speed;
			}
			else
			{
				first_point = sf::Vector2u(Game::left_bound + point2.x * block_size_x, Game::upper_bound + point2.y * block_size_y);
				second_point = sf::Vector2u(Game::left_bound + point1.x * block_size_x, Game::upper_bound + point1.y * block_size_y);
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

BreakableBlock::BreakableBlock(const BlockData & block_data, bool endless)
	:
	Block(block_data)
{
}

BreakableBlock::BreakableBlock(std::string texture_name, float x, float y, bool endless)
	:
	Block(texture_name, x, y, endless)
{
}

void BreakableBlock::hitAction(Game & game)
{
	game.getSoundPlayer().playBreakableBlockSound();
	game.pop(this);
}

BlockType BreakableBlock::getBlockType() const
{
	return breakable;
}

ItemBlock::ItemBlock(const BlockData & block_data, bool endless)
	:
	BreakableBlock(block_data, endless),
	item_type(ItemType(rand() % TYPE_NUM))
{
}

ItemBlock::ItemBlock(std::string texture_name, float x, float y, bool endless)
	:
	BreakableBlock(texture_name, x, y, endless),
	item_type(ItemType(rand() % TYPE_NUM))
{
}

void ItemBlock::hitAction(Game & game)
{
	game.getSoundPlayer().playBreakableBlockSound();
	switch (item_type)
	{
	case ADDBALL: game.add(new Ball(center().x, center().y));
		break;
	case MARIOBALL: game.add(new Star(center().x, center().y)); 
		break;
	case ROCKETITEM: game.add(new Rocket(center().x, center().y));
		break;
	case EXPLOSIVE: game.add(new Explosion(game, center().x, center().y));
		break;
	case FASTFORWARD: game.add(new FastForward(center().x, center().y));
		break;
	case BEER: game.add(new Beer(center().x, center().y));
		break;
	}
	game.pop(this);
}

BlockType ItemBlock::getBlockType() const
{
	return item;
}
