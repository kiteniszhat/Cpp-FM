//
// Created by Emanuel on 25.04.2024.
//

#include "Album.h"
#include "AlbumFunctions.h"


Album::Album(const std::string &artistName, const std::string &albumName, const std::string &apiKey) :
name_(albumName), apiKey_(apiKey), artist_(artistName, apiKey), albumTracks_(get_album_tracks(albumName, artistName, apiKey))
{}



std::string Album::getName() const
{
    return name_;
}

std::string Album::getApiKey() const
{
    return apiKey_;
}

std::vector<std::string> Album::getAlbumTracks() const
{
    return albumTracks_;
}

Artist Album::getArtist() const
{
    return artist_;
}

void Album::printInfo() const
{
    if (!getAlbumTracks().empty())
    {
        std::cout << "\n    Track list of " << getName() << " by " << getArtist().getName() << ":\n";
        for (int i = 0; i < getAlbumTracks().size(); i ++)
            std::cout << "        " << i + 1 << ". " << getAlbumTracks()[i] << std::endl;
    }
    else
    {
        std::cerr << "\n    No tracks found." << std::endl;
    }

}



