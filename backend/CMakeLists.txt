cmake_minimum_required(VERSION 3.14)
project(OverGuard)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
add_executable(OverGuard src/main.cpp src/APIHandler.cpp)

# Include .h files
include_directories(include) # this must be before any FetchContent usages

include(FetchContent)

# Fetch nlohmann/json
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

# Fetch CPR
FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8  # Replace with the desired commit
)
FetchContent_MakeAvailable(cpr)

# Link libraries to your target
target_link_libraries(OverGuard PRIVATE cpr::cpr nlohmann_json::nlohmann_json)