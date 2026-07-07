cmake_minimum_required(VERSION 3.20)
project(GraphAlgorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(app
    src/main.cpp
    src/graph.cpp
)

target_include_directories(app
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
