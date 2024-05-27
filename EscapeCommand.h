//
// Created by FaZe-ltv on 5/23/2024.
//

#ifndef ESCAPECOMMAND_H
#define ESCAPECOMMAND_H

#include "Command.h"
#include "Item.h"

class EscapeCommand : public Command
{
public:
    explicit EscapeCommand(Item* t) : Command(t)
    {
    }

    void execute() override;
};

#endif //ESCAPECOMMAND_H
