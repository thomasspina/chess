#pragma once

#include "piece.hpp"

#include <QGraphicsItem>

namespace view
{
    class UiPiece : public QGraphicsItem
    {
    public:
        UiPiece();
    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

    private:
        model::Piece* piece;
    };
}
