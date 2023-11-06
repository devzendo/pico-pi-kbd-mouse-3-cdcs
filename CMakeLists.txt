cmake_minimum_required(VERSION 3.10.2)
# Thanks to https://crascit.com/2015/03/28/enabling-cxx11-in-cmake/
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Don't fall back to an earlier standard if the one declared isn't available
set(CMAKE_CXX_EXTENSIONS OFF)

include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)
set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")

project(pico-pi-kbd-mouse-3-cdcs)

pico_sdk_init()

link_libraries(pico_stdlib)

add_executable(usbexperiment main.cpp)

pico_add_extra_outputs(usbexperiment)

