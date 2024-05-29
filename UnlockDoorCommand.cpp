//
// Created by FaZe-ltv on 5/21/2024.
//

#include "UnlockDoorCommand.h"
#include "Player.h"

void UnlockDoorCommand::execute()
{
    if (door->isLocked())
    {
        std::cout << "You unlocked the front door." << std::endl;
        door->unlockDoor();
        Player::dropItem("front-key");
        Passage::createBasicPassage(door->getFrom(), door->getTo(), "north", false);
        door->getFrom()->setDescription("You are standing in a lawn south of the manor. All windows are barred.\n"
            "The front door is now opened.\n");
    }
}
