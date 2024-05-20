//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_ZOORKENGINE_H
#define ZOORK_ZOORKENGINE_H

#include "Player.h"
#include "Location.h"
#include "Passage.h"
#include <string>
#include <vector>

class ZOOrkEngine
{
public:
    explicit ZOOrkEngine(const std::shared_ptr<Room>&);

    void run();

private:
    bool gameOver = false;
    Player* player;

    void handleGoCommand(const std::vector<std::string>&);

    void handleLookCommand(const std::vector<std::string>&);

    void handleTakeCommand(const std::vector<std::string>&);

    void handleDropCommand(const std::vector<std::string>&);

    void handleQuitCommand(const std::vector<std::string>&);

    static std::vector<std::string> tokenizeString(const std::string&);

    static std::string makeLowercase(std::string);
};

#endif // ZOORK_ZOORKENGINE_H
