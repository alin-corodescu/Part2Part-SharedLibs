cmake_minimum_required(VERSION 3.6)
project(shared_libraries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES_IOWrappers lib/IOWrappers.cpp include/IOWrappers.h include/NetworkWrappers.h lib/NetworkWrappers.cpp
        include/Command.h include/CommandArgument.h include/CommandBuilder.h include/FileDescription.h
        lib/CommandBuilder.cpp lib/Command.cpp include/FileDescription.cpp)
set(IO_SRC include/IOWrappers.h lib/IOWrappers.cpp)
add_library(IOWrappers STATIC ${IO_SRC})
add_library(shared ${SOURCE_FILES_IOWrappers})
