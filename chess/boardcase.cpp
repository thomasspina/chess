#include "boardcase.hpp"

const QColor view::Colour::White = QColor::fromRgb(240, 217, 183);

const QColor view::Colour::Black = QColor::fromRgb(180, 136, 102);


view::BoardCase::BoardCase(int x, int y, int h, int w, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    setAcceptDrops(true);

    _coordinates = std::make_pair(x, y);
    _height = h;
    _width = w;
}


void view::BoardCase::dropEvent(QGraphicsSceneDragDropEvent* event)
{
    // TODO when piece is dropped we check move validity,
        // if not good then we don't change its pos and it goes back to original pos
        // if good then we move it to this case
}


void view::BoardCase::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    // TODO mouse press to move a piece. Essentially does the what the drag and drop does but with clicks
}
