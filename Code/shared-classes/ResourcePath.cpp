
#include "ResourcePath.hpp"
#include <iostream>

using namespace std;

string resourcePath( )
{
    return smartPath("block-breaker/Resources/editor/");
}

string stagePath( )
{
    return smartPath("block-breaker/Stages/");
}

string smartPath( string path )
{
#ifdef __APPLE__
    int pos;
    while((pos = path.find("\\")) != string::npos)
        path[pos] = '/';
    
    return path;
#else
    int pos;
    while((pos = path.find("/")) != string::npos)
        path[pos] = '\\';
    
    return path;
#endif

}

string texture_name_of_type( BlockType type )
{
    string result;
    
    switch (type)
    {
        case normal:
            result += "normal-block.png";
            break;
            
        case breakable :
            result += "breakable-block.png";
            break;
            
        case item:
            result += "item-block.png";
            break;
            
        default:
            throw invalid_argument("no support texture of BlockType ");
    }
    
    return smartPath(result);
}
