//#pragma once

#ifdef __APPLE__
    #include <SFML/Graphics.hpp>
#else
    #include <SFML\Graphics.hpp>
#endif

#include "Menu.hpp"
#include "CharaterSelect.hpp"
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
		CharacterSelect character_select(&window);
		switch (menu.getChoice())
		{
		case 0:
			character_select.run();
			Game(&window, character_select.getSelectedName()).run();
			break;
		case 1:
			character_select.run();
			StageSelect stage_select(&window, "block-breaker\\stages");
			stage_select.run();
			if(window.isOpen())
				Game(&window, character_select.getSelectedName(), stage_select.getSelectedName()).run();
			break;
		}
	}
	window.close();

	system("pause"); 
	return 0;
}
