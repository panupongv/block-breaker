//#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include "Menu.hpp"
#include "StageSelect.hpp"
#include "Game.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 620), "SFML works!");//, sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		Menu menu(&window);
		menu.run();
		switch (menu.getChoice())
		{
		case 0:
			Game(&window).run();
			break;
            case 1:
#ifdef __APPLE__
                StageSelect stage_select(&window, "stages/");
#else
                StageSelect stage_select(&window, "block-breaker\\stages");
#endif
			stage_select.run();
			if(window.isOpen())
				Game(&window, stage_select.getSelectedName()).run();
			break;
		}
	}
	window.close();

	system("pause"); 
	return 0;
}
