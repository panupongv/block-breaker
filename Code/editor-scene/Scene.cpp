#include "Scene.hpp"
#include <iostream>

using namespace std;

Scene::Scene( string n , sf::RenderWindow& window) : name(n)
{
    this->window = &window;
}

Scene::~Scene()
{
    while(this->objects.size() > 0)
    {
        delete this->objects.back();
        this->objects.pop_back();
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

void Scene::addObject(BaseObject* object)
{
    this->objects.push_back(object);
}

void Scene::removeObject(BaseObject* object)
{
    for(int i = 0 ; i < this->objects.size() ; ++i)
    {
        if(object == this->objects[i])
        {
            this->objects.erase(this->objects.begin()+i);
            delete object;
            return;
        }
    }
}

void Scene::update(EventHandler& eHandler)
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
    for(int i = 0 ; i < this->objects.size() ; ++i)
    {
        this->objects[i]->draw(this->getWindow());
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
