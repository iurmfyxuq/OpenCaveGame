cmake_minimum_required(VERSION 3.10)
project(OpenCaveGame)

set(CMAKE_CXX_STANDARD 17)

include_directories(blaze3dcpp/include)
find_package(spdlog REQUIRED)

# add_subdirectory(blaze3dcpp)

add_executable(OpenCaveGame Start.cpp)
# target_link_libraries(OpenCaveGame blaze3dcpp)
# find_package(glad REQUIRED)
# find_package(glfw3 REQUIRED)
# find_package(glm REQUIRED)
# target_link_libraries(OpenCaveGame glad::glad glfw glm::glm)