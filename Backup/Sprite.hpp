#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Sprite
{
public:
	Sprite();
	//virtual void update();
private:
	sf::Sprite sprite;
	sf::Texture texture;
};