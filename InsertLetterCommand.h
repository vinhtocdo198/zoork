//
// Created by FaZe-ltv on 5/23/2024.
//

#ifndef INSTALLLETTERCOMMAND_H
#define INSTALLLETTERCOMMAND_H

#include "Command.h"
#include "Item.h"

class InsertLetterCommand : public Command
{
public:
    explicit InsertLetterCommand(Item* l): Command(l), letter(l)
    {
    }

    void execute() override;

private:
    Item* letter;
};

#endif //INSTALLLETTERCOMMAND_H
