#//////////////////////////////////////////////////////////////////////////////////

cmake_minimum_required(VERSION 3.26)

#//////////////////////////////////////////////////////////////////////////////////

project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(Engine/src Engine/vendor/glm Engine/vendor/GLFW/include)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_BUILD_TYPE Debug)
    message("debug mode")
    add_compile_definitions(DEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    message("release mode")
    add_compile_definitions(RELEASE)
elseif (CMAKE_BUILD_TYPE MATCHES Dist)
    message("distribution mode")
    add_compile_definitions(DIST)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

if(WIN32)
    add_compile_definitions(PLATFORM_WINDOWS)
elseif (UNIX)
    add_compile_definitions(PLATFORM_LINUX)
elseif (APPLE)
    add_compile_definitions(PLATFORM_MAC)
endif (WIN32)

add_library(Engine
        Engine/src/Events/Event.cpp
        Engine/src/Events/Event.h
        Engine/src/Events/Input.cpp
        Engine/src/Events/Input.h
        Engine/includes/EngineAPI.h
        Engine/src/Engine.cpp
        Engine/src/Engine.h
        Engine/src/EntryPoint.h
        Engine/src/SystemsManager/Layer.h
        Engine/src/SystemsManager/Scene.h
        Engine/src/SystemsManager/LayerStack.cpp
        Engine/src/SystemsManager/LayerStack.h
        Engine/src/SystemsManager/SceneStack.cpp
        Engine/src/SystemsManager/SceneStack.h
        Engine/src/Window/Window.cpp
        Engine/src/Window/Window.h)
target_precompile_headers(Engine PUBLIC Engine/src/pch.h)

#//////////////////////////////////////////////////////////////////////////////////

project(Closing)

set(CMAKE_CXX_STANDARD 20)

include_directories(Closing/src Engine/includes)

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

add_subdirectory(Engine/vendor/GLFW)

add_executable(Closing
        Closing/main.cpp
        Closing/Level-GreenHill/GameLayer.cpp
        Closing/Level-GreenHill/GameLayer.h
        Engine/src/Math/Math.h)
target_link_libraries(Closing Engine glfw)

#//////////////////////////////////////////////////////////////////////////////////
