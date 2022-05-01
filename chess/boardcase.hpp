#pragma once

#include <QObject>
#include <QGraphicsRectItem>
#include <QColor>

namespace view
{
    struct Colour {
        static const QColor White;
        static const QColor Black;
    };

    class BoardCase : public QObject, public QGraphicsRectItem
    {
        Q_OBJECT

    public:
        BoardCase(int x, int y, int h, int w);
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
