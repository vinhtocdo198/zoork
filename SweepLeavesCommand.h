//
// Created by FaZe-ltv on 5/21/2024.
//

#ifndef SWEEPLEAVESCOMMAND_H
#define SWEEPLEAVESCOMMAND_H

#include "Room.h"
#include "Command.h"

class SweepLeavesCommand : public Command
{
public:
    explicit SweepLeavesCommand(Room* r) : Command(r), front_yard(r)
    {
    }

    void execute() override;

private:
    Room* front_yard;
};

#endif // SWEEPLEAVESCOMMAND_H
