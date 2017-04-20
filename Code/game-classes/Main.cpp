//#pragma once

#include "sfml.hpp"

#include "Menu.hpp"
#include "CharaterSelect.hpp"
#include "StageSelect.hpp"
#include "Game.hpp"
#include "GameResult.hpp"
#include "ResourcePath.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 620), "Block Breaker");//, sf::Style::Fullscreen);
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
			if (window.isOpen())
			{
				Game game(&window, character_select.getSelectedName());
				game.run();
				GameResult result(&window, game.getFinalScore());
				result.run();
			}
			break;
           case 1:
            StageSelect stage_select(&window, smartPath("block-breaker\\Stages"));
			stage_select.run();
			character_select.run();
			if (window.isOpen())
			{
				Game game(&window, character_select.getSelectedName(), stage_select.getSelectedName());
				game.run();
				std::cout << game.getStatus() << std::endl;
			}
			break;
		}
	}
	window.close();

	system("pause"); 
	return 0;
}
