//
// Created by FaZe-ltv on 5/21/2024.
//

#ifndef UNLOCKDOORCOMMAND_H
#define UNLOCKDOORCOMMAND_H

#include "Command.h"
#include "Door.h"
#include "Room.h"

class UnlockDoorCommand : public Command
{
public:
    explicit UnlockDoorCommand(Door* d) : Command(d), door(d)
    {
    }

    void execute() override;

private:
    Door* door;
};

#endif //UNLOCKDOORCOMMAND_H
