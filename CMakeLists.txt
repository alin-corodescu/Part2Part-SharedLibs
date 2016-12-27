cmake_minimum_required(VERSION 3.6)
project(shared_libraries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_IOWrappers lib/IOWrappers.cpp include/IOWrappers.h)
add_library(shared ${SOURCE_FILES_IOWrappers})
