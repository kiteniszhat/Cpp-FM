//
// Created by Emanuel on 26.04.2024.
//

#ifndef LASTFMAPI_USERFUNCTIONS_H
#define LASTFMAPI_USERFUNCTIONS_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

std::vector<std::string> get_user_recent_tracks(const std::string &name, const std::string &apiKey)
{
    std::vector<std::string> recent_tracks;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=user.getrecenttracks&user=" + name +
            "&api_key=" + apiKey + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return recent_tracks;
        }
        for (const auto& track : data["recenttracks"]["track"]){
            std::string artist = track["artist"]["#text"].get<std::string>();
            std::string trackName = track["name"].get<std::string>();
            recent_tracks.push_back(artist + " - " + trackName);
        }
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return recent_tracks;
}



std::vector<std::string> get_user_top_tracks(const std::string &name, const std::string &apiKey, const std::string &timePeriod)
{
    std::vector<std::string> top_tracks;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=user.gettoptracks&user=" + name +
            "&api_key=" + apiKey + "&period=" + timePeriod + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_tracks;
        }
        for (const auto& track : data["toptracks"]["track"]){
            std::string artist = track["artist"]["name"].get<std::string>();
            std::string trackName = track["name"].get<std::string>();
            std::string playcount = track["playcount"].get<std::string>();
            top_tracks.push_back(artist + " - " + trackName + "    [" + playcount + " plays]");
        }
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return top_tracks;
}



std::vector<std::string> get_user_top_albums(const std::string &name, const std::string &apiKey, const std::string &timePeriod)
{
    std::vector<std::string> top_albums;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=user.gettopalbums&user=" + name +
            "&api_key=" + apiKey + "&period=" + timePeriod + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_albums;
        }
        for (const auto& album : data["topalbums"]["album"]){
            std::string artist = album["artist"]["name"].get<std::string>();
            std::string albumName = album["name"].get<std::string>();
            std::string playcount = album["playcount"].get<std::string>();
            top_albums.push_back(artist + " - " + albumName + "    [" + playcount + " plays]");
        }
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return top_albums;
}



std::vector<std::string> get_user_top_artists(const std::string &name, const std::string &apiKey, const std::string &timePeriod)
{
    std::vector<std::string> top_artists;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=user.gettopartists&user=" + name +
            "&api_key=" + apiKey + "&period=" + timePeriod + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_artists;
        }
        for (const auto& artist : data["topartists"]["artist"]){
            std::string artistName = artist["name"].get<std::string>();
            std::string playcount = artist["playcount"].get<std::string>();
            top_artists.push_back(artistName + "    [" + playcount + " plays]");
        }
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return top_artists;
}

#endif //LASTFMAPI_USERFUNCTIONS_H
