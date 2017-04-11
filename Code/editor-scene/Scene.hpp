#pragma once

#include "sfml.hpp"
#include <string>
#include <vector>
#include "BaseObject.hpp"

class Scene
{
public:
    Scene( std::string n , sf::RenderWindow& window );
    virtual ~Scene();
    
    //getters setters
    std::string getSceneName() const;
    void flagInited();
    void flagStartingFalse();
    void flagEnded();
    void flagEnding();
    void setNextScene(Scene* scene_ptr);
    sf::RenderWindow& getWindow();
    bool isInited() const;
    bool isStarting() const;
    bool isEnded() const;
    bool isEnding() const;
    Scene* getNextScene() const;
    
    //actions
    void addObject( BaseObject* sprite );
    void removeObject( BaseObject* sprite );
    
    //need sub class implementation
    virtual void update(sf::Event& event) = 0; // called when not starting not ending
    virtual void draw() = 0;//always called
    
protected:
    virtual void begin() = 0; //called when starting
    virtual void end() = 0; // called when ending && not ended
    virtual void init() = 0;// called when not inited
    
private:
    std::string name = "not set";
    bool inited = false;
    bool starting = true;
    bool ending = false;
    bool ended = false;
    std::vector<BaseObject*> sprites;
    Scene* nextScene = NULL;
    sf::RenderWindow* window;
};