//
// Created by FaZe-ltv on 5/21/2024.
//

#include "SweepLeavesCommand.h"
#include "Player.h"
#include "UnlockDoorCommand.h"

void SweepLeavesCommand::execute()
{
    std::cout << "You sweep the leaf pile away and see a shiny tiny [front-key] and a silver [lighter].\n";
    Player::dropItem("broom");
    front_yard->removeItem("leaf-pile");
    front_yard->setDescription(
        "You are standing in a lawn south of the manor. All windows are barred. There is\n"
        "a rusty lock on the front door.\n");
}
