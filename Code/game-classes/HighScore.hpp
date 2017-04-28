#pragma once

#include "sfml.hpp"
#include "ScoreProcessor.hpp"

class HighScore
{
public:
	HighScore(sf::RenderWindow * window);
	void run();
private:
	void draw();
private:
	sf::RenderWindow * window;
	sf::Event event;
	std::vector<sf::Text> score_list;
	sf::Text head;
	sf::Font font;

	bool finished;
	int width;
	int height;
};