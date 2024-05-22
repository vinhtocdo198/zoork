//
// Created by FaZe-ltv on 5/22/2024.
//

#ifndef REMOVESTITCHESCOMMAND_H
#define REMOVESTITCHESCOMMAND_H
#include "Command.h"
#include "Item.h"

class RemoveStitchesCommand : public Command
{
public:
    explicit RemoveStitchesCommand(Item* k) : Command(k), knife(k)
    {
    }

    void execute() override;

private:
    Item* knife;
};

#endif //REMOVESTITCHESCOMMAND_H
