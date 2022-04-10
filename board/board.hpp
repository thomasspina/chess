#pragma once

#include <memory>

namespace model
{
    class Board 
    {
    public:
        Board();
        ~Board() = default;

        std::unique_ptr<Piece>& getPiece(int col, int row) const;
        std::pair<int, int>& accessWhiteKingPos();
        std::pair<int, int>& accessBlackKingPos();
    private:
        std::unique_ptr<Piece> _board[8][8];
        std::pair<int, int> _blackKingPos;
        std::pair<int, int> _whiteKingPos;
    };
}