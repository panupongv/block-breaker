#include "SoundPlayer.hpp"

SoundPlayer::SoundPlayer()
	:
	normal_block()
{
	if (!normal_block_buffer.loadFromFile(smartPath("block-breaker\\Resources\\normalblocksound.wav")))
		std::cout << "unable to load \"normalblocksound.wav\"" << std::endl;
	normal_block.setBuffer(normal_block_buffer);

	if(!breakable_block_buffer.loadFromFile(smartPath("block-breaker\\Resources\\breakableblocksound.wav")))
		std::cout << "unable to load \"breakableblocksound.wav\"" << std::endl;
	breakable_block.setBuffer(breakable_block_buffer);

	if(!bounce_buffer.loadFromFile(smartPath("block-breaker\\Resources\\bounce.wav")))
		std::cout << "unable to load \"bounce.wav\"" << std::endl;
	bounce.setBuffer(bounce_buffer);

	if(!mario_buffer.loadFromFile(smartPath("block-breaker\\Resources\\mariosong.wav")))
		std::cout << "unable to load \"mariosong.wav\"" << std::endl;
	mario.setBuffer(mario_buffer);

	if (!explode_buffer.loadFromFile(smartPath("block-breaker\\Resources\\explodesound.wav")))
		std::cout << "unable to load \"explodesound.wav\"" << std::endl;
	explode.setBuffer(explode_buffer);

	if (!ball_launch_buffer.loadFromFile(smartPath("block-breaker\\Resources\\pulse.wav")))
		std::cout << "unable to load \"pulse.wav\"" << std::endl;
	ball_launch.setBuffer(ball_launch_buffer);

	if (!rocket_launch_buffer.loadFromFile(smartPath("block-breaker\\Resources\\cannon.wav")))
		std::cout << "unable to load \"cannon.wav\"" << std::endl;
	rocket_launch.setBuffer(rocket_launch_buffer);

	if (!win_buffer.loadFromFile(smartPath("block-breaker\\Resources\\win.wav")))
		std::cout << "unable to load \"win.wav\"" << std::endl;
	win.setBuffer(win_buffer);
}

void SoundPlayer::playNormalBlockSound()
{
	normal_block.play();
}

void SoundPlayer::playBreakableBlockSound()
{
	breakable_block.play();
}

void SoundPlayer::playBounceSound() 
{
	bounce.play();
}

void SoundPlayer::playMarioSound() 
{
	mario.play();
}

void SoundPlayer::playExplodeSound()
{
	explode.play();
}

void SoundPlayer::playBallLaunchSound()
{
	ball_launch.play();
}

void SoundPlayer::playRocketLaunchSound()
{
	rocket_launch.play();
}

void SoundPlayer::playWinSound()
{
	win.play();
}
