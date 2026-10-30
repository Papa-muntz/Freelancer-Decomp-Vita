cmake_minimum_required(VERSION 3.10)
project(VitaTest)
set(CMAKE_CXX_STANDARD 17)

# To bypass windows.h include, we define some dummy macros
add_definitions(-D_WIN32)
add_definitions(-DWIN32_LEAN_AND_MEAN)

include_directories(.)
include_directories(../src/include)
include_directories(../src/x86math)

add_executable(vitatest main.cpp ../src/x86math/x86math.cpp stubs.cpp)
