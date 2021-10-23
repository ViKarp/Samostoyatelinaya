cmake_minimum_required(VERSION 3.20)
project(untitled3)

set(CMAKE_CXX_STANDARD 23)
find_package(Threads REQUIRED)
add_executable(untitled3 main.cpp)

include_directories(includes)
set(CMAKE_CXX_STANDARD 20)
find_package(Threads REQUIRED)
target_link_libraries(untitled3  Threads::Threads)