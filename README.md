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
  - 
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
