#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include "Sprite.hpp"
#include "Block.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");//, sf::Style::Fullscreen);
	
	//dummy menu
	//press any key to exit menu
	//Menu(&window).run();

	BlockData b_data("[block]0,255,255,255,1,2,10,10,100,10");

	//Test
	Block block("brick.png", b_data); //x = 200 == (block size x * grid pos x), y = (block size y * 0) = 0

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
		block.draw(window);
		block.update();
		window.display();
	}

	system("pause"); 
	return 0;
}