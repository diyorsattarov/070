cmake_minimum_required(VERSION 3.0.0)
project(cpp-mysql VERSION 0.1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Sql REQUIRED)

add_executable(cpp-mysql mysql.cpp)

target_link_libraries(cpp-mysql Qt5::Core Qt5::Sql)
