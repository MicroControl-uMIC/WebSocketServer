cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_C_COMPILER "/usr/bin/arm-linux-gnueabihf-gcc-8")
set(CMAKE_CXX_COMPILER "/usr/bin/arm-linux-gnueabihf-g++-8")

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /opt/umic200/sysroot)
set(CMAKE_STAGING_PREFIX /home/umic)


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

include_directories(SYSTEM /opt/umic200/sysroot/usr/local/include)


project(WebSocketServer VERSION 1.0.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core WebSockets REQUIRED)

list (
    APPEND WEB_SOCKET_SOURCES
    source/main.cpp
    source/web_socket_server.cpp
)

add_executable(${PROJECT_NAME} ${WEB_SOCKET_SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::WebSockets)
