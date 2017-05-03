#pragma once

#include "sfml.hpp"

#include "Menu.hpp"
#include "CharaterSelect.hpp"
#include "StageSelect.hpp"
#include "HighScore.hpp"
#include "Game.hpp"
#include "GameResult.hpp"
#include "ResourcePath.hpp"
#include "ScoreProcessor.hpp"
#include <iostream>

class BlockBreaker
{
public:
	BlockBreaker();
	void run();
private:
	sf::RenderWindow window;
};