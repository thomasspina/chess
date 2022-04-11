#include "queen.hpp"
#include "bishop.hpp"
#include "rook.hpp"

model::Queen::Queen(Colour colour, std::pair<int, int> pos) : Piece(colour, pos) {}


bool model::Queen::isMoveValid(int col, int row, const Board& board)
{
    if (!Piece::isMoveValid(col, row, board))
        return false;

    return Bishop::isMoveValid(col, row, board) || Rook::isMoveValid(col, row, board);
}


bool model::Queen::isPuttingKingInCheck(int kCol, int kRow, const Board& board) 
{ 
    return isMoveValid(kCol, kRow, board); 
}