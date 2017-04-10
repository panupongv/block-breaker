#pragma once

#include "sfml.hpp"

class ScreenSetting
{
private:
    
public:
    static const int res_x = 800;
    static const int res_y = 600;
    constexpr static float ratio = 2;
    static const int size_x = res_x*ratio;
    static const int size_y = res_y*ratio;
};
