#include "BlockGenerator.hpp"

Block * BlockGenerator::create(const BlockData & block_data, bool endless)
{
	switch (block_data.getType())
	{
	case normal:
		return new Block(block_data, endless);
	case breakable:
		return new BreakableBlock(block_data, endless);
	case item:
		return new ItemBlock(block_data, endless);
	default:
		return nullptr;
	}
}

Block * BlockGenerator::create(BlockType type, float x, float y, bool endless)
{
	switch (type)
	{
	case normal:
		return new Block(Block::getTextureNameFromType(type), x, y, endless);
	case breakable:
		return new BreakableBlock(Block::getTextureNameFromType(type), x, y, endless);
	case item:
		return new ItemBlock(Block::getTextureNameFromType(type), x, y, endless);
	default:
		return nullptr;
	}
}

sf::Color BlockGenerator::getColor(ColorCode color_code)
{
	switch (color_code)
	{
	case RED: return sf::Color::Red;
	case ORANGE: return sf::Color(255, 127, 0);
	case YELLOW: return sf::Color::Yellow;
	case GREEN: return	sf::Color::Green;
	case BLUE: return	sf::Color::Blue;
	case INDIGO: return	sf::Color(50, 0, 150);
	case VIOLET: return	sf::Color(148, 0, 211);
	default: return sf::Color::White;
	}
}

