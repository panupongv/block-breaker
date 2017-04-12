#pragma once

#include <vector>
#include "Block.hpp"
#include "BlockData.hpp"

namespace BlockGenerator
{
	Block* create(const BlockData& block_data, bool endless);
	Block* create(BlockType type, float x, float y, bool endless);

	const int COLOR_NUM = 7;
	enum ColorCode {RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET};
	sf::Color getColor(ColorCode color_code);
};