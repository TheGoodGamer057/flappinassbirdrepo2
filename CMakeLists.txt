set(CMAKE_TOOLCHAIN_FILE "F:/Tools 2/C Stuff/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

cmake_minimum_required(VERSION 3.11)
project(rytm)

# 1. Set C++ standard
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
    json
    raylib
    GIT_REPOSITORY https://github.com
    GIT_TAG        master
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_definitions(-DRES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(rytm PRIVATE "${CMAKE_SOURCE_DIR}/includes")

target_link_libraries(${PROJECT_NAME} raylib)

find_package(tomlplusplus CONFIG REQUIRED)
target_link_libraries(main PRIVATE tomlplusplus::tomlplusplus)

if(PLATFORM STREQUAL "Web")
elseif(LINUX)
    target_link_libraries(${PROJECT_NAME} m pthread dl rt)
endif()
