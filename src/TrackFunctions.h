//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_TRACKFUNCTIONS_H
#define LASTFMAPI_TRACKFUNCTIONS_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

std::string get_track_playcount(const std::string &trackName, const std::string &artistName, const std::string &apiKey)
{
    std::string playcount;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=track.getInfo&api_key=" + apiKey +
            "&artist=" + artistName + "&track=" + trackName + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return playcount;
        }
        playcount = data["track"]["playcount"].get<std::string>();
        return playcount;
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return playcount;
}
// http://ws.audioscrobbler.com/2.0/?method=track.getInfo&api_key=722d4a408cab1bb80b5f07fcc02fa690&artist=Grimes&track=Genesis&format=json
#endif //LASTFMAPI_TRACKFUNCTIONS_H
