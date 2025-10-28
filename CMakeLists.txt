cmake_minimum_required(VERSION 3.22)
project(GameEnginePrototype VERSION 0.1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Use vcpkg toolchain when available (pass as -DCMAKE_TOOLCHAIN_FILE=...)


add_subdirectory(engine)
add_subdirectory(editor)
add_subdirectory(samples/game)