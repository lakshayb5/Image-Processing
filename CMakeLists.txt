cmake_minimum_required(VERSION 2.0)
project(x)
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(bin_name a.cpp)
target_link_libraries(bin_name ${OpenCV_LIBS})
