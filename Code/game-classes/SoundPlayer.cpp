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