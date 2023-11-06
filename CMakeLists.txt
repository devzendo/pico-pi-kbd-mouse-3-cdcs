cmake_minimum_required(VERSION 3.13)
# Thanks to https://crascit.com/2015/03/28/enabling-cxx11-in-cmake/
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Don't fall back to an earlier standard if the one declared isn't available
set(CMAKE_CXX_EXTENSIONS OFF)

include(pico_sdk_import.cmake)
include(pico_extras_import.cmake)
set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")

project(usbexperiment)

pico_sdk_init()

include_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(usbexperiment)
target_sources(usbexperiment PUBLIC main.cpp hid_usb.cpp)

# Ensure TinyUSB can find tusb_config.h
target_include_directories(usbexperiment PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# In addition to pico_stdlib required for common PicoSDK functionality, add dependency on tinyusb_device
# for TinyUSB device support and tinyusb_board for the additional board support library used by the example
target_link_libraries(usbexperiment PUBLIC pico_stdlib pico_unique_id tinyusb_host tinyusb_board)


pico_add_extra_outputs(usbexperiment)

