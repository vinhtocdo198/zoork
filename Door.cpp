//
// Created by FaZe-ltv on 5/21/2024.
//

#include "Door.h"

#include <utility>

Door::Door(const std::string& n, const std::string& d, Room* from, Room* to, const bool locked)
    : Passage(n, d, from, to), locked(locked)
{
}

Door::Door(const std::string& n, const std::string& d, std::shared_ptr<Command> c, Room* from, Room* to, const bool locked)
    : Passage(n, d, std::move(c), from, to), locked(locked)
{
}

bool Door::isLocked() const
{
    return locked;
}

void Door::unlock()
{
    locked = false;
}

void Door::lock()
{
    locked = true;
}
