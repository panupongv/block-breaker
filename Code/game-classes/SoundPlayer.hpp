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
	void playDrunkSound();
	void playSonicSound();
	void playWinSound();
	void playLoseSound();
private:
	sf::SoundBuffer normal_block_buffer;          sf::Sound normal_block;
	sf::SoundBuffer breakable_block_buffer;	      sf::Sound breakable_block;
	sf::SoundBuffer bounce_buffer;                sf::Sound bounce;
	sf::SoundBuffer mario_buffer;				  sf::Sound mario;
	sf::SoundBuffer explode_buffer;               sf::Sound explode;
	sf::SoundBuffer ball_launch_buffer;           sf::Sound ball_launch;
	sf::SoundBuffer rocket_launch_buffer;         sf::Sound rocket_launch;
	sf::SoundBuffer drunk_buffer;                 sf::Sound drunk;
	sf::SoundBuffer sonic_buffer;                 sf::Sound sonic;
	sf::SoundBuffer win_buffer;                   sf::Sound win;
	sf::SoundBuffer lose_buffer;                  sf::Sound lose;
};