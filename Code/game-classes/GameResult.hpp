#pragma once

#include "sfml.hpp"
#include "ResourcePath.hpp"
#include <iostream>
#include <fstream>

class GameResult
{
public:
	GameResult(sf::RenderWindow*window, int score);
	GameResult(sf::RenderWindow* window, bool win);
	void run();
private:
	void draw();
	void eventInput();
	void update();
	bool setup();
private:
	enum Mode {ENDLESS = 1, CUSTOM};
	Mode mode;

	sf::RenderWindow * window;
	sf::Event event;
	sf::Text score_text;
	sf::Text win_text;
	sf::Text done_text;
	sf::Font font;

	int width;
	int height;
	bool in_text;
	bool finished;
};