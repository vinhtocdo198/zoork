//
// Created by FaZe-ltv on 5/22/2024.
//

#include "PlayPianoCommand.h"
#include <random>
#include <vector>
#include <iostream>

void PlayPianoCommand::execute()
{
    // Song names
    const std::vector<std::string> songs = {
        "Moonlight Sonata",
        "Fur Elise",
        "Nocturne in E flat major (Op. 9, No. 2)",
        "Flight Of The Bumblebee",
        "Swan Lake"
    };

    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<std::vector<std::string>::size_type> dis(0, songs.size() - 1);

    // Generate a random index and song
    const auto randomIndex = dis(gen);
    const std::string& randomSong = songs[randomIndex];
    std::cout << "You are playing " << randomSong << ".\n";
}
