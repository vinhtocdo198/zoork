//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"
#include <algorithm>
#include <sstream>
#include <ranges>

ZOOrkEngine::ZOOrkEngine(const std::shared_ptr<Room>& start)
{
    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run()
{
    while (!gameOver)
    {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);

        // Handle empty input
        if (input.empty())
        {
            std::cout << "Please enter a command.\n\n";
            continue;
        }

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        const auto arguments = std::vector(words.begin() + 1, words.end());

        if (command == "go")
        {
            handleGoCommand(arguments);
        }
        else if (command == "look" || command == "l")
        {
            handleLookCommand(arguments);
        }
        else if (command == "take" || command == "t")
        {
            handleTakeCommand(arguments);
        }
        else if (command == "drop" || command == "d")
        {
            handleDropCommand(arguments);
        }
        else if (command == "quit" || command == "q")
        {
            handleQuitCommand(arguments);
        }
        else if (command == "inventory" || command == "i")
        {
            handleInventoryCommand();
        }
        else if (command == "use" || command == "u")
        {
            handleUseCommand(arguments);
        }
        else if (command == "interact" || command == "f")
        {
            handleInteractCommand(arguments);
        }
        else if (command == "help" || command == "h")
        {
            std::cout << "Available commands:\n"
                "go [direction] - Move in a direction (north/n, south/s, east/e, west/w, up/u, down/d)\n"
                "look/l - Look around the current room\n"
                "look/l [item] - Look at an item\n"
                "take/t [item] - Take an item\n"
                "drop/d [item] - Drop an item\n"
                "use/u [item] - Use an item in your inventory\n"
                "interact/f [item] - Interact with an object\n"
                "inventory/i - View your inventory\n"
                "quit/q - Quit the game\n\n";
        }
        else
        {
            std::cout << "I don't understand that command.\n\n";
        }

        // First time when the player enters the house, close the door
        if (player->getCurrentRoom()->getName() == "foyer" && !firstEnter)
        {
            std::cout << "The door behind you suddenly closes. You realize you are trapped inside this creepy place!\n"
                "Find the jewelry and a way out!\n\n";
            firstEnter = true;
        }
    }
}

void ZOOrkEngine::handleGoCommand(const std::vector<std::string>& arguments) const
{
    if (arguments.empty())
    {
        std::cout << "Where do you want to go?\n\n";
    }
    else
    {
        // Check if the player has the lighter to enter the manor
        if (!Player::getItem("lighter") && player->getCurrentRoom()->getDescription() ==
            "You are standing in a lawn south of the manor. All windows are barred.\n"
            "The front door is now opened.\n")
        {
            std::cout << "It looks dark inside. Did I forget something?\n\n";
            return;
        }

        // Check if the player has the oil lamp to see in the dark
        if (!Player::getItem("oil-lamp") && player->getCurrentRoom()->getName() != "front-yard")
        {
            std::cout << "It's too dark to see anything. You need a light source.\n\n";
            return;
        }

        std::string direction;
        if (arguments[0] == "n" || arguments[0] == "north")
        {
            direction = "north";
        }
        else if (arguments[0] == "s" || arguments[0] == "south")
        {
            direction = "south";
        }
        else if (arguments[0] == "e" || arguments[0] == "east")
        {
            direction = "east";
        }
        else if (arguments[0] == "w" || arguments[0] == "west")
        {
            direction = "west";
        }
        else if (arguments[0] == "u" || arguments[0] == "up")
        {
            direction = "up";
        }
        else if (arguments[0] == "d" || arguments[0] == "down")
        {
            direction = "down";
        }
        else
        {
            direction = arguments[0];
        }

        Room* currentRoom = player->getCurrentRoom();
        const auto passage = currentRoom->getPassage(direction);
        player->setCurrentRoom(passage->getTo());
        passage->enter();
    }
}

void ZOOrkEngine::handleLookCommand(const std::vector<std::string>& arguments) const
{
    if (arguments.empty())
    {
        std::cout << player->getCurrentRoom()->getDescription() << std::endl;
    }
    else
    {
        for (const auto& arg : arguments)
        {
            if (const Item* roomItem = player->getCurrentRoom()->getItem(arg); roomItem != nullptr)
            {
                std::cout << roomItem->getDescription() << std::endl;
            }
            else if (const Item* invItem = Player::getItem(arg); invItem != nullptr)
            {
                std::cout << invItem->getDescription() << std::endl;
            }
            else
            {
                std::cout << "I don't see that here.\n";
            }
        }
        std::cout << std::endl;
    }
}

