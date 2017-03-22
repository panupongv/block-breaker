#include "DraftBlock.hpp"

using namespace std;
using namespace sf;

DraftBlock::DraftBlock( TemplateBlock tb )
: TemplateBlock(tb.getType() , tb.getColor() ,-1000,-1000 ) { }


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