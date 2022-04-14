#include "rook.hpp"

model::Rook::Rook(const Colour& colour, const std::pair<int, int>& pos) : Piece(colour, pos) {}


bool model::Rook::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;


    int currCol = _currPos.first;
    int currRow = _currPos.second;

    // check if there is a piece obstructing the path
    if (currCol == col) {
        int i = currRow < row ? currRow : row;
        int lim = currRow < row ? row : currRow;

        i++;
        for (; i < lim; i++) {
            if (board.getPiece(col, i) != nullptr)
                return false;
        }
        return true;
    } 

    else if (currRow == row) {
        int i = currCol < col ? currCol : col;
        int lim = currCol < col ? col : currCol;

        i++;
        for (; i < lim; i++) {
            if (board.getPiece(i, row) != nullptr)
                return false;
        }
        return true;
    }

    return false;
}


bool model::Rook::isPuttingKingInCheck(int kCol, int kRow, const Board& board) 
{ 
    return isMoveValid(kCol, kRow, board); 
}