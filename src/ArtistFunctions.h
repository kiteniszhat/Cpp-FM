//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_ARTISTFUNCTIONS_H
#define LASTFMAPI_ARTISTFUNCTIONS_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

std::vector<std::string> splitArtist(const std::string &input)
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

void printArtistDescription(const std::vector<std::string> &input)
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

std::vector<std::string> get_artist_top_albums(const std::string &name, const std::string &apiKey, int limit = 3)
{
    std::vector<std::string> top_albums;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=artist.gettopalbums&artist=" + name +
            "&api_key=" + apiKey + "&limit=" + std::to_string(limit) + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_albums;
        }
        for (const auto& album : data["topalbums"]["album"]){
            top_albums.push_back(album["name"]);
        }
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return top_albums;
}



std::vector<std::string> get_artist_top_tracks(const std::string &name, const std::string &apiKey, int limit = 5)
{
    std::vector<std::string> top_tracks;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=artist.gettoptracks&artist=" + name +
            "&api_key=" + apiKey + "&limit=" + std::to_string(limit) + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
//            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_tracks;
        }
        for (const auto& track : data["toptracks"]["track"]){
            top_tracks.push_back(track["name"]);
        }
    }
//    else{
//        std::cerr << "    Error: Unable to reach data." << std::endl;
//    }
    return top_tracks;
}



std::vector<std::string> get_artist_top_genres(const std::string &name, const std::string &apiKey, int limit = 3)
{
    std::vector<std::string> top_genres;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=artist.gettoptags&artist=" + name +
            "&api_key=" + apiKey + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
//            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_genres;
        }
        for (const auto& genre : data["toptags"]["tag"]){
            top_genres.push_back(genre["name"]);
        }
    }
//    else{
//        std::cerr << "    Error: Unable to reach data." << std::endl;
//    }
    return top_genres;
}



std::string get_artist_info(const std::string &name, const std::string &apiKey)
{
    std::string info;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=artist.getinfo&artist=" + name +
            "&api_key=" + apiKey + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
//            std::cerr << "    Error: " << data["message"] << std::endl;
            return info;
        }
        info = data["artist"]["bio"]["summary"].get<std::string>();
        return info;
    }
//    else{
//        std::cerr << "    Error: Unable to reach data." << std::endl;
//    }
    return info;
}

#endif //LASTFMAPI_ARTISTFUNCTIONS_H
