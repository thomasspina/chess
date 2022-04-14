#include "queen.hpp"
#include "bishop.hpp"
#include "rook.hpp"

model::Queen::Queen(const Colour& colour, const std::pair<int, int>& pos) 
    : Piece(colour, pos), Rook(colour, pos), Bishop(colour, pos)
{}


bool model::Queen::isMoveValid(int col, int row, const Board& board)
{
    return Bishop::isMoveValid(col, row, board) || Rook::isMoveValid(col, row, board);
}


bool model::Queen::isPuttingKingInCheck(int kCol, int kRow, const Board& board) 
{ 
    return isMoveValid(kCol, kRow, board); 
}