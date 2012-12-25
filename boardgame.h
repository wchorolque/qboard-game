#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <QtCore>
class BoardGame
{
private:
    qint8 goal;
    qint8 pit;
    qint8 board_size;
public:
    BoardGame();
    BoardGame(qint8 board_size, qint8 goal, qint8 pit);

    void setGoal(qint8 goal);
    qint8 getGoal();

    void setPit(qint8 pit);
    qint8 getPit();

    void setBoardSize(qint8 board_size);
    qint8 getBoardSize();
};


#endif // BOARDGAME_H
