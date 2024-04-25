//
// Created by Emanuel on 26.04.2024.
//

#ifndef LASTFMAPI_USER_H
#define LASTFMAPI_USER_H

#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

class User
{
private:
    std::string name_;
    std::string apiKey_;
    std::string timePeriod_;
    std::vector<std::string> recentTracks_;
    std::vector<std::string> topTracks_;
    std::vector<std::string> topAlbums_;
    std::vector<std::string> topArtists_;

public:
    User(const std::string &name, const std::string &apiKey, const std::string &timePeriod);

    std::string getName() const;
    std::string getApiKey() const;
    std::string getTimePeriod() const;
    std::vector<std::string> getRecentTracks() const;
    std::vector<std::string> getTopTracks() const;
    std::vector<std::string> getTopAlbums() const;
    std::vector<std::string> getTopArtists() const;

    void printInfo() const;
};


#endif //LASTFMAPI_USER_H
