cmake_minimum_required(VERSION 3.26)
project(ClosingIn)

set(CMAKE_CXX_STANDARD 20)

include_directories(ClosingIn/src)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    message("debug mode")
    add_compile_definitions(DEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    message("release mode")
    add_compile_definitions(RELEASE)
elseif (CMAKE_BUILD_TYPE MATCHES Dist)
    message("distribution mode")
    add_compile_definitions(DIST)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

add_executable(ClosingIn
        ClosingIn/src/main.cpp
        ClosingIn/src/pch.cpp
        ClosingIn/src/pch.h
        ClosingIn/src/Events/Event.cpp
        ClosingIn/src/Events/Event.h
        ClosingIn/src/Events/Input.cpp
        ClosingIn/src/Events/Input.h)

target_precompile_headers(ClosingIn PUBLIC ClosingIn/src/pch.h)