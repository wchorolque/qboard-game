#include <QTextStream>
#include "game.h"

Game::Game(qint8 board_size, qint8 goal, qint8 pit)
{
    this->init(board_size, goal, pit);
}

Game::~Game()
{
    if (0 != board) {
        delete board;
    }
}

void Game::init(qint8 board_size, qint8 goal, qint8 pit)
{
    this->board = new BoardGame(board_size, goal, pit);
}

void Game::configure(qint8 board_size, qint8 goal, qint8 pit)
{
    this->board->setBoardSize(board_size);
    this->board->setGoal(goal);
    this->board->setPit(pit);

    this->board->getPlayer(1)->setName("Player 1");
    this->board->getPlayer(2)->setName("Computer");
}

void Game::playGame(bool automatic)
{
    QTextStream cout(stdout);
    QTextStream cin(stdout);

    quint8 player1_position = board->getPlayer(1)->getPosition();
    quint8 player2_position = board->getPlayer(2)->getPosition();
    quint8 goal_position = board->getGoal();
    quint8 pit_position = board->getPit();

    cout << board->getPlayer(1)->toString() << endl;
    cout << board->getPlayer(2)->toString() << endl;

    while (true) {
        this->board->movePlayer(1);
        player1_position = this->board->getPlayer(1)->getPosition();
        cout << this->board->getPlayer(1)->toString() << endl;

        if (goal_position == player1_position) {
            cout << "The player 1 win" << endl;
            break;
        } else if (pit_position == player1_position) {
            cout << "The player 1 lose" << endl;
            break;
        }

        this->board->movePlayer(2);
        player2_position = this->board->getPlayer(2)->getPosition();
        cout << this->board->getPlayer(2)->toString() << endl;

        if (goal_position == player2_position) {
            cout << "The player 2 win" << endl;
            break;
        } else if (pit_position == player2_position) {
            cout << "The player 2 lose " << endl;
            break;
        }

        if (false == automatic) {
            cin.readLine();
        }
    }
}
