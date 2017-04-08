#include "SnappableObject.hpp"

using namespace std;
using namespace sf;

SnappableObject::~SnappableObject() { }

SnappableObject::SnappableObject( int size_x , int size_y )
{
    this->grid_size_x = size_x;
    this->grid_size_y = size_y;
}

Vector2i SnappableObject::getSnapGrid(float x, float y)
{
    return Vector2i( static_cast<int>(x/grid_size_x) , static_cast<int>(y/grid_size_y));
}

Vector2f SnappableObject::getSnapPosition(float x, float y)
{
    Vector2i grid = this->getSnapGrid(x, y);
    return this->getSnapPosition(grid.x, grid.y);
}

Vector2f SnappableObject::getSnapPosition(int grid_x, int grid_y)
{
    return Vector2f( grid_x * grid_size_x , grid_y * grid_size_y);
}