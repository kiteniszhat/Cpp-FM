░█████╗░░░░░░░░░░░░░░░███████╗███╗░░░███╗
██╔══██╗░░██╗░░░░██╗░░██╔════╝████╗░████║
██║░░╚═╝██████╗██████╗█████╗░░██╔████╔██║
██║░░██╗╚═██╔═╝╚═██╔═╝██╔══╝░░██║╚██╔╝██║
╚█████╔╝░░╚═╝░░░░╚═╝░░██║░░░░░██║░╚═╝░██║
░╚════╝░░░░░░░░░░░░░░░╚═╝░░░░░╚═╝░░░░░╚═╝
---------------

Terminal-based C++ application utilizing the nlohmann json library for parsing JSON data and the httplib library for making HTTP requests. It fetches data from the Last.fm API, such as top tracks, artists, or albums, based on user input. Users can interact with the application through the command line interface, receiving relevant information from Last.fm directly within their terminal window.

## Libraries Used

  - **[nlohmann's JSON](https://github.com/nlohmann/json)**: A library for making HTTP requests and retrieving data from APIs
  - **[httplib](https://github.com/yhirose/cpp-httplib)**: A library for parsing JSON data

## How It Works

1. The user is prompted by the application to input the name of a track, artist, album, or Last.fm user to retrieve data for.
2. Using the provided user data and API key, the application sends an HTTP request to the Last.fm API.
3. The API responds with data in JSON format.
4. The application parses the JSON response to extract the relevant information.
5. The extracted details about the track, artist, album, or user are then displayed within the terminal-based interface.

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

## License

This project is licensed under the [MIT License](LICENSE).
