#include "piece.hpp"

namespace model 
{
    struct TooManyKings {};

    class King : public Piece 
    {
    public:
        King(const Colour& colour, const std::pair<int, int>&pos);
        ~King();

        bool isMoveValid(int column, int row, const Board& board) override;
        bool isPuttingKingInCheck(int kCol, int kRow, const Board& board) override;
        bool isPuttingSelfInCheck(int col, int row, const Board& board);
    private:
        static int kingCounter;
    };
}