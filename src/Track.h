//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_TRACK_H
#define LASTFMAPI_TRACK_H

#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"
#include "Artist.h"

class Track
{
private:
    std::string trackName_;
    std::string apiKey_;
    std::string playcount_;
    Artist artist_;

public:
    Track(const std::string &artistName, const std::string &trackName, const std::string &apiKey);

    std::string getPlayCount() const;

    void printInfo();
};


#endif //LASTFMAPI_TRACK_H
