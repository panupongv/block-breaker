#include "ScreenManager.hpp"
#include <iostream>

using namespace std;

sf::Vector2f ScreenManager::getMousePosition(sf::RenderWindow &window)
{
    sf::Vector2i raw_mouse_position = sf::Mouse::getPosition(window);
    
    float ratio_x = static_cast<float>(window.getSize().x) / res_x;
    float ratio_y = static_cast<float>(window.getSize().y) / res_y;
    
    float mouse_x = raw_mouse_position.x / ratio_x;
    float mouse_y = raw_mouse_position.y / ratio_y;
    
    return sf::Vector2f(mouse_x,mouse_y);
}


sf::RenderWindow& ScreenManager::createWindow()
{
    sf::VideoMode mode(res_x,res_y,sf::Style::Close);
    
    sf::RenderWindow* window = new sf::RenderWindow(mode,"Block Breaker Stage Editor");
    
    window->setSize(sf::Vector2u(default_size_x,default_size_y));
    
    return *window;
}

void ScreenManager::resizeWindow(sf::RenderWindow& window, int x , int y )
{
    window.setSize(sf::Vector2u(x,y));
}
