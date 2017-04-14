#include "StageSelect.hpp"
#include "ResourcePath.hpp"

StageSelect::StageSelect(sf::RenderWindow * window, std::string file_path)
	:
	window(window),
	reader(file_path),
	width(window->getSize().x),
	height(window->getSize().y),
	FILE_NUM(reader.getFileNames().size()),
	finished(false)
{
	std::vector<std::string> file_list(reader.getFileNames());
	if (!font.loadFromFile(smartPath("block-breaker\\Resources\\munro.ttf")))
	{
		std::cout << "Font not avaliable" << std::endl;
	}
	for (int i = 0; i < FILE_NUM; i++)
	{
		sf::Text temp_text;
		temp_text.setString(file_list[i]);
		temp_text.setFont(font);
		temp_text.setCharacterSize(50);
		temp_text.setFillColor(sf::Color::White);
		temp_text.setOutlineColor(sf::Color::White);

		sf::FloatRect text_rect = temp_text.getLocalBounds();
		temp_text.setOrigin(text_rect.left + text_rect.width / 2.0f,
			text_rect.top + text_rect.height / 2.0f);
		temp_text.setPosition(sf::Vector2f(width / 2.0f, i * 75 + 100));
		texts.push_back(temp_text);
	}
}

void StageSelect::run()
{
	while (!finished && window->isOpen())
	{
		eventInput();
		draw();
		update();
	}
}

std::string StageSelect::getSelectedName() const
{
	if (selected == -1) return "";
	return texts[selected].getString();
}

void StageSelect::eventInput()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (selected != -1)
				finished = true;
			break;	
		case sf::Event::MouseWheelScrolled:
		{
			moveText(event.mouseWheelScroll.delta);
		}
		break;
		}
	}
}

void StageSelect::draw()
{
	window->clear();
	for (int i = 0; i < FILE_NUM; i++)
	{
		window->draw(texts[i]);
	}
	window->display();
}

void StageSelect::update()
{
	bool in_text = false;
	for (int i = 0; i < FILE_NUM; i++)
	{
		if (texts[i].getGlobalBounds().intersects(sf::FloatRect(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y, 1, 1)))
		{
			in_text = true;
			selected = i;
			texts[i].setFillColor(sf::Color::Red);
		}
		else
		{
			texts[i].setFillColor(sf::Color::White);
		}
	}
	if (!in_text)
		selected = -1;
}

void StageSelect::moveText(int delta)
{
	for (int i = 0; i < FILE_NUM; i++)
		texts[i].move(0, delta * 10);
}
