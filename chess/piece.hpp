#pragma once

#include <utility>

#include "board.hpp"

namespace model 
{
    enum class Colour 
    {
        WHITE,
        BLACK
    };

    class Piece 
    {
    public:
        Piece(const Colour& colour, const std::pair<int, int>& pos);
        virtual ~Piece() = default;

        virtual void move(int col, int row);

        virtual bool isMoveValid(int col, int row, const Board& board);
        virtual bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) = 0;

        Colour getColour() const;
        std::pair<int, int> getPos() const;
    protected:
        Colour _colour;
        std::pair<int, int> _currPos;
    };
}
    
