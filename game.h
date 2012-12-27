#ifndef GAME_H
#define GAME_H

#include <QString>
#include "boardgame.h"
#include "player.h"

class Game
{
private:
    BoardGame* board;

public:
    Game(qint8 board_size, qint8 goal, qint8 pit);
    ~Game();
    void init(qint8 board_size, qint8 goal, qint8 pit);
    void playGame(bool automatic=false);
    void configure(qint8 board_size, qint8 goal, qint8 pit);

};

#endif // GAME_H
