cmake_minimum_required(VERSION 3.15)
project(OpenCV_Demo)

set(OpenCV_DIR G:/code/opencv/build/install)
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status")
message(STATUS "....version: ${OpenCV_VERSION}")
message(STATUS "....libraries: ${OpenCV_LIBS}")
message(STATUS "....include paths: ${OpenCV_INCLUDE_DIRS}")

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(Chapter01)