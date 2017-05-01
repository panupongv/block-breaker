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
	std::vector<std::pair<sf::Text, sf::Text>> score_list;
	sf::Text head;
	sf::Font font;

	int width;
	int height;
	bool finished;
};