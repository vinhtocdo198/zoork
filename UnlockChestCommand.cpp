//
// Created by FaZe-ltv on 5/22/2024.
//

#include "UnlockChestCommand.h"
#include "Player.h"

void UnlockChestCommand::execute()
{
    std::string passcode;
    std::cout << "You try to unlock the chest.\n";
    bool locked = true;
    while (locked)
    {
        std::cout << "Enter the passcode (or 'q' to exit):";
        std::getline(std::cin, passcode);

        if (passcode == "q")
        {
            std::cout << "You stop trying to unlock the chest.\n";
            break;
        }

        if (passcode == "1809")
        {
            std::cout << "Click! You open the chest.\n";
            locked = false;
        }
        else
        {
            std::cout << "Nothing happens.\n";
        }
    }
    if (!locked)
    {
        chest->setInteractive(false);
        chest->setDescription(
            "An opened wooden chest, inside are two wooden pieces of alphabetical letters: [i] and [l].");
    }
}
