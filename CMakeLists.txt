cmake_minimum_required(VERSION 3.18.4)
project(TicTacToeGame VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(SFML_STATIC_Libraries TRUE)
set(SFML_DIR ${CMAKE_BINARY_DIR}/../SFML-2.5.1/lib/cmake/SFML) #specify by your own
#[[set_target_properties(PROPERTIES LINK_SEARCH_START_STATIC 1)
set_target_properties(PROPERTIES LINK_SEARCH_END_STATIC 1)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")]]
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

add_executable(${CMAKE_PROJECT_NAME} WIN32 main.cpp cross.cpp cross.h line.cpp line.h line.h line.cpp mathfuncs.cpp mathfuncs.h)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
link_directories(${CMAKE_BINARY_DIR}/../SFML-2.5.1/lib/cmake/SFML)
include_directories(${CMAKE_BINARY_DIR}/../SFML-2.5.1/include)
target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        ${CMAKE_BINARY_DIR}/../sfml-audio-2.dll
        ${CMAKE_BINARY_DIR}/../sfml-graphics-2.dll
        ${CMAKE_BINARY_DIR}/../sfml-system-2.dll
        ${CMAKE_BINARY_DIR}/../sfml-window-2.dll
)
