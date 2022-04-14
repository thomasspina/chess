#include "pawn.hpp"

model::Pawn::Pawn(Colour colour, std::pair<int, int> pos) : Piece(colour, pos) {}


int model::Pawn::getMoves() const { return _nMoves; }


void model::Pawn::incrementMoves() { _nMoves++; }


bool model::Pawn::isMarkedForDeath() const { return _markedForDeath; }


void model::Pawn::move(int col, int row) 
{   
    Piece::move(col, row);
    _nMoves++;
}



bool model::Pawn::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;
    
    int currCol = _currPos.first;
    int currRow = _currPos.second;

    if (_nMoves == 0 && currCol == col && currRow + 2 == row) {
        if (board.getPiece(col, row) == nullptr && board.getPiece(col, row - 1) == nullptr)
            return true;
    }

    if ((currCol + 1 == col || currCol - 1 == col) && currRow + 1 == row) {
        if (board.getPiece(col, row) != nullptr)
            return true;
    }

    if (currCol == col && currRow + 1 == row) {
        if (board.getPiece(col, row) == nullptr)
            return true;
    }

    // two ifs below are for en passant
    if (currCol + 1 == col && currRow + 1 == row) {
        if (Pawn* piece = dynamic_cast<Pawn*>(board.getPiece(col, currRow).get())) {

            if (piece->_movedTwo && piece->_nMoves == 1) {
                piece->_markedForDeath = true;
                return true;
            }
            
        }
    }

    if (currCol - 1 == col && currRow + 1 == row) {
        if (Pawn* piece = dynamic_cast<Pawn*>(board.getPiece(col, currRow).get())) {

            if (piece->_movedTwo && piece->_nMoves == 1) {
                piece->_markedForDeath = true;
                return true;
            }
        }
    }


    return false;
}

bool model::Pawn::isPuttingKingInCheck(int kCol, int kRow, const Board& board)
{
    return isMoveValid(kCol, kRow, board);
}