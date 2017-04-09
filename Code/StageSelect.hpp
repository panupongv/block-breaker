#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class StageSelect
{
public:
	StageSelect(sf::RenderWindow * window, const std::vector<std::string>& file_list);
	void run();
	std::string getSelectedName() const;
private:
	void event_input();
	void draw();
	void update();
private:
	sf::RenderWindow * window;
	sf::Event event;
	sf::Font font;
	std::vector<sf::Text> texts;

	int width;
	int height;
	float offset;

	bool finished;
	int selected;
};