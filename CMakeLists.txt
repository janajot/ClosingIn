cmake_minimum_required(VERSION 3.26)
project(ClosingIn)

set(CMAKE_CXX_STANDARD 14)

include_directories(ClosingIn/src)

add_executable(ClosingIn
        ClosingIn/src/main.cpp
        ClosingIn/src/pch.cpp
        ClosingIn/src/pch.h)

target_precompile_headers(ClosingIn PUBLIC ClosingIn/src/pch.h)