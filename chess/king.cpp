#include "king.hpp"

int model::King::kingCounter = 0;


model::King::King(const Colour& colour, const std::pair<int, int>& pos) : Piece(colour, pos) 
{
    if (kingCounter == 2) 
        throw TooManyKings();

    kingCounter++;
}


model::King::~King() { kingCounter--; }


bool model::King::isPuttingKingInCheck(int kCol, int kRow, const Board& board)
{
    if (!Piece::isMoveValid(kCol, kRow, board))
        return false;

    int currCol = _currPos.first;
    int currRow = _currPos.second; 

    return (currCol - 1 == kCol && currRow == kRow) ||
        (currCol + 1 == kCol && currRow == kRow) ||
        (currCol == kCol && currRow - 1 == kRow) ||
        (currCol == kCol && currRow + 1 == kRow) || 
        (currCol + 1 == kCol && currRow + 1 == kRow) ||
        (currCol + 1 == kCol && currRow - 1 == kRow) ||
        (currCol - 1 == kCol && currRow - 1 == kRow) ||
        (currCol - 1 == kCol && currRow + 1 == kRow);
}


bool model::King::isPuttingSelfInCheck(int col, int row, const Board& board)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (const std::unique_ptr<Piece>& piece = board.getPiece(i, j)) {

                if (piece->getColour() != _colour && piece->isPuttingKingInCheck(col, row, board))
                    return true;
            }
        }
    }

    return false;
}


bool model::King::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;

    int currCol = _currPos.first;
    int currRow = _currPos.second;

    if (isPuttingSelfInCheck(col, row, board))
        return false;

    return (currCol - 1 == col && currRow == row) ||
        (currCol + 1 == col && currRow == row) ||
        (currCol == col && currRow - 1 == row) ||
        (currCol == col && currRow + 1 == row) || 
        (currCol + 1 == col && currRow + 1 == row) ||
        (currCol + 1 == col && currRow - 1 == row) ||
        (currCol - 1 == col && currRow - 1 == row) ||
        (currCol - 1 == col && currRow + 1 == row);
}
