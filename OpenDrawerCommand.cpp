//
// Created by FaZe-ltv on 5/23/2024.
//

#include "OpenDrawerCommand.h"
#include <iostream>

void OpenDrawerCommand::execute()
{
    std::cout << "You open the drawer.\n";
    drawer->setDescription("An opened drawer with some expired items, bandages, and a wooden piece\n"
        "of alphabetical letter [a] inside.");
}
