#include "piece.hpp"

namespace model
{
    class Pawn : public Piece
    {
    public:
        Pawn(Colour colour, std::pair<int, int> pos);
        Pawn(Colour colour, std::pair<int, int> pos, int nMoves);

        bool isMoveValid(int col, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;

        void move(int col, int row) override;

        int getMoves() const;
        void incrementMoves();
    private:
        int _nMoves = 0;
    };
}

// TODO how tf to do promotion?