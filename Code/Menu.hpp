#pragma once

#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>

class Menu
{
public:
	Menu(sf::RenderWindow *window);
	void run();
	int getChoice() const;
private:
	void event_input();
	void draw();
	void update();
private:
	static const int TEXT_NUM = 3;

	sf::RenderWindow *window;
	sf::Font font;
	sf::Event event;
	sf::Texture title_texture;
	sf::Sprite title;
	sf::Text texts[TEXT_NUM];

	int width;
	int height;

	int selected;
	bool finished;

};