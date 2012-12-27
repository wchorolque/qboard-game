#include "game.h"

#include <cstdlib>
#include <QtGui>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    qint8 board_size;
    qint8 goal_position;
    qint8 pit_position;
    qint32 answer;

    while (true) {
        srand(time(0));

        cout << "Number of spaces: ";
        cout.flush();
        board_size = cin.readLine().toInt();
        goal_position = rand() % (board_size - 1) + 2;
        pit_position = rand() % (board_size - 1) + 2;
        cout << "Spaces: " << board_size << endl;
        cout << "Goal: " << goal_position << endl;
        cout << "Pit: " << pit_position << endl;

        cout.flush();
        Game* game = new Game(board_size, goal_position, pit_position);
        game->playGame();
        answer = QMessageBox::question(
                    0,                  // Parent
                    "Game End",         // Title
                    "Do you want to play another game?", // label
                    QMessageBox::Yes | QMessageBox::No
                    );
        if (QMessageBox::No == answer) {
            break;
        }
    }


    return EXIT_SUCCESS;
}