void ZOOrkEngine::handleTakeCommand(const std::vector<std::string>& arguments) const
{
    if (arguments.empty())
    {
        std::cout << "What do you want to take?\n\n";
    }
    else
    {
        for (const auto& arg : arguments)
        {
            if (const Item* item = player->getCurrentRoom()->getItem(arg); item != nullptr)
            {
                // Custom responses for specific items
                if (item->getName() == "knife" && player->getCurrentRoom()->getName() == "laundry-room")
                {
                    player->getCurrentRoom()->setDescription(
                        "You are now in the laundry room. There's nothing other than a [sink] and a\n"
                        "[washing-machine].\n");
                }
                else if ((item->getName() == "i" || item->getName() == "l")
                    && player->getCurrentRoom()->getName() == "master-bedroom")
                {
                    player->getCurrentRoom()->getItem("chest")->setDescription(
                        "An opened wooden chest.");
                }
                else if (item->getName() == "a" && player->getCurrentRoom()->getName() == "bathroom")
                {
                    player->getCurrentRoom()->getItem("drawer")->setDescription(
                        "An opened drawer with some expired items and bandages inside.");
                }
                else if (item->getName() == "note" && player->getCurrentRoom()->getName() == "kitchen")
                {
                    player->getCurrentRoom()->getItem("fridge")->setDescription("A grimy fridge.");
                }
                else if (item->getName() == "ring" && player->getCurrentRoom()->getName() == "living-room")
                {
                    player->getCurrentRoom()->getItem("hole")->setDescription(
                        "A small hole in the wall, nothing there.");
                }

                // Generic response for all items in the inventory
                if (item->isObtainable())
                {
                    Player::takeItem(player->getCurrentRoom()->retrieveItem(item->getName()));
                    std::cout << "You obtained " << item->getName() << ".\n";
                }
                else
                {
                    std::cout << "You can't take that.\n";
                }
            }
            else
            {
                std::cout << "I don't see that here.\n";
            }
        }
        std::cout << std::endl;
    }
}

void ZOOrkEngine::handleDropCommand(const std::vector<std::string>& arguments) const
{
    if (arguments.empty())
    {
        std::cout << "What do you want to drop?\n\n";
    }
    else
    {
        const auto inventory = Player::getInventory();
        for (const auto& arg : arguments)
        {
            auto it = std::ranges::find_if(inventory, [&arg](const Item* item)
            {
                return item->getName() == arg;
            });
            if (it != inventory.end())
            {
                Item* item = *it;
                Player::dropItem(arg);
                player->getCurrentRoom()->addItem(item);
                std::cout << "You dropped " << item->getName() << ".\n\n";
            }
            else
            {
                std::cout << "You don't have that item.\n\n";
            }
        }
    }
}

void ZOOrkEngine::handleQuitCommand(const std::vector<std::string>& arguments)
{
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n\n> ";
    std::cin >> input;

    if (const std::string quitStr = makeLowercase(input); quitStr == "y" || quitStr == "yes")
    {
        gameOver = true;
    }
}

void ZOOrkEngine::handleInventoryCommand()
{
    if (const auto inventory = Player::getInventory(); inventory.empty())
    {
        std::cout << "Your inventory is empty.\n\n";
    }
    else
    {
        std::cout << "Your inventory: ";
        for (auto it = inventory.begin(); it != inventory.end(); ++it)
        {
            std::cout << (*it)->getName();
            if (std::next(it) != inventory.end())
            {
                std::cout << ", ";
            }
        }
        std::cout << ".\n\n";
    }
}

void ZOOrkEngine::handleUseCommand(const std::vector<std::string>& arguments)
{
    if (arguments.empty())
    {
        std::cout << "What do you want to use?\n\n";
    }
    else
    {
        for (const auto& arg : arguments)
        {
            const auto inventory = Player::getInventory();
            auto it = std::ranges::find_if(inventory, [&arg](const Item* item)
            {
                return item->getName() == arg;
            });
            if (it != inventory.end())
            {
                (*it)->use();
            }
            else
            {
                std::cout << "You don't have that item in your inventory.\n";
            }
        }
        std::cout << std::endl;
    }
}

void ZOOrkEngine::handleInteractCommand(const std::vector<std::string>& arguments)
{
    if (arguments.empty())
    {
        std::cout << "What do you want to interact with?\n\n";
    }
    else
    {
        for (const auto& arg : arguments)
        {
            if (Item* item = player->getCurrentRoom()->getItem(arg); item != nullptr)
            {
                if (item->isInteractive())
                {
                    item->use();
                    if (item->getName() == "tunnel")
                    {
                        gameOver = true;
                    }
                }
                else
                {
                    std::cout << "Nothing happens.\n";
                }
            }
            else
            {
                std::cout << "I don't see that here.\n";
            }
        }
        std::cout << std::endl;
    }
}

std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string& input)
{
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' '))
    {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input)
{
    std::string output = std::move(input);
    std::ranges::transform(output, output.begin(), tolower);

    return output;
}

// void ZOOrkEngine::setDoorLocked(const bool lock)
// {
//     doorUnlocked = lock;
// }
