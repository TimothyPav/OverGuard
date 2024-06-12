cmake_minimum_required(VERSION 3.10)
project(OverGuard)
set(CMAKE_CXX_STANDARD 17)

# Add all source files
add_executable(OverGuard src/main.cpp src/APIHandler.cpp)

# Include .h files
include_directories(include)

# Include CPR (C++ requests)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

target_link_libraries(OverGuard PRIVATE cpr::cpr)