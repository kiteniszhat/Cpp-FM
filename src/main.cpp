#include <iostream>
#include <vector>
#include <string>
#include "httplib.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
using namespace httplib;

std::vector<std::string> get_top_tracks(const std::string& artist_name, const std::string& api_key, int limit = 5) {
    std::vector<std::string> top_tracks;
    Client client("http://ws.audioscrobbler.com");
    auto res = client.Get(("/2.0/?method=artist.gettoptracks&artist=" + artist_name + "&api_key=" + api_key + "&limit=" + std::to_string(limit) + "&format=json").c_str());
    if (res && res->status == 200) {
        auto data = json::parse(res->body);
        if (data.find("error") != data.end()) {
            std::cerr << "Error: " << data["message"] << std::endl;
            return top_tracks;
        }
        for (const auto& track : data["toptracks"]["track"]) {
            top_tracks.push_back(track["name"]);
        }
    } else {
        std::cerr << "Error: Unable to fetch data. Status code: " << (res ? res->status : -1) << std::endl;
    }
    return top_tracks;
}

std::vector<std::string> get_top_albums(const std::string& artist_name, const std::string& api_key, int limit = 5) {
    std::vector<std::string> top_albums;
    Client client("http://ws.audioscrobbler.com");
    auto res = client.Get(("/2.0/?method=artist.gettopalbums&artist=" + artist_name + "&api_key=" + api_key + "&limit=" + std::to_string(limit) + "&format=json").c_str());
    if (res && res->status == 200) {
        auto data = json::parse(res->body);
        if (data.find("error") != data.end()) {
            std::cerr << "Error: " << data["message"] << std::endl;
            return top_albums;
        }
        for (const auto& album : data["topalbums"]["album"]) {
            top_albums.push_back(album["name"]);
        }
    } else {
        std::cerr << "Error: Unable to fetch data. Status code: " << (res ? res->status : -1) << std::endl;
    }
    return top_albums;
}

std::vector<std::string> get_my_top_tracks(const std::string& api_key, int limit = 5) {
    std::vector<std::string> top_artists;
    std::string user = "KittenishHat71";
    Client client("http://ws.audioscrobbler.com");
    auto res = client.Get(("/2.0/?method=user.gettopartists&user=" + user + "&api_key=" + api_key + "&limit=" + std::to_string(limit) + "&format=json").c_str());
    if (res && res->status == 200) {
        auto data = json::parse(res->body);
        if (data.find("error") != data.end()) {
            std::cerr << "Error: " << data["message"] << std::endl;
            return top_artists;
        }
        for (const auto& artist : data["topartists"]["artist"]) {
            top_artists.push_back(artist["name"]);
        }
    } else {
        std::cerr << "Error: Unable to fetch data. Status code: " << (res ? res->status : -1) << std::endl;
    }
    return top_artists;
}

int main() {
    std::string api_key = "722d4a408cab1bb80b5f07fcc02fa690";
    std::string artist_name;
    std::cout << "Enter artist name: ";
    std::cin >> artist_name;

    auto top_tracks = get_top_tracks(artist_name, api_key);
    auto top_albums = get_top_albums(artist_name, api_key);
    auto top_user_artists = get_my_top_tracks(api_key);

    if (!top_tracks.empty()) {
        std::cout << "Top tracks of " << artist_name << ":\n";
        for (size_t i = 0; i < top_tracks.size(); ++i) {
            std::cout << i + 1 << ". " << top_tracks[i] << std::endl;
        }
    } else {
        std::cout << "No top tracks found." << std::endl;
    }

    if (!top_albums.empty()) {
        std::cout << "Top albums of " << artist_name << ":\n";
        for (size_t i = 0; i < top_albums.size(); ++i) {
            std::cout << i + 1 << ". " << top_albums[i] << std::endl;
        }
    } else {
        std::cout << "No top albums found." << std::endl;
    }

    if (!top_user_artists.empty()) {
        std::cout << "My top artists:\n";
        for (size_t i = 0; i < top_user_artists.size(); ++i) {
            std::cout << i + 1 << ". " << top_user_artists[i] << std::endl;
        }
    } else {
        std::cout << "No top artists found." << std::endl;
    }

    return 0;
}
