#include "Scene.hpp"
#include <iostream>

using namespace std;

Scene::Scene( string n , sf::RenderWindow& window) : name(n)
{
    this->window = &window;
}

Scene::~Scene()
{
    while(this->sprites.size() > 0)
    {
        delete this->sprites.back();
        this->sprites.pop_back();
    }
}

string Scene::getSceneName() const
{
    return this->name;
}

void Scene::flagInited()
{
    this->inited = true;
}

void Scene::flagStartingFalse()
{
    this->starting = false;
}

void Scene::flagEnded()
{
    this->ended = true;
}

void Scene::flagEnding()
{
    this->ended = true;
}

void Scene::setNextScene(Scene* ptr)
{
    this->nextScene = ptr;
}

sf::RenderWindow& Scene::getWindow()
{
    return *window;
}
bool Scene::isStarting() const
{
    return this->starting;
}

bool Scene::isEnded() const
{
    return this->ended;
}

bool Scene::isEnding() const
{
    return this->ending;
}

bool Scene::isInited() const
{
    return this->inited;
}

Scene* Scene::getNextScene() const
{
    return this->nextScene;
}

void Scene::addObject(BaseObject* sprite)
{
    this->sprites.push_back(sprite);
}

void Scene::removeObject(BaseObject* sprite)
{
    for(int i = 0 ; i < this->sprites.size() ; ++i)
    {
        if(sprite == this->sprites[i])
        {
            this->sprites.erase(this->sprites.begin()+i);
            delete sprite;
            return;
        }
    }
}

void Scene::update(sf::Event& event)
{
    if(isStarting())
    {
        begin();
        return;
    }
    
    if(isEnding())
    {
        end();
        return;
    }
}

void Scene::draw()
{
    for(int i = 0 ; i < this->sprites.size() ; ++i)
    {
        this->sprites[i]->draw(this->getWindow());
    }
}

void Scene::begin()
{
    if(isInited() == false)
    {
        init();
        flagInited();
    }
}
