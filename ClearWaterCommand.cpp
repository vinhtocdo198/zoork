//
// Created by FaZe-ltv on 5/22/2024.
//

#include "ClearWaterCommand.h"
#include <iostream>

void ClearWaterCommand::execute()
{
    std::cout << "You clear the water from the sink, then something falls to the ground with a clatter.\n";
    laundry_room->getItem("sink")->setDescription("A dry sink.");
    laundry_room->getItem("sink")->setInteractive(false);
    laundry_room->setDescription("You are now in the laundry room. There's nothing other than a [sink] and a\n"
        "[washing-machine]... and a wet kitchen [knife]. Fortunately, I wasn't scratched.\n");
}
