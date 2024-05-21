//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"
#include <iostream>

Player* Player::playerInstance = nullptr;
std::vector<Item*> Player::inventory;

void Player::setCurrentRoom(Room* r)
{
    currentRoom = r;
}

Room* Player::getCurrentRoom() const
{
    return currentRoom;
}

void Player::takeItem(Item* item)
{
    inventory.push_back(item);
}

void Player::dropItem(const std::string& itemName)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if ((*it)->getName() == itemName)
        {
            inventory.erase(it);
            return;
        }
    }
}

Item* Player::getItem(const std::string& itemName)
{
    for (const auto& item : inventory)
    {
        if (item->getName() == itemName)
        {
            return item;
        }
    }
    return nullptr;
}

std::vector<Item*> Player::getInventory()
{
    return inventory;
}
