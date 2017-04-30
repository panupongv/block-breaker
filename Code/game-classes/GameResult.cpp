#include "GameResult.hpp"

GameResult::GameResult(sf::RenderWindow * window, int score)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	mode(ENDLESS),
	score(score)
{
	if(!setup())
		std::cout << "Setup failed - GameResult" << std::endl;
	score_text.setString("score: " + std::to_string(score));
	score_text.setFont(font);
	score_text.setCharacterSize(80);
	sf::FloatRect text_rect = score_text.getLocalBounds();
	score_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	score_text.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f - 100));
	score_text.setFillColor(sf::Color::White);

	name = "";
	name_text.setString("NAME: " + name);
	name_text.setFont(font);
	name_text.setCharacterSize(80);
	text_rect = name_text.getLocalBounds();
	name_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	name_text.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));
	name_text.setFillColor(sf::Color::White);
}

GameResult::GameResult(sf::RenderWindow * window, bool win)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	mode(CUSTOM)
{
	if (!setup())
		std::cout << "Setup failed - GameResult" << std::endl;
	if(win)
		win_text.setString("too easy");
	else
		win_text.setString("lol noob");
	win_text.setFont(font);
	win_text.setCharacterSize(80);
	sf::FloatRect text_rect = win_text.getLocalBounds();
	win_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	win_text.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));
	win_text.setFillColor(sf::Color::White);
}

void GameResult::run()
{
	while (!finished && window->isOpen())
	{
		eventInput();
		draw();
		update();
	}
	if (mode == ENDLESS && name != "")
		ScoreProcessor().addScore(score, name);
}

void GameResult::draw()
{
	window->clear();
	if (mode == ENDLESS)
	{
		window->draw(score_text);
		window->draw(name_text);
	}
	else
	{
		window->draw(win_text);
	}
	window->draw(done_text);
	window->display();
}

void GameResult::eventInput()
{
	while(window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (in_text)
				finished = true;
			break;
		case sf::Event::TextEntered:
			char pressed = event.key.code;
			if (isalpha(pressed))
				name += pressed;
			else if(pressed == '\b' && name.size() != 0)
				name = name.substr(0, name.size() - 1);
			name_text.setString("NAME: " + name);
			sf::FloatRect text_rect = name_text.getLocalBounds();
			name_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
				text_rect.top + text_rect.height / 2.0f);
			name_text.setPosition(sf::Vector2f(width / 2.0f, height / 2.0f));
			name_text.setFillColor(sf::Color::White);
		break;
		}
	}
}

void GameResult::update()
{
	sf::FloatRect mouse(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y, 1, 1);
	in_text = mouse.intersects(done_text.getGlobalBounds());
	if(in_text)
		done_text.setFillColor(sf::Color::Red);
	else
		done_text.setFillColor(sf::Color::White);
}

bool GameResult::setup()
{
	if (!font.loadFromFile(smartPath("block-breaker\\Resources\\munro.ttf")))
		return false;
	done_text.setString("DONE");
	done_text.setFont(font);
	done_text.setCharacterSize(80);
	done_text.setPosition(600, 480);
	done_text.setFillColor(sf::Color::White);
	return true;
}
