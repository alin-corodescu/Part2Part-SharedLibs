cmake_minimum_required(VERSION 3.6)
project(shared_libraries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(IO_SRC include/IOWrappers.h lib/IOWrappers.cpp)
add_library(IOWrappers STATIC ${IO_SRC})

set(NET_SRC include/NetworkWrappers.h lib/NetworkWrappers.cpp)
add_library(NetworkWrappers STATIC ${NET_SRC})

set(CMD_SRC include/CommandBuilder.h include/CommandArgument.h include/Command.h
        lib/Command.cpp lib/CommandBuilder.cpp)
add_library(Commands ${CMD_SRC})

set(HSH_SRC include/IntegrityChecker.h lib/IntegrityChecker.cpp)
add_library(IntegrityChecker ${HSH_SRC})

set(FD_SRC include/FileDescription.h lib/FileDescription.cpp)
add_library(FileDescription ${FD_SRC})

set(ADDR_SRC include/Address.h lib/Address.cpp)
add_library(Address ${ADDR_SRC})