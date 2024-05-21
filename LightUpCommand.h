//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef LIGHTUPCOMMAND_H
#define LIGHTUPCOMMAND_H
#include "Command.h"
#include "Item.h"
#include "Room.h"

class LightUpCommand : public Command
{
public:
    explicit LightUpCommand(Item* o, Room* f, Room* lv, Room* p)
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

#endif //LIGHTUPCOMMAND_H
