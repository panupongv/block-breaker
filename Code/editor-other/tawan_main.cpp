#include "sfml.hpp"
#include <iostream>

#include "ResourcePath.hpp"
#include "StageData.hpp"
#include "EditorScene.hpp"
#include "TextObject.hpp"
#include "WindowHelper.hpp"
#include "DirectoryReader.hpp"
#include "EventHandler.hpp"

using namespace std;

int main()
{
    sf::RenderWindow& window = WindowHelper::createWindow();
    
    Scene* current_scene = new EditorScene(window);
    
    while(window.isOpen())
    {
        sf::Event event;
        EventHandler eHandler(window);
        
        while(window.pollEvent(event))
            eHandler.poll(event);
        
        
        if (eHandler.wasClosed())
        {
            window.close();
            return EXIT_SUCCESS;
        }
        
        if(current_scene->isEnded())
        {
            if(current_scene->getNextScene() == NULL)
            {
                window.close();
                return EXIT_SUCCESS;
            }
            
            Scene* prev_scene = current_scene;
            current_scene = current_scene->getNextScene();
            delete prev_scene;
        }
        
        current_scene->update(eHandler);
        current_scene->draw();
        
        window.display();
    }
    
    return EXIT_SUCCESS;
}

void backup()
{
    // Set the Icon
//    sf::Image icon;
//    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
//        return EXIT_FAILURE;
//    }
    
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
