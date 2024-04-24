set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

cmake_minimum_required(VERSION 3.27)
project(lastfmAPI)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY "https://github.com/nlohmann/json.git"
        GIT_TAG "v3.11.3"
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
        httplib
        GIT_REPOSITORY "https://github.com/yhirose/cpp-httplib.git"
        GIT_TAG "v0.15.3"
)

FetchContent_MakeAvailable(httplib)

add_executable(lastfmAPI)
target_include_directories(test1 PRIVATE ../../../../../src)
file(GLOB sources "src/*.cpp" "src/*.h")
target_sources(lastfmAPI PRIVATE ${sources})

target_link_libraries(lastfmAPI nlohmann_json::nlohmann_json)
target_link_libraries(lastfmAPI httplib::httplib)
