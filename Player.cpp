//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"

Player *Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room *r)
{
    currentRoom = r;
}

Room *Player::getCurrentRoom() const
{
    return currentRoom;
}
