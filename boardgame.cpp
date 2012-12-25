#include "boardgame.h"

BoardGame::BoardGame()
{
    this->setBoardSize(3);
    this->setGoal(3);
    this->setPit(2);
}

BoardGame::BoardGame(qint8 board_size, qint8 goal, qint8 pit)
{
    this->setBoardSize(board_size);
    this->setGoal(goal);
    this->setPit(pit);
}

void BoardGame::setBoardSize(qint8 board_size)
{
    if (board_size >= 0) {
        if (board_size < 3) {
            this->board_size = 3;
        } else {
            this->board_size = board_size;
        }
    } else {
        this->board_size = 3;
    }
}

qint8 BoardGame::getBoardSize()
{
    return this->board_size;
}

void BoardGame::setGoal(qint8 goal)
{
    if (goal > 1 && goal <= this->board_size) {
        this->goal = goal;
    } else {
        this->goal = 3;
    }
}
 qint8 BoardGame::getGoal()
 {
     return this->goal;
 }

 void BoardGame::setPit(qint8 pit)
 {
     if (pit > 1 && pit <= this->board_size) {
         this->pit = pit;
     } else {
         this->pit = 2;
     }
 }

 qint8 BoardGame::getPit()
 {
     return this->pit;
 }
