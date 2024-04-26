░█████╗░░░░░░░░░░░░░░░███████╗███╗░░░███╗
██╔══██╗░░██╗░░░░██╗░░██╔════╝████╗░████║
██║░░╚═╝██████╗██████╗█████╗░░██╔████╔██║
██║░░██╗╚═██╔═╝╚═██╔═╝██╔══╝░░██║╚██╔╝██║
╚█████╔╝░░╚═╝░░░░╚═╝░░██║░░░░░██║░╚═╝░██║
░╚════╝░░░░░░░░░░░░░░░╚═╝░░░░░╚═╝░░░░░╚═╝
---------------

Terminal-based C++ application utilizing the nlohmann json library for parsing JSON data and the httplib library for making HTTP requests. It fetches data from the Last.fm API, such as top tracks, artists, or albums, based on user input. Users can interact with the application through the command line interface, receiving relevant information from Last.fm directly within their terminal window.

## Status

:construction: *Work in Progress* :warning:

## Table of Contents

1. [How it works](#how-it-works)
2. [Example Input/Output](#example-inputoutput)
3. [Libraries Used](#libraries-used)
4. [License](#license)
5. [Repository Guide](#repository-guide)

<a name="how-it-works"></a>

## How It Works

1. The user is prompted by the application to input the name of a track, artist, album, or Last.fm user to retrieve data for.
2. Using the provided user data and API key, the application sends an HTTP request to the Last.fm API.
3. The API responds with data in JSON format.
4. The application parses the JSON response to extract the relevant information.
5. The extracted details about the track, artist, album, or user are then displayed within the terminal-based interface.

<a name="example-inputoutput"></a>

## Example Input/Output

**Input**

```
Enter artist name: The Doors
```

**Output**

```
Top albums of The Doors:
  1. The Doors
  2. Greatest Hits
  3. L.A. Woman

Top tracks of The Doors:
  1. Break on Through (to the Other Side)
  2. People Are Strange
  3. Light My Fire
  4. Riders on the Storm
  5. Roadhouse Blues

Genres of The Doors:
  1. classic rock
  2. Psychedelic Rock
  3. rock

The Doors description from Last.fm:
[...]
```

<a name="libraries-used"></a>

## Libraries Used

  - **[nlohmann's JSON](https://github.com/nlohmann/json)**: A library for parsing JSON data
  - **[httplib](https://github.com/yhirose/cpp-httplib)**: A library for making HTTP requests and retrieving data from APIs

<a name="license"></a>

## License

This project is licensed under the [MIT License](LICENSE).

<a name="repository-guide"></a>

## Repository Guide

```bash
├── README.md        # this README
├── LICENSE          # license file
├── CMakeLists.txt   # CMake file that contains instructions for configuring the build
├── src
│   ├── Album.cpp    # album class
│   ├── Album.h
│   ├── AlbumFunctions.h
│   ├── Artist.cpp   # artist class
│   ├── Artist.h
│   ├── ArtistFunctions.h
│   ├── Menu.h       # file that makes app look cool in Terminal ;D
│   ├── Track.cpp    # track class
│   ├── Track.h
│   ├── TrackFunctions.h
│   ├── User.cpp     # user class
│   ├── User.h
│   ├── UserFunctions.h
│   └── main.cpp
```
