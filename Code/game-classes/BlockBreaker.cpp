#include "BlockBreaker.hpp"

BlockBreaker::BlockBreaker()
	:
	window(sf::VideoMode(800, 620), "Block Breaker")
{
	sf::Image icon;
	icon.loadFromFile(smartPath("block-breaker\\Resources\\iconnohelmet.png"));
	window.setIcon(32, 32, icon.getPixelsPtr());
	window.setFramerateLimit(60);
}

void BlockBreaker::run()
{
	while (window.isOpen())
	{
		Menu menu(&window);
		menu.run();
		CharacterSelect character_select(&window);
		switch (menu.getChoice())
		{
		case 0:
		{
			character_select.run();
			if (window.isOpen())
			{
				Game game(&window, character_select.getSelectedName());
				game.run();
				if (window.isOpen())
				{
					GameResult result(&window, game.getFinalScore());
					result.run();
				}
			}
		}
		break;
		case 1:
		{
			StageSelect stage_select(&window, smartPath("block-breaker\\Stages"));
			stage_select.run();
			if (window.isOpen() && stage_select.getSelectedName() != "")
			{
				character_select.run();
				if (window.isOpen())
				{
					Game game(&window, character_select.getSelectedName(), stage_select.getSelectedName());
					game.run();
					if (window.isOpen())
					{
						GameResult result(&window, game.getStatus());
						result.run();
					}
				}
			}
		}
		break;
		case 2:
			HighScore(&window).run();
			break;
		}
	}
	window.close();
}
