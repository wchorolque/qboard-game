#include "boardgame.h"

BoardGame::BoardGame()
{
    this->init(
                BoardGame::DEFAULT_BOARD_SIZE,
                BoardGame::DEFAULT_GOAL,
                BoardGame::DEFAULT_PIT
                );
}

BoardGame::BoardGame(qint8 board_size, qint8 goal, qint8 pit)
{
    this->init(board_size, goal, pit);
}

void BoardGame::init(qint8 board_size, qint8 goal, qint8 pit)
{
    this->setBoardSize(board_size);
    this->setGoal(goal);
    this->setPit(pit);

    this->setNamePlayer01("Player 01");
    this->setNamePlayer02("Player 02");

    this->setPositionPlayer01(0);
    this->setPositionPlayer02(0);
    srand(time(0));
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

qint8 BoardGame::getBoardSize() const
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
 qint8 BoardGame::getGoal() const
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

 qint8 BoardGame::getPit() const
 {
     return this->pit;
 }

void BoardGame::setPositionPlayer01(qint8 position)
{
    if (position >= 0 && position <= this->board_size) {
        this->position_player01 = position;
    }
}

qint8 BoardGame::getPositionPlayer01 () const
{
    return this->position_player01;
}

void BoardGame::setPositionPlayer02(qint8 position)
{
    if (position >= 0 && position <= this->board_size) {
        this->position_player02 = position;
    }
}

qint8 BoardGame::getPositionPlayer02() const
{
    return this->position_player02;
}

void BoardGame::setNamePlayer01(QString name)
{
    if (name.trimmed().length() > 0) {
        this->name_player01 = name;
    }
}

QString BoardGame::getNamePlayer01() const
{
    return this->name_player01;
}

void BoardGame::setNamePlayer02(QString name)
{
    if (name.trimmed().length() > 0) {
        this->name_player02 = name;
    }
}

QString BoardGame::getNamePlayer02() const
{
    return this->name_player02;
}
