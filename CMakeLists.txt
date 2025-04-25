cmake_minimum_required(VERSION 3.10)
project(OpenCaveGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(blaze3dcpp/include)
# add_subdirectory(blaze3dcpp)

add_executable(OpenCaveGame Start.cpp)
# target_link_libraries(OpenCaveGame blaze3dcpp)