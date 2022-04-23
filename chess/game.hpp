#pragma once

#include "piece.hpp"


// TODO use singleton design pattern
namespace model {

    class Game {
    public:
        static Game* runningGame;

        Game();
        ~Game();

        Piece* getLastMovedPiece() const;
    private:
        Piece* _lastMovedPiece;
    };
}
