#include "piece.hpp"

namespace model
{
    template<typename T>
    class TempPiece
    {
    public:
        TempPiece(const Colour& colour, const std::pair<int, int>& pos);
        ~TempPiece();

        T* operator->();
    private:
        T* _piece;
    };
}