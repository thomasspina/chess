#include "pawn.hpp"
#include "game.hpp"

model::Pawn::Pawn(const Colour& colour, const std::pair<int, int>& pos) : Piece(colour, pos) {}


bool model::Pawn::isMarkedForDeath() const { return _markedForDeath; }


void model::Pawn::move(int col, int row) 
{   
    Piece::move(col, row);
}


bool model::Pawn::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;
    
    int currCol = _currPos.first;
    int currRow = _currPos.second;
    int moveDir;
    bool hasMoved;

    // set direction of move (down or up the board) and check if in original pos
    if (_colour == model::Colour::WHITE) {
        if (currRow == 6) 
            hasMoved = false;
        else 
            hasMoved = true;
        moveDir = -1;
    }   
    else {
        if (currRow == 1)
            hasMoved = false;
        else
            hasMoved = true;
        moveDir = 1;
    }

    // make a jump of two
    if (!hasMoved && currCol == col && currRow + (2 * moveDir) == row) {
        if (board.getPiece(col, row) == nullptr && board.getPiece(col, row + (-1 * moveDir)) == nullptr)
            return true;
    }

    // take a piece diagonally 
    if ((currCol + 1 == col || currCol - 1 == col) && currRow + moveDir == row) {
        if (board.getPiece(col, row) != nullptr)
            return true;
    }

    // move one space in front
    if (currCol == col && currRow + moveDir == row) {
        if (board.getPiece(col, row) == nullptr)
            return true;
    }

    // check for en passant
    if ((currCol + 1 == col || currCol - 1 == col) && currRow + moveDir == row) {
        if (Pawn* piece = dynamic_cast<Pawn*>(board.getPiece(col, currRow).get())) {
            
            // check whether the pawn adjacent moved two and is the last piece that moved
            if (piece->_movedTwo &&
                model::Game::runningGame->getLastMovedPiece()->getPos() == piece->getPos()) {

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
