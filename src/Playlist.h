//
// Created by Emanuel on 26.04.2024.
//

#ifndef LASTFMAPI_PLAYLIST_H
#define LASTFMAPI_PLAYLIST_H

#include <iostream>
#include <regex>
#include <string>
#include "User.h"
#include "Track.h"

std::string get_similar_track(const std::string &artistName, const std::string &trackName, const std::string &apiKey)
{
    std::string similar;
    httplib::Client client("http://ws.audioscrobbler.com");
    auto response = client.Get(("/2.0/?method=track.getsimilar&api_key=" + apiKey +
            "&artist=" + artistName + "&track=" + trackName + "&format=json").c_str());
    if (response -> status == 200){
        auto data = nlohmann::json::parse(response -> body);
        if (data.find("error") != data.end()){
//            std::cerr << "    Error: " << data["message"] << std::endl;
            return similar;
        }
        if (data["similartracks"].find("track") != data["similartracks"].end()) {
            if (data["similartracks"]["track"][0].find("name") != data["similartracks"]["track"][0].end()){
                std::string track = data["similartracks"]["track"][5]["name"].get<std::string>();
                std::string artist = data["similartracks"]["track"][5]["artist"]["name"].get<std::string>();
                similar = artist + " - " + track;
            }
//            else
//                std::cerr << "    Error: No similar tracks found." << std::endl;
        }
//        else
//            std::cerr << "    Error: No similar tracks found." << std::endl;
    }
    else{
        std::cerr << "    Error: Unable to reach data." << std::endl;
    }
    return similar;
}



void makePlaylist(const std::string &userName, const std::string &timePeriod, const std::string &apiKey)
{
    User user(userName, apiKey, timePeriod);
    std::vector<std::string> topTracks = user.getTopTracks();
    std::vector<std::string> similarTracks;
    std::regex pattern(R"(^(.*?)\s*-\s*(.*?)\s*\[.*\]$)");
    std::smatch match;
    std::string timePeriod_printReady;
    if (timePeriod == "7day")
        timePeriod_printReady = " in last 7 days";
    else if (timePeriod == "1month")
        timePeriod_printReady = " in last month";
    else if (timePeriod == "3month")
        timePeriod_printReady = " in last 3 months";
    else if (timePeriod == "6month")
        timePeriod_printReady = " in last 6 months";
    else if (timePeriod == "12month")
        timePeriod_printReady = " in last 12 months";
    else if (timePeriod == "overall")
        timePeriod_printReady = " in overall";
    std::cout << "    User top tracks" << timePeriod_printReady << " for reference" << ":\n";
    for (int i = 0; i < 10; i ++)
        std::cout <<  "        " << i + 1 << ". " << topTracks[i] << std::endl;
    std::cout << std::endl;
    std::cout << "    New playlist based on user top tracks" << timePeriod_printReady << ":\n";
    int limit = 10;
    int diff = 0;
    for (int i = 0; i < limit; i ++) {
        if (std::regex_match(topTracks[i], match, pattern)) {
            std::string track = get_similar_track(match[1], match[2] , apiKey);
            if (!track.empty()) {
                similarTracks.push_back(track);
                std::cout << "        " << i + 1 - diff << ". " << similarTracks[i - diff] << std::endl;
            }
            else {
                limit ++;
                diff ++;
            }
        }
    }
    std::cout << std::endl;
}

#endif //LASTFMAPI_PLAYLIST_H
