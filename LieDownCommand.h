//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef LIEDOWNCOMMAND_H
#define LIEDOWNCOMMAND_H
#include "Command.h"
#include "Item.h"

class LieDownCommand : public Command
{
public:
    explicit LieDownCommand(Item* i) : Command(i)
    {
    }

    void execute() override;
};

#endif //LIEDOWNCOMMAND_H
