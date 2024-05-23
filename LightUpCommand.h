//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef LIGHTUPCOMMAND_H
#define LIGHTUPCOMMAND_H
#include "Command.h"
#include "Item.h"

class LightUpCommand : public Command
{
public:
    explicit LightUpCommand(Item* o) : Command(o)
    {
    }

    void execute() override;
};

#endif //LIGHTUPCOMMAND_H
