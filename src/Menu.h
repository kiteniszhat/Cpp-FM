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

           [4] Exit              [5] Search Album        [5] Make playlist
    ----------------------------------------------------------------------------)";
        std::cout << std::endl << std::endl;
        std::cout << "    Choose number between [1, 2, 3, 4] : ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayLogInMenu(apiKey);
                break;
            case 2:
                displaySearchArtistMenu(apiKey);
                break;
            case 3:
                displaySearchTracksMenu(apiKey);
                break;
            case 4:
                return;
            case 5:
                displaySearchAlbumMenu(apiKey);
                break;
            default:
                std::cerr << "    Invalid choice. Please try again.\n";
                break;
        }
    }
}


#endif //LASTFMAPI_MENU_H
