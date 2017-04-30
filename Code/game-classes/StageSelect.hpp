#pragma once

#include "SFML/Graphics.hpp"
#include "DirectoryReader.hpp"
#include <iostream>
#include <string>
#include <vector>

class StageSelect
{
public:
	StageSelect(sf::RenderWindow * window, std::string file_path);
	void run();
	std::string getSelectedName() const;
private:
	void eventInput();
	void draw();
	void update();
	void moveText(int delta);
private:
	BBStageFileFinder finder;

	sf::RenderWindow * window;
	sf::Event event;
	sf::Font font;
	std::vector<sf::Text> texts;
	sf::Text back;

	const int FILE_NUM;

	int width;
	int height;

	bool finished;
	int selected;
};