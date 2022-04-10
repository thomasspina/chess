#include "king.hpp"

model::King::King(Colour colour, std::pair<int, int> pos) : Piece(colour, pos) {}


bool model::King::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;

    int currCol = _currPos.first;
    int currRow = _currPos.second;

    // TODO check if king is in check at that position
        // probably do that check on the board. 
        // since we have to check all other pieces pretty much
    
    // TODO check if it gets within one square of enemy king.


    return (currCol - 1 == col && currRow == row) ||
        (currCol + 1 == col && currRow == row) ||
        (currCol == col && currRow - 1 == row) ||
        (currCol == col && currRow + 1 == row) || 
        (currCol + 1 == col && currRow + 1 == row) ||
        (currCol + 1 == col && currRow - 1 == row) ||
        (currCol - 1 == col && currRow - 1 == row) ||
        (currCol - 1 == col && currRow + 1 == row);
}