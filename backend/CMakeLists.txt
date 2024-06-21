cmake_minimum_required(VERSION 3.14)
project(OverGuard)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch dependencies
include(FetchContent)

FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8
)
FetchContent_MakeAvailable(cpr)

# Include directories
include_directories(include)  # Include your project headers

# Define the SQLite library
add_library(sqlite STATIC lib/sqlite/sqlite3.c)
target_include_directories(sqlite PUBLIC ${CMAKE_SOURCE_DIR}/lib/sqlite)

# Add source files to executable
add_executable(OverGuard src/Database_Operations.cpp src/main.cpp src/APIHandler.cpp src/Heroes.cpp src/JsonSerializer.cpp lib/sqlite/sqlite3.c)

# Link libraries to your target
target_link_libraries(OverGuard PRIVATE cpr::cpr nlohmann_json::nlohmann_json sqlite)