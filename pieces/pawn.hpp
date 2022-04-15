#include "piece.hpp"

namespace model
{
    class Pawn : public Piece
    {
    public:
        Pawn(const Colour& colour, const std::pair<int, int>& pos);

        bool isMoveValid(int col, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;

        void move(int col, int row) override;

        int getMoves() const;
        void incrementMoves();
        bool isMarkedForDeath() const;
        void unsetMovedLast(); // if another piece has moved then moved last is unset
    private:
        bool _movedTwo = false; // used to check whether he moved 2 squares in the begining
        bool _movedLast = false; // used for en passant to check whether the piece is valid
        bool _markedForDeath = false; // used to determine weather they got killed by en passant
    };
}