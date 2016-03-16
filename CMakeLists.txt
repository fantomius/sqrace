cmake_minimum_required(VERSION 3.3)
project(sqrace)

FIND_PACKAGE( Boost COMPONENTS system REQUIRED )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(./Engine)

file(GLOB Engine "Engine/*.h" "Engine/*.cpp")
set(SOURCE_FILES main.cpp ${Engine})
add_executable(sqrace ${SOURCE_FILES})

target_link_libraries( sqrace ${Boost_LIBRARIES} )