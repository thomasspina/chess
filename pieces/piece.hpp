#include "enums.hpp"

class Piece 
{
public:
    Piece(Colour colour, int position[2]) : _colour(colour), _currPos(position) {};

    virtual void move(int column, int row) = 0;
    virtual bool isMoveValid(int column, int row) = 0;

    Colour getColour() const { return _colour; };
    int* getPos() const { return _currPos; };
protected:
    Colour _colour;
    int* _currPos;
};