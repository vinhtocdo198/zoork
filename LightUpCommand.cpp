//
// Created by FaZe-ltv on 5/22/2024.
//

#include "LightUpCommand.h"
#include "Passage.h"
#include <iostream>

void LightUpCommand::execute()
{
    std::cout << "You light up the way.\n";
    foyer->setDescription("The foyer looks brighter now. In front of you is a cold corridor\n"
        "and on your left is a spiral staircase, Italian style.\n");
    Passage::createBasicPassage(foyer, living_room, "north", true);
    Passage::createBasicPassage(foyer, piano, "up", true);
}
