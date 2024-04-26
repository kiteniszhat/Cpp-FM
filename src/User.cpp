//
// Created by Emanuel on 26.04.2024.
//

#include "User.h"
#include "UserFunctions.h"

User::User(const std::string &name, const std::string &apiKey, const std::string &timePeriod) :
name_(name), apiKey_(apiKey), timePeriod_(timePeriod), recentTracks_(get_user_recent_tracks(name, apiKey)),
topTracks_(get_user_top_tracks(name, apiKey, timePeriod)), topAlbums_(get_user_top_albums(name, apiKey, timePeriod)),
topArtists_(get_user_top_artists(name, apiKey, timePeriod))
{}



std::string User::getName() const
{
    return name_;
}

std::string User::getApiKey() const
{
    return apiKey_;
}

std::string User::getTimePeriod() const
{
    return timePeriod_;
}

std::vector<std::string> User::getRecentTracks() const
{
    return recentTracks_;
}

std::vector<std::string> User::getTopTracks() const
{
    return topTracks_;
}

std::vector<std::string> User::getTopAlbums() const
{
    return topAlbums_;
}

std::vector<std::string> User::getTopArtists() const
{
    return topArtists_;
}

void User::printInfo() const
{
    std::string timePeriod;
    if (getTimePeriod() == "7day")
        timePeriod = " in last 7 days";
    else if (getTimePeriod() == "1month")
        timePeriod = " in last month";
    else if (getTimePeriod() == "3month")
        timePeriod = " in last 3 months";
    else if (getTimePeriod() == "6month")
        timePeriod = " in last 6 months";
    else if (getTimePeriod() == "12month")
        timePeriod = " in last 12 months";
    else if (getTimePeriod() == "overall")
        timePeriod = " in overall";
    if (!getRecentTracks().empty())
    {
        std::cout << "\n    Recently listened tracks by user " << getName() << ":\n";
        for (int i = 0; i < 5; i ++)
            std::cout << "        " << i + 1 << ". " << getRecentTracks()[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No user recent tracks found." << std::endl;
    }
    if (!getTopTracks().empty())
    {
        std::cout << "\n    Most listened tracks by user " << getName() << timePeriod << ":\n";
        for (int i = 0; i < 10; i ++)
            std::cout << "        " << i + 1 << ". " << getTopTracks()[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No user top tracks found." << std::endl;
    }
    if (!getTopAlbums().empty())
    {
        std::cout << "\n    Most listened albums by user " << getName() << timePeriod << ":\n";
        for (int i = 0; i < 10; i ++)
            std::cout << "        " << i + 1 << ". " << getTopAlbums()[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No user top albums found." << std::endl;
    }
    if (!getTopArtists().empty())
    {
        std::cout << "\n    Most listened artists by user " << getName() << timePeriod << ":\n";
        for (int i = 0; i < 10; i ++)
            std::cout << "        " << i + 1 << ". " << getTopArtists()[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No user top artists found." << std::endl;
    }
}
