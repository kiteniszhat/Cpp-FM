//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_TRACKFUNCTIONS_H
#define LASTFMAPI_TRACKFUNCTIONS_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

std::vector<std::string> splitTracks(const std::string &input)
{
    std::stringstream stringStreams(input);
    std::vector<std::string> splitArray;
    std::string word;
    while (stringStreams >> word) {
        splitArray.push_back(word);
    }
    while (splitArray[splitArray.size() - 1] != "<a") {
        splitArray.pop_back();
    }
    splitArray.pop_back();
    return splitArray;
}



void printTrackDescription(const std::vector<std::string> &input)
{
    int charAmmount = 0;
    std::cout << "    ";
    for (const auto &word : input) {
        charAmmount += word.size();
        if (charAmmount <= 76 ) {
            std::cout << word << " ";
            charAmmount ++;
        }
        else {
            std::cout << std::endl << "    " << word << " ";
            charAmmount = word.size() + 1;
        }
    }
}



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



std::string get_track_album(const std::string &trackName, const std::string &artistName, const std::string &apiKey)
{
    std::string album;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=track.getInfo&api_key=" + apiKey +
            "&artist=" + artistName + "&track=" + trackName + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
//            std::cerr << "    Error: " << data["message"] << std::endl;
            return album;
        }
        album = data["track"]["album"]["title"].get<std::string>();
        return album;
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return album;
}



std::string get_track_info(const std::string &trackName, const std::string &artistName, const std::string &apiKey)
{
    std::string info;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=track.getInfo&api_key=" + apiKey +
            "&artist=" + artistName + "&track=" + trackName + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
//            std::cerr << "    Error: " << data["message"] << std::endl;
            return info;
        }
        if (data["track"].find("wiki") != data["track"].end()) {
            if (data["track"]["wiki"].is_object() && !data["track"]["wiki"].empty()) {
                info = data["track"]["wiki"]["summary"].get<std::string>();
            }
            else {
                std::cerr << "    \nError: No wiki information available for this track." << std::endl;
            }
        }
        else {
            std::cerr << "    \nError: No wiki information available for this track." << std::endl;
        }
        return info;
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return info;
}

// http://ws.audioscrobbler.com/2.0/?method=track.getInfo&api_key=722d4a408cab1bb80b5f07fcc02fa690&artist=Grimes&track=Genesis&format=json
#endif //LASTFMAPI_TRACKFUNCTIONS_H
