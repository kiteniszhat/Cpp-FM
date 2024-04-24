//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_MENU_H
#define LASTFMAPI_MENU_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include "Artist.h"


void executePowerShellCommand(const char* command)
{
    std::string fullCommand = "powershell.exe ";
    fullCommand += command;
    system(fullCommand.c_str());
}


void displayLogInMenu(const std::string &apiKey)
{

}


void displaySearchArtistMenu(const std::string &apiKey)
{
    std::string artistName;
    std::cout << "    Enter artist name: ";
//    std::getline(std::cin, artistName);
    std::cin >> artistName;
    Artist artist(artistName, apiKey);
    artist.printInfo();
}


void displaySearchTracksMenu(const std::string &apiKey)
{

}


void displayMainMenu(const std::string &apiKey)
{
    executePowerShellCommand("chcp 65001");
    int choice;
    std::cout << std::endl;
    std::cout << R"(
                ░█████╗░░░░░░░░░░░░░░░███████╗███╗░░░███╗
                ██╔══██╗░░██╗░░░░██╗░░██╔════╝████╗░████║
                ██║░░╚═╝██████╗██████╗█████╗░░██╔████╔██║
                ██║░░██╗╚═██╔═╝╚═██╔═╝██╔══╝░░██║╚██╔╝██║
                ╚█████╔╝░░╚═╝░░░░╚═╝░░██║░░░░░██║░╚═╝░██║
                ░╚════╝░░░░░░░░░░░░░░░╚═╝░░░░░╚═╝░░░░░╚═╝)";
    std::cout << std::endl << std::endl;

    std::cout << R"(
    ---------------------------------------------------------------------------
            [1] Log in        [2] Search Artist        [3] Search Track
    ---------------------------------------------------------------------------)";
    std::cout << std::endl << std::endl;
    std::cout << "    Choose number between 1 and 3: ";
    std::cin >> choice;

    switch(choice) {
        case 1:
            displayLogInMenu(apiKey);
            break;
        case 2:
            displaySearchArtistMenu(apiKey);
            break;
        default:
            std::cerr << "    Invalid choice. Please try again.\n";
            break;
    }
}


#endif //LASTFMAPI_MENU_H
