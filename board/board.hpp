#pragma once

#include <memory>

#include "piece.hpp"

namespace model
{
    class Board 
    {
    public:
        Board();
        ~Board() = default;

        std::unique_ptr<Piece>& getPiece(int col, int row) const;

        void placePiece(int col, int row);
    private:
        std::unique_ptr<Piece> _board[8][8];
    };
}