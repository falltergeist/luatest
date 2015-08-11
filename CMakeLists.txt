cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/modules)

project(luatest)

add_definitions(-std=c++11 -Wall)

find_package(Lua 5.1 REQUIRED)
    
if (NOT LUA_FOUND)
    message(FATAL_ERROR "Lua library not found")
endif(NOT LUA_FOUND)
include_directories(${LUA_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES  src/*.cpp)
file(GLOB_RECURSE HEADERS  src/*.h)

add_executable(luatest main.cpp ${SOURCES} ${HEADERS})
target_link_libraries(luatest ${LUA_LIBRARY})



