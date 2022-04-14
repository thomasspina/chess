#include "knight.hpp"

model::Knight::Knight(const Colour& colour, const std::pair<int, int>& pos) : Piece(colour, pos) {}


bool model::Knight::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;
    
    int currCol = _currPos.first;
    int currRow = _currPos.second;

    // check if there is a piece obstructing the path
    return ((currCol - 1 == col || currCol + 1 == col) && 
            (currRow - 2 == row || currRow + 2 == row)) 
            ||
            ((currCol + 2 == col || currCol - 2 == col) && 
            (currRow - 1 == row || currRow + 1 == row));
}


bool model::Knight::isPuttingKingInCheck(int kCol, int kRow, const Board& board)
{
    return isMoveValid(kCol, kRow, board);
}