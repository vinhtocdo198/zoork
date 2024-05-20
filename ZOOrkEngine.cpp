//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"
#include <memory>
#include <utility>
#include <algorithm>
#include <iostream>
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

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        const auto arguments = std::vector(words.begin() + 1, words.end());

        if (command == "go")
        {
            handleGoCommand(arguments);
        }
        else if (command == "look" || command == "inspect")
        {
            handleLookCommand(arguments);
        }
        else if (command == "take" || command == "get")
        {
            handleTakeCommand(arguments);
        }
        else if (command == "drop")
        {
            handleDropCommand(arguments);
        }
        else if (command == "quit")
        {
            handleQuitCommand(arguments);
        }
        else
        {
            std::cout << "I don't understand that command.\n";
        }
    }
}

void ZOOrkEngine::handleGoCommand(const std::vector<std::string>& arguments)
{
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
    auto passage = currentRoom->getPassage(direction);
    player->setCurrentRoom(passage->getTo());
    passage->enter();
}

void ZOOrkEngine::handleLookCommand(const std::vector<std::string>& arguments)
{
    // To be implemented
    std::cout << "This functionality is not yet enabled.\n";
}

void ZOOrkEngine::handleTakeCommand(const std::vector<std::string>& arguments)
{
    // To be implemented
    std::cout << "This functionality is not yet enabled.\n";
}

void ZOOrkEngine::handleDropCommand(const std::vector<std::string>& arguments)
{
    // To be implemented
    std::cout << "This functionality is not yet enabled.\n";
}

void ZOOrkEngine::handleQuitCommand(const std::vector<std::string>& arguments)
{
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes")
    {
        gameOver = true;
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
