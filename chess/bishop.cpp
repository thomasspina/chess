#include "bishop.hpp"

#include <math.h>

model::Bishop::Bishop(const Colour& colour, const std::pair<int, int>& pos) : Piece(colour, pos) {}


bool model::Bishop::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;
    
    int currCol = _currPos.first;
    int currRow = _currPos.second;

    // check if there is a piece obstructing the path
    if (currCol < col && currRow < row) {
        for (int i = 1; currCol + i < col && currRow + i < row; i++) {
            if (board.getPiece(currCol + i, currRow + i) != nullptr)
                return false;
        }
    }
    else if (currCol > col && currRow > row) {
        for (int i = 1; currCol - i > col && currRow - i > row; i--) {
            if (board.getPiece(currCol - i, currRow - i) != nullptr)
                return false;
        }
        return true;
    }
    else if (currCol < col && currRow > row) {
        for (int i = 1; currCol + i < col && currRow - i > row; i++) {
            if (board.getPiece(currCol + i, currRow - i) != nullptr)
                return false;
        }
        return true;
    }
    else if (currCol > col && currRow < row) {
        for (int i = 1; currCol + i < col && currRow + i < row; i++) {
            if (board.getPiece(currCol + i, currRow + i) != nullptr)
                return false;
        }
        return true;
    }

    return abs(col - currCol) == abs(row - currRow);
}


bool model::Bishop::isPuttingKingInCheck(int kCol, int kRow, const Board& board)
{
    return isMoveValid(kCol, kRow, board);
}