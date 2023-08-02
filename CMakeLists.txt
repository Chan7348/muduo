cmake_minimum_required(VERSION 2.5)
project(muduo)

# cmake => makefile  make
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -fPIC")

aux_source_directory(src/ SRC_LIST)

add_library(muduo SHARED ${SRC_LIST})

add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_SOURCE_DIR}/lib
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${PROJECT_SOURCE_DIR}/CMakeFiles
    COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_SOURCE_DIR}/cmake_install.cmake
    COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_SOURCE_DIR}/CMakeCache.txt 
    COMMAND ${CMAKE_COMMAND} -E remove ${PROJECT_SOURCE_DIR}/Makefile   
)