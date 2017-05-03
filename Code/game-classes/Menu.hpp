#pragma once

#include "sfml.hpp"
#include "Sprite.hpp"
#include "ResourcePath.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class MenuBall : public Sprite
{
public:
	MenuBall();
	void update();
};

class MenuPad : public Sprite
{
public:
	MenuPad();
	void update(const Sprite& ball);
};

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

	MenuBall ball;
	MenuPad pad;

	int width;
	int height;

	int selected;
	bool finished;

};