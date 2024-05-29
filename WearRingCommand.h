//
// Created by FaZe-ltv on 5/23/2024.
//

#ifndef WEARRINGCOMMAND_H
#define WEARRINGCOMMAND_H

#include "Command.h"
#include "Room.h"

class WearRingCommand : public Command
{
public:
    explicit WearRingCommand(Room* k): Command(k), kitchen(k)
    {
    }

    void execute() override;

private:
    Room* kitchen;
};

#endif //WEARRINGCOMMAND_H
