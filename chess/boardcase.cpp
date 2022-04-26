#include "boardcase.hpp"

view::BoardCase::BoardCase(int x, int y, int h, int w)
{
    _coordinates = std::make_pair(x, y);
    _height = h;
    _width = w;
}



