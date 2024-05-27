//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef INSTALLWATCHHANDCOMMAND_H
#define INSTALLWATCHHANDCOMMAND_H

#include "Command.h"
#include "Item.h"

class InstallClockHandCommand : public Command
{
public:
    explicit InstallClockHandCommand(Item* c) : Command(c), clock(c)
    {
    }

    void execute() override;

private:
    Item* clock;
};

#endif //INSTALLWATCHHANDCOMMAND_H
