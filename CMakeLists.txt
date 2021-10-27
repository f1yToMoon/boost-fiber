cmake_minimum_required(VERSION 3.20)
project(fiber)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.61.0 COMPONENTS fiber)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(fiber main.cpp)
    target_link_libraries(fiber ${Boost_LIBRARIES})
endif()
