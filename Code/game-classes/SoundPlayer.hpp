#pragma once

#include "sfml.hpp"
#include "ResourcePath.hpp"
#include <iostream>

class SoundPlayer
{
public:
	SoundPlayer();
	void playNormalBlockSound();
	void playBreakableBlockSound();
	void playBounceSound();
	void playMarioSound();
private:
	sf::SoundBuffer normal_block_buffer;
	sf::SoundBuffer breakable_block_buffer;
	sf::SoundBuffer bounce_buffer;
	sf::SoundBuffer mario_buffer;

	sf::Sound normal_block;
	sf::Sound breakable_block;
	sf::Sound bounce;
	sf::Sound mario;
};