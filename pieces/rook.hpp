#pragma once

#include "piece.hpp"

namespace model
{
    class Rook : public Piece 
    {
    public:
        Rook(Colour colour, std::pair<int, int> pos);

        bool isMoveValid(int col, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow) override;
    };
}