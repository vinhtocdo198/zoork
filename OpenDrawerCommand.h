//
// Created by FaZe-ltv on 5/23/2024.
//

#ifndef OPENDRAWERCOMMAND_H
#define OPENDRAWERCOMMAND_H

#include "UnlockChestCommand.h"

class OpenDrawerCommand : public Command
{
public:
    explicit OpenDrawerCommand(Item* d) : Command(d), drawer(d)
    {
    }

    void execute() override;

private:
    Item* drawer;
};

#endif //OPENDRAWERCOMMAND_H
