//
// Created by FaZe-ltv on 5/22/2024.
//

#include "SetFireCommand.h"
#include "Passage.h"
#include <iostream>

void SetFireCommand::execute()
{
    std::cout << "You set fire to the oil lamp.\n";
    oil_lamp->setObtainable(true);
    oil_lamp->setDescription("An oil lamp that is on fire.");
}
