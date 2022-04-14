#include <memory>

#include "piece.hpp"


model::Piece::Piece(const Colour& colour, const std::pair<int, int>& pos) : _colour(colour), _currPos(pos) {}


model::Colour model::Piece::getColour() const { return _colour; }


std::pair<int, int> model::Piece::getPos() const { return _currPos; }


void model::Piece::move(int col, int row) { _currPos = std::make_pair(col, row); }


bool model::Piece::isMoveValid(int col, int row, const Board& board) 
{ 
    // check if it goes out of the board
    if (col > 7 || col < 0 || row > 7 || row < 0) 
        return false;

    // check if there is a piece of the same colour there
    if (const std::unique_ptr<Piece>& piece = board.getPiece(col, row)) {
        if (piece->getColour() == this->getColour())
            return false;
    }
}

