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

	if (!drunk_buffer.loadFromFile(smartPath("block-breaker\\Resources\\drunk.wav")))
		std::cout << "unable to load \"drunk.wav\"" << std::endl;
	drunk.setBuffer(drunk_buffer);

	if (!sonic_buffer.loadFromFile(smartPath("block-breaker\\Resources\\sonic.wav")))
		std::cout << "unable to load \"sonic.wav\"" << std::endl;
	sonic.setBuffer(sonic_buffer);

	if (!win_buffer.loadFromFile(smartPath("block-breaker\\Resources\\win.wav")))
		std::cout << "unable to load \"win.wav\"" << std::endl;
	win.setBuffer(win_buffer);

	if (!lose_buffer.loadFromFile(smartPath("block-breaker\\Resources\\lose.wav")))
		std::cout << "unable to load \"lose.wav\"" << std::endl;
	lose.setBuffer(lose_buffer);
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

void SoundPlayer::playDrunkSound()
{
	drunk.play();
}

void SoundPlayer::playSonicSound()
{
	sonic.play();
}

void SoundPlayer::playWinSound()
{
	win.play();
}

void SoundPlayer::playLoseSound()
{
	lose.play();
}
