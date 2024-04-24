//
// Created by Emanuel on 24.04.2024.
//

#include "Artist.h"
#include "ArtistFunctions.h"


Artist::Artist(const std::string &name, const std::string &apiKey) :
name_(name), apiKey_(apiKey), topAlbums_{get_artist_top_albums(name, apiKey)},
topTracks_{get_artist_top_tracks(name, apiKey)}, genres_(get_artist_top_genres(name, apiKey))
{}

Artist::Artist(const Artist &artist) :
name_(artist.getName()), apiKey_(artist.getApiKey()), topAlbums_(artist.getAlbums()),
topTracks_(artist.getTracks()), genres_(artist.getGenres())
{}



std::string Artist::getName() const
{
    return name_;
}

std::vector<std::string> Artist::getAlbums() const
{
    return topAlbums_;
}

std::vector<std::string> Artist::getTracks() const
{
    return topTracks_;
}

std::vector<std::string> Artist::getGenres() const
{
    return genres_;
}

std::string Artist::getApiKey() const
{
    return apiKey_;
}

void Artist::printInfo()
{
    if (!topAlbums_.empty())
    {
        std::cout << "\n    Top albums of " << name_ << ":\n";
        for (size_t i = 0; i < topAlbums_.size(); ++i)
            std::cout << "        " << i + 1 << ". " << topAlbums_[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No top albums found." << std::endl;
    }

    if (!topTracks_.empty())
    {
        std::cout << "\n    Top tracks of " << name_ << ":\n";
        for (size_t i = 0; i < topTracks_.size(); ++i)
            std::cout << "        " << i + 1 << ". " << topTracks_[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No top tracks found." << std::endl;
    }
    if (!genres_.empty())
    {
        std::cout << "\n    Genres of " << name_ << ":\n";
        for (size_t i = 0; i < 3; ++i)
            std::cout << "        " << i + 1 << ". " << genres_[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No genres found." << std::endl;
    }
}

void Artist::setName(const std::string &name)
{
    name_ = name;
}



