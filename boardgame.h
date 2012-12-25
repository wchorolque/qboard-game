#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <QtCore>
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
public:
    BoardGame();
    BoardGame(qint8 board_size, qint8 goal, qint8 pit);

    void setGoal(qint8 goal);
    qint8 getGoal();

    void setPit(qint8 pit);
    qint8 getPit();

    void setBoardSize(qint8 board_size);
    qint8 getBoardSize();

    qint8 rollDice();
};


#endif // BOARDGAME_H
