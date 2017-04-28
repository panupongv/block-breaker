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
	void eventInput();
	void draw();
	void update();
private:
	static constexpr int TEXT_NUM = 4;

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