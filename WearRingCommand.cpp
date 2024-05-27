//
// Created by FaZe-ltv on 5/23/2024.
//

#include "WearRingCommand.h"

void WearRingCommand::execute()
{
    std::cout << "You wear the ring. Suddenly, a loud noise echoes from the kitchen, shaking the walls around you.\n";
    kitchen->setDescription(
        "You are now in the kitchen. It is a total mess, with a [dining-table] covered in\n"
        "plates of rotten food. A [fridge] stands in the corner, but the stove has somehow\n"
        "turned into a [tunnel].\n");
    kitchen->removeItem("stove");
}
