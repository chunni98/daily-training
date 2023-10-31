cmake_minimum_required(VERSION 3.27)

# set the project name
project(datastructure)

include_directories(include)
include_directories(../include)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./src  SRC_LIST)

# add the executable
add_executable(main ${SRC_LIST})