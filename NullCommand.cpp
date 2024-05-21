//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullCommand.h"
#include <iostream>

void NullCommand::execute()
{
    std::cout << "Nothing happens.\n";
}
