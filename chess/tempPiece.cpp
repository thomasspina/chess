#include "tempPiece.hpp"

template<typename T>
model::TempPiece<T>::TempPiece(const Colour& colour, const std::pair<int, int>& pos)
{
    _piece = new T(colour, pos);
}

template<typename T>
model::TempPiece<T>::~TempPiece()
{
    delete _piece;
}

template<typename T>
T* model::TempPiece<T>::operator->() { return _piece; }