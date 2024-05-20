//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullCommand.h"
#include "NullRoom.h"
#include <memory>

NullRoom::NullRoom() : Room("Nowhere", "This is a nonplace.", std::make_shared<NullCommand>())
{
}
