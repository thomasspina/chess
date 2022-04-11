#pragma once

#include "piece.hpp"
#include "bishop.hpp"
#include "rook.hpp"

namespace model
{
    class Queen : virtual public Piece, public Rook, public Bishop
    {
    public:
        Queen(Colour colour, std::pair<int, int> pos);

        bool isMoveValid(int col, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;
    };
}