cmake_minimum_required(VERSION 3.10)

project(Coffee)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(${PROJECT_SOURCE_DIR}/src)

# Qt6 Core
find_package(Qt6 REQUIRED COMPONENTS Core)
target_link_libraries(mytarget PRIVATE Qt6::Core)

# Qt6 Gui
find_package(Qt6 REQUIRED COMPONENTS Gui)
target_link_libraries(mytarget PRIVATE Qt6::Gui)


# Path to the Qt toolchain file for Emscripten
set(CMAKE_TOOLCHAIN_FILE $ENV{EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES src/main.cpp src/MainWindow.cpp)
set(HEADERS include/MainWindow.h)
set(RESOURCES resources/resources.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${RESOURCES})

# Specify the HTML template if needed
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "--shell-file ${CMAKE_SOURCE_DIR}/your_template.html")

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(${PROJECT_NAME} PRIVATE include)
