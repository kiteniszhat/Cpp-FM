//
// Created by Emanuel on 25.04.2024.
//

#ifndef LASTFMAPI_ALBUMFUNCTIONS_H
#define LASTFMAPI_ALBUMFUNCTIONS_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

std::vector<std::string> get_album_tracks(const std::string &albumName, const std::string &artistName, const std::string &apiKey)
{
    std::vector<std::string> album_tracks;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=album.getinfo&api_key=" + apiKey +
            "&artist=" + artistName + "&album=" + albumName + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return album_tracks;
        }
        for (const auto& track : data["album"]["tracks"]["track"]){
            album_tracks.push_back(track["name"]);
        }
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return album_tracks;
}


#endif //LASTFMAPI_ALBUMFUNCTIONS_H
