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
	
	//Test game class
	Game game(&window, "stage1.csv");
	game.run();

	int counter = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				window.close();
			}
		}
 		window.clear();
		window.display();
	}

	system("pause"); 
	return 0;
}