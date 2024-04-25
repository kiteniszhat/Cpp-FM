//
// Created by Emanuel on 25.04.2024.
//

#ifndef LASTFMAPI_ALBUM_H
#define LASTFMAPI_ALBUM_H

#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"
#include "Artist.h"

class Album
{
private:
    std::string name_;
    std::string apiKey_;
    std::vector<std::string> albumTracks_;
    Artist artist_;

public:
    Album(const std::string &artistName, const std::string &albumName, const std::string &apiKey);

    std::string getName() const;
    std::string getApiKey() const;
    std::vector<std::string> getAlbumTracks() const;
    Artist getArtist() const;

    void printInfo() const;
};


#endif //LASTFMAPI_ALBUM_H
