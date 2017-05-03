#include "HighScore.hpp"

HighScore::HighScore(sf::RenderWindow * window)
	:
	window(window),
	width(window->getSize().x),
	height(window->getSize().y),
	finished(false)
{
	if (!font.loadFromFile(smartPath("block-breaker\\Resources\\munro.ttf")))
	{
		std::cout << "Font not avaliable" << std::endl;
	}
	ScoreProcessor pcs;
	std::vector<std::pair<std::string, std::string>> strings = pcs.getTopScores();
	sf::Text temp_text;
	std::pair<sf::Text, sf::Text> temp_pair;
	temp_text.setFont(font);
	temp_text.setCharacterSize(40);
	temp_text.setFillColor(sf::Color::White);
	for (int i = 0; i < strings.size(); i++)
	{
		temp_text.setString(strings[i].first);
		temp_text.setPosition(150, 70 + (45 * (i + 1)));
		temp_pair.first = temp_text;
		temp_text.setString(strings[i].second);
		temp_text.setPosition(width - 150 - temp_text.getLocalBounds().width, 70 + (45 * (i + 1)));
		temp_pair.second = temp_text;
		score_list.push_back(temp_pair);
	}
	head.setString("Top scorers");
	head.setFont(font);
	head.setCharacterSize(60);
	head.setFillColor(sf::Color::White);
	head.setOutlineColor(sf::Color::White);
	sf::FloatRect text_rect = head.getLocalBounds();
	head.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	head.setPosition(sf::Vector2f(width / 2.0f, 75));
}

void HighScore::run()
{
	while (!finished && window->isOpen())
	{
		draw();
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			else if (event.type == sf::Event::MouseButtonPressed)
				finished = true;
		}
	}
}

void HighScore::draw()
{
	window->clear();
	for (int i = 0; i < score_list.size(); i++)
	{
		window->draw(score_list[i].first); window->draw(score_list[i].second);
	}
	window->draw(head);
	window->display();
}
