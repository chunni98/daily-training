cmake_minimum_required(VERSION 3.27)

# set the project name
project(datastructure)

include_directories(include)
include_directories(../include)

set(CMAKE_CXX_STANDARD 17)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG")

aux_source_directory(./src  SRC_LIST)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# add the executable
add_executable(main ${SRC_LIST})