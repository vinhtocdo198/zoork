//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef PLAYPIANOCOMMAND_H
#define PLAYPIANOCOMMAND_H

#include "Command.h"
#include "Item.h"

class PlayPianoCommand : public Command
{
public:
    explicit PlayPianoCommand(Item* i) : Command(i)
    {
    }

    void execute() override;
};

#endif //PLAYPIANOCOMMAND_H
