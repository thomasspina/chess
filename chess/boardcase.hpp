#pragma once

#include <QGraphicsRectItem>
#include <QColor>

namespace view
{
    struct Colour {
        static const QColor White;
        static const QColor Black;
    };

    class BoardCase : public QGraphicsRectItem
    {
    public:
        BoardCase(int x, int y, int h, int w, QGraphicsItem* parent = nullptr);
        ~BoardCase() = default;

    private:
        std::pair<int, int> _coordinates;
        int _height;
        int _width;

    protected:
        void dropEvent(QGraphicsSceneDragDropEvent* event) override;
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    };
}
