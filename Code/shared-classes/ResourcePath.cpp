////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2017 Marco Antognini (antognini.marco@gmail.com),
//                         Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "ResourcePath.hpp"
#include <iostream>
//#import <Foundation/Foundation.h>

using namespace std;

////////////////////////////////////////////////////////////
std::string resourcePath(void)
{
#ifdef __APPLE__
    return "_resources/";
#else
    return "";
#endif
//
//    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
//
//    std::string rpath;
//    NSBundle* bundle = [NSBundle mainBundle];
//
//    if (bundle == nil) {
//#ifdef DEBUG
//        NSLog(@"bundle is nil... thus no resources path can be found.");
//#endif
//    } else {
//        NSString* path = [bundle resourcePath];
//        rpath = [path UTF8String] + std::string("/");
//    }
//
//    [pool drain];
//
//    return rpath;
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
