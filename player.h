#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
private:
    qint8 max_position;
    QString name;
    qint8 position;
    void init(QString name, qint8 max_position, qint8 position);

public:
    Player(QString name, qint8 max_position);
    Player(QString name, qint8 max_position, qint8 position);

    qint8 getMaxPosition() const;

    void setName(QString name);
    QString getName() const;

    void setPosition(qint8 position);
    qint8 getPosition() const;

    QString toString() const;
};

#endif // PLAYER_H
