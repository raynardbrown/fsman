cmake_minimum_required(VERSION 3.15.5)

# Set the name of the project and store it in a variable, PROJECT_NAME.
project(fsman)

set(Headers "")
list(APPEND Headers ${CMAKE_CURRENT_SOURCE_DIR}/inc)

set(Sources src/maingui.cpp)

if (MSVC)
    add_compile_options(-Zi
                        -W4
                        -EHsc
                        -D_CRT_SECURE_NO_WARNINGS
                        -DSTRICT
                        -DUNICODE
                        -D_UNICODE)
else()
    # fail until we target more platforms
    message(FATAL_ERROR "compiler not supported")
endif()

set(Libraries "")

# Note: the user must _NOT_ specify relative paths to the CMAKE_PREFIX_PATH
# variable via the command line or the CMake generation will fail. I believe
# this behavior is a limitation of CMake.
find_library(UI_LAYOUT_LIBRARY ui_layout PATH_SUFFIXES ui_layout/build)

# Verify that CMake has found the ui_layout library. If CMake is unable to find
# the library, fail with a fatal error and output a message to the user.
if(NOT UI_LAYOUT_LIBRARY)
  message(FATAL_ERROR "ui_layout library not found")
endif()

list(APPEND Libraries ${UI_LAYOUT_LIBRARY})

find_library(UI_LIBRARY ui PATH_SUFFIXES ui/build)

if(NOT UI_LIBRARY)
  message(FATAL_ERROR "ui library not found")
endif()

list(APPEND Libraries ${UI_LIBRARY})

find_path(UI_INCLUDE NAMES Window.h PATH_SUFFIXES ui/inc)

if(NOT UI_INCLUDE)
  message(FATAL_ERROR "ui headers not found")
endif()

list(APPEND Headers ${UI_INCLUDE})

add_executable(${PROJECT_NAME} ${Sources})

if (MSVC)
    target_link_options(${PROJECT_NAME} PRIVATE -SUBSYSTEM:WINDOWS
                                                -ENTRY:mainCRTStartup)
else()
    # fail until we target more platforms
    message(FATAL_ERROR "compiler not supported")
endif()

target_link_libraries(${PROJECT_NAME} ${Libraries})

target_include_directories(${PROJECT_NAME} PRIVATE ${Headers})