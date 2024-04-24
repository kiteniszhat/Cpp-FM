//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_ARTIST_H
#define LASTFMAPI_ARTIST_H

#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

class Artist
{
private:
    std::string name_;
    std::string apiKey_;
    std::vector<std::string> topAlbums_;
    std::vector<std::string> topTracks_;
    std::vector<std::string> genres_;

public:
    Artist(const std::string &name, const std::string &apiKey);

    std::string getName() const;
    auto getAlbums() const;
    auto getTracks() const;
    auto getGenres() const;

    void printInfo();
};


#endif //LASTFMAPI_ARTIST_H
