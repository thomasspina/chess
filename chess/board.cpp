#include "board.hpp"
#include "king.hpp"


model::Board::Board() {}

const std::unique_ptr<model::Piece>& model::Board::getPiece(int col, int row) const
{
    return _board[col][row];
}
