//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullPassage.h"
#include "RoomDefaultEnterCommand.h"
#include "Room.h"

Room::Room(const std::string& n, const std::string& d) : Location(n, d)
{
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

Room::Room(const std::string& n, const std::string& d, std::shared_ptr<Command> c) : Location(n, d, std::move(c))
{
}

void Room::addItem(Item* i)
{
    items.push_back(i);
}

void Room::removeItem(const std::string& itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if ((*it)->getName() == itemName)
        {
            items.erase(it);
            return;
        }
    }
}

Item* Room::getItem(const std::string& itemName)
{
    for (const auto& item : items)
    {
        if (item->getName() == itemName)
        {
            return item;
        }
    }
    return nullptr;
}

Item* Room::retrieveItem(const std::string& itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if ((*it)->getName() == itemName)
        {
            Item* temp = *it;
            items.erase(it);
            return temp;
        }
    }
    return nullptr;
}

void Room::addPassage(const std::string& direction, std::shared_ptr<Passage> p)
{
    passageMap[direction] = std::move(p);
}

void Room::removePassage(const std::string& direction)
{
    if (passageMap.contains(direction))
    {
        passageMap.erase(direction);
    }
}

std::shared_ptr<Passage> Room::getPassage(const std::string& direction)
{
    if (passageMap.contains(direction))
    {
        return passageMap[direction];
    }
    std::cout << "It is impossible to go " << direction << "!\n";
    return std::make_shared<NullPassage>(this);
}
