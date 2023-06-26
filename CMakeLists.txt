cmake_minimum_required(VERSION 3.25)
project(squeal)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(squeal main.cpp lib/DB.cpp)
target_link_libraries(squeal ${SQLite3_LIBRARIES})

