#pragma once

#include "piece.hpp"

namespace model
{
    class Knight : public Piece 
    {
    public:
        Knight(const Colour& colour, const std::pair<int, int>& pos);

        bool isMoveValid(int col, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;
    };
}