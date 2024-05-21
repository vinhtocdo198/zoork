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
    explicit SetFireCommand(Item* l, Item* o) : Command(l), lighter(l), oil_lamp(o)
    {
    }

    void execute() override;

private:
    Item* lighter;
    Item* oil_lamp;
};

#endif //USEDURABLEITEMCOMMAND_H
