add_executable(HWIDSpoofer
    cli/main.cpp
    core/Logger.cpp
    core/BackupManager.cpp
    core/SpoofEngine.cpp
    core/HwidReader.cpp
    modules/DiskSerialSpoofer.cpp
    modules/SmbiosSpoofer.cpp
    modules/MacSpoofer.cpp
    modules/VolumeSerialSpoofer.cpp
    modules/RegistryCleaner.cpp
)

target_include_directories(HWIDSpoofer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/modules
)

target_link_libraries(HWIDSpoofer PRIVATE
    iphlpapi
    setupapi
    wbemuuid
)

if(WIN32)
    target_compile_definitions(HWIDSpoofer PRIVATE UNICODE _UNICODE WIN32_LEAN_AND_MEAN)
endif()

if(HWID_NO_DRIVER)
    target_compile_definitions(HWIDSpoofer PRIVATE HWID_NO_DRIVER=1)
endif()
