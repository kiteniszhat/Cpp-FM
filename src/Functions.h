//
// Created by Emanuel on 24.04.2024.
//

#ifndef LASTFMAPI_FUNCTIONS_H
#define LASTFMAPI_FUNCTIONS_H

#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

std::vector<std::string> get_artist_top_albums(const std::string &name, const std::string &apiKey, int limit = 3)
{
    std::vector<std::string> top_albums;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=artist.gettopalbums&artist=" + name +
            "&api_key=" + apiKey + "&limit=" + std::to_string(limit) + "&format=json").c_str());
    if (response -> status == 200)
    {
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end())
        {
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_albums;
        }
        for (const auto& album : data["topalbums"]["album"])
        {
            top_albums.push_back(album["name"]);
        }
    }
    else
    {
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
    if (response -> status == 200)
    {
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end())
        {
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_tracks;
        }
        for (const auto& track : data["toptracks"]["track"])
        {
            top_tracks.push_back(track["name"]);
        }
    }
    else
    {
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return top_tracks;
}


std::vector<std::string> get_artist_top_genres(const std::string &name, const std::string &apiKey, int limit = 3)
{
    std::vector<std::string> top_genres;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=artist.gettoptags&artist=" + name +
            "&api_key=" + apiKey + "&format=json").c_str());
    if (response -> status == 200)
    {
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end())
        {
            std::cerr << "    Error: " << data["message"] << std::endl;
            return top_genres;
        }
        for (const auto& genre : data["toptags"]["tag"])
        {
            top_genres.push_back(genre["name"]);
        }
    }
    else
    {
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return top_genres;
}

#endif //LASTFMAPI_FUNCTIONS_H
