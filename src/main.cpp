#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

#include "Artist.h"


int main()
{
    std::string apiKey = "722d4a408cab1bb80b5f07fcc02fa690";
    std::string artistName;
    std::cout << "Enter artist name: ";
    std::cin >> artistName;
    Artist artist(artistName, apiKey);
    artist.printInfo();
}

//
// Created by Emanuel on 24.04.2024.
//
