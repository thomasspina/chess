#pragma once

#include <QObject>
#include <QGraphicsRectItem>

namespace view
{
    class BoardCase : public QObject, public QGraphicsRectItem
    {
        Q_OBJECT

    public:
        BoardCase(int x, int y, int i, int j);
        ~BoardCase() = default;

    private:
        std::pair<int, int> _coordinates;
        int _height;
        int _width;

    public slots:
        // piece is hovering over?
    signals:
        // piece has been dropped
    };
}
