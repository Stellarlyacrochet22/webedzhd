# Optional kernel driver — requires WDK
# Build with: cmake -DHWID_BUILD_DRIVER=ON

if(NOT HWID_BUILD_DRIVER)
    return()
endif()

message(STATUS "Driver build placeholder — add WDK sources here")
