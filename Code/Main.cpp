#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.hpp"
#include "Sprite.hpp"
#include "Block.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");//, sf::Style::Fullscreen);
	
	//dummy menu
	//press any key to exit menu
	Menu(&window).run();

	//Test
	Sprite dice("dice.png", 100, 100, 0, 0); //frame width and height 100, start pos (0, 0)
	Block block("santa.png", 2, 0); //x = 200 == (block size x * grid pos x), y = (block size y * 0) = 0

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
		dice.draw(window);
		block.draw(window);
		block.update();
		window.display();
	}

	system("pause"); 
	return 0;
}