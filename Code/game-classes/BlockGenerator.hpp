#pragma once

#include "Block.hpp"
#include "BlockData.hpp"

class BlockGenerator
{
public:
	static Block* create(const BlockData& block_data, bool endless);
	static Block* create(BlockType type, float x, float y, bool endless);
};