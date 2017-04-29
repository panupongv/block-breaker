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
	void playExplodeSound();
	void playBallLaunchSound();
	void playRocketLaunchSound();
	void playWinSound();
private:
	sf::SoundBuffer normal_block_buffer;
	sf::SoundBuffer breakable_block_buffer;
	sf::SoundBuffer bounce_buffer;
	sf::SoundBuffer mario_buffer;
	sf::SoundBuffer explode_buffer;
	sf::SoundBuffer ball_launch_buffer;
	sf::SoundBuffer rocket_launch_buffer;
	sf::SoundBuffer win_buffer;

	sf::Sound normal_block;
	sf::Sound breakable_block;
	sf::Sound bounce;
	sf::Sound mario;
	sf::Sound explode;
	sf::Sound ball_launch;
	sf::Sound rocket_launch;
	sf::Sound win;
};