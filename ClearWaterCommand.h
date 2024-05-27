//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef CLEARWATERCOMMAND_H
#define CLEARWATERCOMMAND_H

#include "Command.h"
#include "Room.h"

class ClearWaterCommand : public Command
{
public:
    explicit ClearWaterCommand(Room* r) : Command(r), laundry_room(r)
    {
    }

    void execute() override;

private:
    Room* laundry_room;
};

#endif //CLEARWATERCOMMAND_H
