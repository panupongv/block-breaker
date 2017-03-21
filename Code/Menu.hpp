#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>

class Menu
{
public:
	Menu(sf::RenderWindow *window);
	void run();
private:
	sf::RenderWindow *window;
	sf::Event event;

	bool finished;

	void event_input();
	void draw();
};