#include "boardcase.hpp"

const QColor view::Colour::White = QColor::fromRgb(240, 217, 183);

const QColor view::Colour::Black = QColor::fromRgb(180, 136, 102);


view::BoardCase::BoardCase(int x, int y, int h, int w)
{
    _coordinates = std::make_pair(x, y);
    _height = h;
    _width = w;
}



