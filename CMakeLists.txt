cmake_minimum_required(VERSION 3.16)

project(praise_pads VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Multimedia)

# Android specific settings
if(ANDROID)
    set(ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android)
    set(ANDROID_ABIS "arm64-v8a")
endif()

qt_add_executable(praise_pads
    main.cpp
    audiocontroller.cpp
    audiocontroller.h
)

qt_add_qml_module(praise_pads
    URI praise_pads
    VERSION 1.0
    QML_FILES main.qml
)

target_link_libraries(praise_pads
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Multimedia
)

# Android deployment settings
if(ANDROID)
    set_target_properties(praise_pads PROPERTIES
        QT_ANDROID_PACKAGE_SOURCE_DIR ${ANDROID_PACKAGE_SOURCE_DIR}
        QT_ANDROID_TARGET_SDK_VERSION 33
        QT_ANDROID_MIN_SDK_VERSION 23
        QT_ANDROID_VERSION_CODE 1
        QT_ANDROID_VERSION_NAME "1.0"
        QT_ANDROID_PACKAGE_NAME "com.example.praisepads"
    )
endif() 