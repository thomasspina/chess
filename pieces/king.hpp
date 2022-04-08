#include "piece.hpp"

class King : virtual public Piece 
{
public:
    
    bool isInCheck() const { return inCheck; };
private:
    bool inCheck;
};