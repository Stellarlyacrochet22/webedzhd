cmake_minimum_required(VERSION 3.20)
project(HWIDSpoofer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(HWID_NO_DRIVER "Build without kernel driver support" OFF)
option(HWID_BUILD_GUI "Build Win32 GUI" ON)
option(HWID_BUILD_DRIVER "Build WDK kernel driver" OFF)

add_subdirectory(src)

if(HWID_BUILD_GUI)
    add_subdirectory(src/gui)
endif()

if(HWID_BUILD_DRIVER AND NOT HWID_NO_DRIVER)
    add_subdirectory(driver)
endif()
