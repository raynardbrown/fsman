cmake_minimum_required(VERSION 3.15.5)

# Set the name of the project and store it in a variable, PROJECT_NAME.
project(fsman)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_executable(fsman src/maingui.cpp)
target_link_libaries(fsman archive)