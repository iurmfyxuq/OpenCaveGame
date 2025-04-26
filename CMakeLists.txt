cmake_minimum_required(VERSION 3.10)
project(OpenCaveGame)

set(CMAKE_CXX_STANDARD 17)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(blaze3dcpp/include)
include_directories(blaze3dcpp/include/utils)

add_subdirectory(blaze3dcpp)

add_executable(OpenCaveGame Start.cpp)
target_link_libraries(OpenCaveGame blaze3dcpp)