//
// Created by Emanuel on 24.04.2024.
//

#include <iomanip>
#include <sstream>
#include "Track.h"
#include "TrackFunctions.h"

Track::Track(const std::string &artistName, const std::string &trackName, const std::string &apiKey) :
trackName_(trackName), apiKey_(apiKey), artist_(artistName, apiKey),
playcount_(get_track_playcount(trackName, artistName, apiKey)), album_(get_track_album(trackName, artistName, apiKey)),
info_(get_track_info(trackName, artistName, apiKey))
{}



std::string Track::getPlayCount() const
{
    return playcount_;
}

Artist Track::getArtist() const
{
    return artist_;
}

std::string Track::getName() const
{
    return trackName_;
}
std::string Track::getAlbum() const
{
    return album_;
}

std::string Track::getInfo() const
{
    return info_;
}

void Track::printInfo()
{
    std::cout << std::endl;
    if (!getPlayCount().empty() && !getAlbum().empty()) {
        std::cout << "    Info about " << getName() << " made by " << getArtist().getName() << ":" << std::endl;
        std::cout << "        • Number of plays: " << getPlayCount() << std::endl;
        std::cout << "        • Album:           " << getAlbum() << std::endl;
    }
    else
    {
        std::cerr << "\n    No info found." << std::endl;
        return;
    }
    std::cout << std::endl;
    if (!getInfo().empty()) {
        std::cout << "    " << getName() << " description from Last.fm:\n" << std::endl;
        std::vector<std::string> info = splitTracks(getInfo());
        for (int i = 0; i < info.size() / 11 + 1; i++) {
            std::cout << "    ";
            for (int j = 0; j < 11; j++) {
                if (i * 11 + j >= info.size()) {
                    break;
                }
                std::cout << info[i * 11 + j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        std::cerr << "\n    No description from Last.fm found." << std::endl;
    }
}




