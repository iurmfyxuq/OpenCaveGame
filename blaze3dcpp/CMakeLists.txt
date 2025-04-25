project(blaze3dcpp)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_program(CLANG_TIDY_BIN NAMES "clang-tidy")
if(CLANG_TIDY_BIN)
  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_BIN}" "-checks=*")
endif()

add_subdirectory(platform)

add_library(blaze3dcpp
    ${PLATFORM_CPP_SOURCES}
)

target_link_libraries(blaze3dcpp glad::glad glfw glm::glm spdlog::spdlog)