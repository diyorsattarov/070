cmake_minimum_required(VERSION 3.10)
project(cpp-server)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required Boost components
find_package(Boost 1.73 REQUIRED COMPONENTS system thread regex log_setup log)
# Include directories
include_directories(${Boost_INCLUDE_DIR})

# Add executable
add_executable(cpp-server main.cpp)

# Link libraries
target_link_libraries(cpp-server ${Boost_LIBRARIES} Boost::regex Boost::log_setup Boost::log)