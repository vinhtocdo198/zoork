//
// Created by FaZe-ltv on 5/23/2024.
//

#ifndef REARRANGEBOOKCOMMAND_H
#define REARRANGEBOOKCOMMAND_H

#include "Bookshelf.h"
#include "Command.h"
#include "Room.h"

class RearrangeBookCommand : public Command
{
public:
    explicit RearrangeBookCommand(Bookshelf* b, Room* r) : Command(b), living_room(r)
    {
    }

    void execute() override;

private:
    Room* living_room;
};

#endif //REARRANGEBOOKCOMMAND_H
