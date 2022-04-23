#include "piece.hpp"

namespace model {
    class Game {
    public:
        static Game runningGame;

        Game();
        ~Game();

        Piece* getLastMovedPiece() const;
    private:
        Piece* _lastMovedPiece;
    };
}