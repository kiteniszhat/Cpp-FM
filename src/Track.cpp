//
// Created by Emanuel on 24.04.2024.
//

#include "Track.h"
#include "TrackFunctions.h"

Track::Track(const std::string &artistName, const std::string &trackName, const std::string &apiKey) :
trackName_(trackName), apiKey_(apiKey), artist_(artistName, apiKey), playcount_(get_track_playcount(trackName, artistName, apiKey))
{}

std::string Track::getPlayCount() const
{
    return playcount_;
}

void Track::printInfo()
{
    std::cout << getPlayCount() << std::endl;
}
