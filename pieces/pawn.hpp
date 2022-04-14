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
    private:
        bool _movedTwo = false; // used to check whether he moved 2 squares in the begining
        int _nMoves;
        bool _markedForDeath = false; // used to determine weather they got killed by en passant
    };
}