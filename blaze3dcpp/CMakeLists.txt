project(blaze3dcpp)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

include_directories(include/platform)

# GCC/Clang 的警告选项
#add_compile_options(-Wall -Wextra -pedantic -Werror)
# 可选：更严格的警告
#add_compile_options(-Wconversion -Wshadow -Wdouble-promotion -Wformat=2)

add_subdirectory(platform)

add_library(blaze3dcpp
    ${PLATFORM_CPP_SOURCES}
)

target_link_libraries(blaze3dcpp glad::glad glfw glm::glm spdlog::spdlog)