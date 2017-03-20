#include "DraftBlock.hpp"
//#include <iostream>

//using namespace std;
//
//
DraftBlock::DraftBlock( TemplateBlock tb )
: Block( tb.getType() , 0 , 0 ) { }


void DraftBlock::update()
{
    //TODO
}

bool DraftBlock::isAvailable()
{
    return available;
}

void DraftBlock::setAvailability(bool available)
{
    this->available = available;
}

sf::Vector2i DraftBlock::getMagnetGrid(float x, float y)
{
    return sf::Vector2i(
        static_cast<int>(x)/block_size_x ,
        static_cast<int>(y)/block_size_y
    );
}