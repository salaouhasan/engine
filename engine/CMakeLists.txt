cmake_minimum_required(VERSION 3.21)
project(EngineCore LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Add vcpkg support (for GLFW, GLEW, GLM, spdlog, yaml-cpp, EnTT, etc.) ---
find_package(glfw3 CONFIG REQUIRED PATHS "C:/vcpkg/installed/x64-windows/share/glfw3")
find_package(GLEW CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)

# --- Source files ---
file(GLOB_RECURSE ENGINE_SOURCES
    "src/*.cpp"
    "src/*.h"
)

add_library(EngineCore STATIC ${ENGINE_SOURCES})
target_include_directories(EngineCore PUBLIC "src")

# --- Link libraries ---
target_link_libraries(EngineCore
    PUBLIC
        glfw
        GLEW::GLEW
        glm
        spdlog::spdlog
        yaml-cpp
        EnTT::EnTT
)
