#include "piece.hpp"

namespace model 
{
    struct TooManyKings {};

    class King : public Piece 
    {
    public:
        King(Colour colour, std::pair<int, int> pos);

        bool isMoveValid(int column, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;
        bool isPuttingSelfInCheck(int col, int row, const Board& board);
    private:
        static int kingCounter;
    };
}