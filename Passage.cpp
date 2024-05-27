//
// Created by Richard Skarbez on 5/7/23.
//

#include "Passage.h"
#include "PassageDefaultEnterCommand.h"

std::string Passage::oppositeDirection(const std::string& s)
{
    if (s == "north")
        return "south";
    if (s == "south")
        return "north";
    if (s == "east")
        return "west";
    if (s == "west")
        return "east";
    if (s == "up")
        return "down";
    if (s == "down")
        return "up";
    if (s == "in")
        return "out";
    if (s == "out")
        return "in";
    return "unknown_direction";
}

void Passage::createBasicPassage(Room* from, Room* to, const std::string& direction, const bool bidirectional = true)
{
    std::string passageName = from->getName() + "_to_" + to->getName();
    const auto temp1 = std::make_shared<Passage>(passageName, "A totally normal passageway.", from, to);
    from->addPassage(direction, temp1);
    if (bidirectional)
    {
        std::string passageName2 = to->getName() + "_to_" + from->getName();
        const auto temp2 = std::make_shared<Passage>(passageName, "A totally normal passageway.", to, from);
        to->addPassage(oppositeDirection(direction), temp2);
    }
}

Passage::Passage(const std::string& n, const std::string& d, Room* from, Room* to)
    : Location(n, d), fromRoom(from), toRoom(to)
{
    setEnterCommand(std::make_shared<PassageDefaultEnterCommand>(this));
}

Passage::Passage(const std::string& n, const std::string& d, std::shared_ptr<Command> c, Room* from, Room* to)
    : Location(n, d, std::move(c)), fromRoom(from), toRoom(to)
{
}

void Passage::setFrom(Room* r)
{
    fromRoom = r;
}

Room* Passage::getFrom() const
{
    return fromRoom;
}

void Passage::setTo(Room* r)
{
    toRoom = r;
}

Room* Passage::getTo() const
{
    return toRoom;
}
