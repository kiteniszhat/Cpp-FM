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
#include "Track.h"
#include "Album.h"
#include "User.h"


void executePowerShellCommand(const char* command)
{
    std::string fullCommand = "powershell.exe ";
    fullCommand += command;
    system(fullCommand.c_str());
}


void displaySearchUser(const std::string &apiKey)
{
    std::string userName, timePeriod;
    std::cout << "    Enter user name: ";
    std::getline(std::cin >> std::ws, userName);
    int choice;

    executePowerShellCommand("clear");
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
    ----------------------------------------------------------------------------
                The time period over which to retrieve the data for
    ----------------------------------------------------------------------------
            [1] last 7 days       [2] last month       [3] last 3 months

            [4] last 6 months     [5] last 12 months   [6] overall
    ----------------------------------------------------------------------------)";
    std::cout << std::endl << std::endl;
    std::cout << "    Choose a number between [1 - 6] : ";
    std::cin >> choice;
    switch (choice) {
        case 1:
            timePeriod = "7day";
            break;
        case 2:
            timePeriod = "1month";
            break;
        case 3:
            timePeriod = "3month";
            break;
        case 4:
            timePeriod = "6month";
            break;
        case 5:
            timePeriod = "12month";
            break;
        case 6:
            timePeriod = "overall";
            break;
        default:
            std::cerr << "    Invalid choice. Please try again.\n";
            executePowerShellCommand("clear");
            return;
    }
    User user(userName, apiKey, timePeriod);
    user.printInfo();
    std::cout << std::endl;
    std::string anything;
    std::cout << "    Type anything to continue: ";
    std::cin >> anything;
    if (anything.empty()) {
        std::cout << "    ;~~~~~~~~D";
    }
    executePowerShellCommand("clear");
}


void displaySearchArtistMenu(const std::string &apiKey)
{
    std::string artistName;
    std::cout << "    Enter artist name: ";
    std::getline(std::cin >> std::ws, artistName);
//    std::cin >> artistName;
    Artist artist(artistName, apiKey);
    artist.printInfo();
    std::cout << std::endl;
    std::string anything;
    std::cout << "    Type anything to continue: ";
    std::cin >> anything;
    if (anything.empty()) {
        std::cout << "    ;~~~~~~~~D";
    }
}


void displaySearchTracksMenu(const std::string &apiKey)
{
    std::string trackName, artistName;
    std::cout << "    Enter track name: ";
    std::getline(std::cin >> std::ws, trackName);
//    std::cin >> trackName;
    std::cout << "    Enter artist name: ";
    std::getline(std::cin >> std::ws, artistName);
//    std::cin >> artistName;
    Track track(artistName, trackName, apiKey);
    track.printInfo();
    std::cout << std::endl;
    std::string anything;
    std::cout << "    Type anything to continue: ";
    std::cin >> anything;
    if (anything.empty()) {
        std::cout << "    ;~~~~~~~~D";
    }
}


void displaySearchAlbumMenu(const std::string &apiKey)
{
    std::string albumName, artistName;
    std::cout << "    Enter album name: ";
    std::getline(std::cin >> std::ws, albumName);
    std::cout << "    Enter artist name: ";
    std::getline(std::cin >> std::ws, artistName);
    Album album(artistName, albumName, apiKey);
    album.printInfo();
    std::cout << std::endl;
    std::string anything;
    std::cout << "    Type anything to continue: ";
    std::cin >> anything;
    if (anything.empty()) {
        std::cout << "    ;~~~~~~~~D";
    }
}


void displayMakePlaylistMenu(const std::string &apiKey)
{
    std::cout << "    Not implemented yet.";
    std::cout << std::endl;
    std::string anything;
    std::cout << "    Type anything to continue: ";
    std::cin >> anything;
    if (anything.empty()) {
        std::cout << "    ;~~~~~~~~D";
    }
}


void displayMainMenu(const std::string &apiKey)
{
    executePowerShellCommand("chcp 65001");
    while (true) {
        executePowerShellCommand("clear");
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
    ----------------------------------------------------------------------------
           [1] Search User       [2] Search Artist       [3] Search Track

           [4] Search Album      [5] Make playlist       [6] Exit
    ----------------------------------------------------------------------------)";
        std::cout << std::endl << std::endl;
        std::cout << "    Choose a number between [1 - 6] : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displaySearchUser(apiKey);
                break;
            case 2:
                displaySearchArtistMenu(apiKey);
                break;
            case 3:
                displaySearchTracksMenu(apiKey);
                break;
            case 4:
                displaySearchAlbumMenu(apiKey);
                break;
            case 5:
                displayMakePlaylistMenu(apiKey);
                break;
            case 6:
                executePowerShellCommand("clear");
                return;
            default:
                std::cerr << "    Invalid choice. Please try again.\n";
                break;
        }
    }
}


#endif //LASTFMAPI_MENU_H
