#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include "Game.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");//, sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	Game game(&window, "stage1.csv");
	game.run();
	window.close();

	system("pause"); 
	return 0;
}