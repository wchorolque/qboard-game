#include "player.h"

Player::Player(QString name, qint8 max_position)
{
    this->init(name, max_position, 0);
}

Player::Player(QString name, qint8 max_position, qint8 position)
{
    this->init(name, max_position, position);
}

void Player::init(QString name, qint8 position, qint8 max_position)
{
    this->setName(name);
    this->setPosition(position);
    this->max_position = max_position;
}

qint8 Player::getMaxPosition() const
{
    return this->max_position;
}

void Player::setName(QString name)
{
    if (name.trimmed().length() > 0) {
        this->name = name;
    } else {
        this->name = QString("Player");
    }
}

QString Player::getName() const
{
    return this->name;
}

void Player::setPosition(qint8 position)
{
    if (position >= 0 && position <= this->getMaxPosition()) {
        this->position = position;
    } else {
        this->position = 0;
    }
}

qint8 Player::getPosition() const
{
    return this->position;
}

