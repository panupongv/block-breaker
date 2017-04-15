#include "Explosion.hpp"

Explosion::Explosion(float x, float y)
	:
	Sprite("explosion.png", 128, 128, 0, 0),
	frame_counter(0)
{
	setCenter(x, y);
}

void Explosion::update(Game & game)
{
	std::vector<Block*> block_list = game.getBlockList();
	if (frame_counter == 0)
	{
		for (int i = 0; i < block_list.size(); i++)
		{
			if (collide(*block_list[i]))
				game.pop(block_list[i]);
		}
	}
	frame_counter++;
	if (getCurrentFrame() == frame_limit)
	{
		game.pop(this);
		return;
	}
	if (frame_counter == frame_to_update)
	{
		nextFrame();
		frame_counter = 0;
	}
	
}
