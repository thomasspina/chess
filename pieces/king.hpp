#include "piece.hpp"

namespace model 
{
    class King : public Piece 
    {
    public:
        King(Colour colour, std::pair<int, int> pos);

        bool isMoveValid(int column, int row, const Board& board) override;
    };
}