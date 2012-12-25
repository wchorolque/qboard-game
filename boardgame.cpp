#include "boardgame.h"

BoardGame::BoardGame()
{
    this->setBoardSize(BoardGame::DEFAULT_BOARD_SIZE);
    this->setGoal(BoardGame::DEFAULT_GOAL);
    this->setPit(BoardGame::DEFAULT_PIT);
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
        if (board_size < BoardGame::DEFAULT_BOARD_SIZE) {
            this->board_size = BoardGame::DEFAULT_BOARD_SIZE;
        } else {
            this->board_size = board_size;
        }
    } else {
        this->board_size = BoardGame::DEFAULT_BOARD_SIZE;
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
        this->goal = BoardGame::DEFAULT_GOAL;
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
         this->pit = BoardGame::DEFAULT_PIT;
     }
 }

 qint8 BoardGame::getPit()
 {
     return this->pit;
 }
