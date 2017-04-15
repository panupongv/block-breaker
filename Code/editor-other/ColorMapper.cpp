#include "ColorMapper.hpp"

using namespace std;

ColorMapper::ColorMapper() {}

sf::Color ColorMapper::getColorFromRatio( float ratio ) const
{
    //reference
    //http://stackoverflow.com/questions/2374959/algorithm-to-convert-any-positive-integer-to-an-rgb-value
    
    float red,green,blue;
    
    //calculate red
    if(ratio >= 0 && ratio <= 0.25*0.5 )
        red = 0.5 + 4*ratio;
    else if(ratio >= 0.25*0.5 && ratio <= 0.25*1.5 )
        red = 1;
    else if(ratio >= 0.25*1.5 && ratio <= 0.25*2.5 )
        red = 1 - 4*(ratio-0.25*1.5);
    else
        red = 0;
    
    //calculate green
    if(ratio >= 0.25*0.5 && ratio <= 0.25*1.5 )
        green = 4*(ratio-0.25*0.5);
    else if(ratio >= 0.25*1.5 && ratio <= 0.25*2.5 )
        green = 1;
    else if(ratio >= 0.25*2.5 && ratio <= 0.25*3.5 )
        green = 1 - 4*(ratio-0.25*2.5);
    else
        green = 0;
    
    //calculate blue
    if(ratio >= 0.5 && ratio <= 0.25*2.5 )
        blue = 4*(ratio-0.5);
    else if(ratio >= 0.25*2.5 && ratio <= 0.25*3.5 )
        blue = 1;
    else if(ratio >= 0.25*3.5 && ratio <= 1 )
        blue = 1 - 4*(ratio-0.25*3.5);
    else
        blue = 0;
    
    //normalize colors
    red *= 255;
    green *= 255;
    blue *= 255;
    
    return sf::Color(red,green,blue);
}

sf::Color ColorMapper::getColorFromId( int id , int num ) const
{
    float slot_size = 1.0/( num-1 );
    float ratio = slot_size * id;
    
    return getColorFromRatio( ratio );
}
