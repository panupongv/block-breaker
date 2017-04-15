#include "CharaterSelect.hpp"

CharacterShowcase::CharacterShowcase(std::string texture_name, std::string name)
	:
	texture_name(texture_name)
{
	if (!font.loadFromFile("block-breaker\\Resources\\munro.ttf"))
	{
		std::cout << "failed to load font - CharacterShowcase" << std::endl;
		system("pause");
	}
	text.setCharacterSize(80);
	text.setFont(font);
	text.setString(name);
	sf::FloatRect text_rect = text.getLocalBounds();
	text.setOrigin(text_rect.left + text_rect.width / 2.0f,
		text_rect.top + text_rect.height / 2.0f);
	text.setPosition(sf::Vector2f(400, 150));
	text.setFillColor(sf::Color::White);
	if (!texture.loadFromFile("block-breaker\\Resources\\" + texture_name))
	{
		std::cout << "failed to load texture - CharacterShowcase" << std::endl;
		system("pause");
	}
	sprite.setTexture(texture);
	sf::FloatRect sprite_rect = sprite.getLocalBounds();
	sprite.setOrigin(sprite_rect.left + sprite_rect.width / 2.0f,
		sprite_rect.top + sprite_rect.height / 2.0f);
	sprite.setPosition(sf::Vector2f(400, 320));
}

void CharacterShowcase::draw(sf::RenderWindow & window)
{
	window.draw(text);
	window.draw(sprite);
}

std::string CharacterShowcase::getTextureName() const
{
	return texture_name;
}

CharacterSelect::CharacterSelect(sf::RenderWindow * window)
	:
	window(window),
	selected(0)
{
	characters.push_back(new CharacterShowcase("paddle.png", "CLASSIC"));
	characters.push_back(new CharacterShowcase("catpad2.png", "CAT"));
	character_num = characters.size();
}

CharacterSelect::~CharacterSelect()
{
	for (int i = 0; i < characters.size(); i++)
		delete characters[i];
}

void CharacterSelect::run()
{
	while (!finished && window->isOpen())
	{
		eventInput();
		draw();
	}
}

std::string CharacterSelect::getSelectedName() const
{
	return characters[selected]->getTextureName();
}

void CharacterSelect::eventInput()
{
	while(window->pollEvent(event))
	{
		switch(event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				selected--;
				if (selected == -1)
					selected += character_num;
				break;
			case sf::Keyboard::Right:
				selected = (selected + 1) % character_num;
				break;
			case sf::Keyboard::Return: finished = true; break;
			}
		}
		break;
		}
	}
}

void CharacterSelect::draw()
{
	window->clear();
	characters[selected]->draw(*window);
	window->display();
}
