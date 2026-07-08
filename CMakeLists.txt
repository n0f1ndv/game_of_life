cmake_minimum_required(VERSION 3.20)
project(GameOfLife LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(include/SDL EXCLUDE_FROM_ALL)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(app
    src/main.c
    src/board.c
)

target_include_directories(app
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(app PRIVATE SDL3::SDL3)