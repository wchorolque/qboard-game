#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <QtCore>

#include "player.h"

class BoardGame
{
private:
    static const qint8 DEFAULT_BOARD_SIZE = 5;
    static const qint8 DEFAULT_GOAL = 5;
    static const qint8 DEFAULT_PIT = 4;
    // Default value 5
    qint8 board_size;
    // Default value 5
    qint8 goal;
    // Default value 4
    qint8 pit;

    Player* player01;
    Player* player02;

    void init(qint8 board_size, qint8 goal, qint8 pit);
public:
    BoardGame ();
    ~BoardGame ();
    BoardGame (qint8 board_size, qint8 goal, qint8 pit);

    void setGoal (qint8 goal);
    qint8 getGoal () const;

    void setPit (qint8 pit);
    qint8 getPit () const;

    void setBoardSize (qint8 board_size);
    qint8 getBoardSize () const;

    Player* getPlayer(qint8 player) const;

    qint8 rollDice() const;
    qint8 movePlayer(qint8 number_player);
};


#endif // BOARDGAME_H
