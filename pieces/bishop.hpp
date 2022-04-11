#pragma once

#include "piece.hpp"

namespace model
{
    class Bishop : public Piece 
    {
    public:
        Bishop(Colour colour, std::pair<int, int> pos);

        bool isMoveValid(int col, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;
    };
}