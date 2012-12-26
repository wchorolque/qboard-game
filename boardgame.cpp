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

    this->player01 = new Player("Player 1", board_size);
    this->player02 = new Player("Player 2", board_size);

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


Player* BoardGame::getPlayer(qint8 player) const
{
    switch(player) {
        case 1: return this->player01;
        case 2: return this->player02;
    }

    return 0;
}

qint8 BoardGame::rollDice() const
{
    qint8 dice;
    dice = rand() % 6 + 1;

    return dice;
}

qint8 BoardGame::movePlayer(qint8 player)
{
    qint8 dice1 = this->rollDice();
    qint8 dice2 = this->rollDice();

    Player* player = this->getPlayer(player);

    qint8 current_position = player->getPosition();
    qint8 dices_sum = dice1 + dice2;
    qint8 new_position = (current_position + dices_sum) % this->BoardGame;

    player->setPosition(new_position);

    return new_position;
}
