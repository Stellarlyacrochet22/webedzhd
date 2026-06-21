if(NOT HWID_BUILD_GUI)
    return()
endif()

add_executable(HWIDSpooferGUI WIN32 gui/main.cpp)
target_link_libraries(HWIDSpooferGUI PRIVATE user32 gdi32)
target_compile_definitions(HWIDSpooferGUI PRIVATE UNICODE _UNICODE)
