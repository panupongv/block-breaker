#pragma once

#include "sfml.hpp"
#include <iostream>
#include <string>
#include <vector>

class CharacterShowcase
{
public:
	CharacterShowcase(std::string texture_name, std::string name);
	void draw(sf::RenderWindow& window);
	std::string getTextureName() const;
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Text text;
	sf::Font font;

	const std::string texture_name;
};

class CharacterSelect
{
public:
	CharacterSelect(sf::RenderWindow* window);
	~CharacterSelect();
	void run();
	std::string getSelectedName() const;
private:
	void eventInput();
	void draw();
private:
	sf::RenderWindow* window;
	sf::Event event;
	std::vector<CharacterShowcase*> characters;

	int character_num;
	int selected;
	bool finished;
};