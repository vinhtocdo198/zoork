//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef OPENCHESTCOMMAND_H
#define OPENCHESTCOMMAND_H

#include "Item.h"

class UnlockChestCommand : public Command
{
public:
    explicit UnlockChestCommand(Item* c) : Command(c), chest(c)
    {
    }

    void execute() override;

private:
    Item* chest;
};

#endif //OPENCHESTCOMMAND_H
