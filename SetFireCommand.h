//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef USEDURABLEITEMCOMMAND_H
#define USEDURABLEITEMCOMMAND_H
#include "Command.h"
#include "Item.h"
#include "Room.h"

class SetFireCommand : public Command
{
public:
    explicit SetFireCommand(Item* o, Room* f, Room* lv, Room* p)
        : Command(o), oil_lamp(o), foyer(f), living_room(lv), piano(p)
    {
    }

    void execute() override;

private:
    Item* oil_lamp;
    Room* foyer;
    Room* living_room;
    Room* piano;
};

#endif //USEDURABLEITEMCOMMAND_H
