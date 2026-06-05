cmake_minimum_required(VERSION 3.16)
project(MelomanGUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(MelomanGUI
    main.cpp
    mainwindow.cpp
    addeditdialog.cpp
)

target_include_directories(MelomanGUI PRIVATE 
    ${CMAKE_SOURCE_DIR}/include/
    ${CMAKE_SOURCE_DIR}/src/
)

target_link_libraries(MelomanGUI PRIVATE Qt6::Widgets MusicLibrary)

set_target_properties(MelomanGUI PROPERTIES
    BUILD_RPATH "$ORIGIN/../../build"
    INSTALL_RPATH "$ORIGIN/../lib"
)

set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)
