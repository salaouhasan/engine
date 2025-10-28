cmake_minimum_required(VERSION 3.22)
project(editor)


add_executable(Editor src/main_editor.cpp src/EditorApp.cpp src/EditorUI.cpp)


target_link_libraries(Editor PRIVATE Engine)


# ensure runtime can find shaders/assets
add_custom_command(TARGET Editor POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
${CMAKE_SOURCE_DIR}/engine/shaders $<TARGET_FILE_DIR:Editor>/shaders)