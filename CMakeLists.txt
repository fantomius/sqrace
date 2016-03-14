cmake_minimum_required(VERSION 3.3)
project(sqrace)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(./Engine)

set(SOURCE_FILES main.cpp Engine/Field.h Engine/Field.cpp Engine/FieldBuilder.h Engine/FieldBuilder.cpp)
add_executable(sqrace ${SOURCE_FILES})