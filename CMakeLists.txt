cmake_minimum_required(VERSION 3.18.4)
project(TicIacToeGame VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(SFML_STATIC_Libraries TRUE)
set(SFML_DIR D:/Programming/SFML-2.5.1/lib/cmake/SFML) #specify by your own
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(${CMAKE_PROJECT_NAME} main.cpp figure.cpp cross.cpp cross.h line.cpp line.h line.h line.cpp mathfuncs.cpp mathfuncs.h)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
link_directories(D:/Programming/SFML-2.5.1/lib/cmake/SFML)
include_directories(D:/Programming/SFML-2.5.1/include)
#target_link_libraries(${CMAKE_PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        "D:/Programming/IDE/CLionProjects/Tic-Tac-Toe-Game/sfml-audio-2.dll"
        "D:/Programming/IDE/CLionProjects/Tic-Tac-Toe-Game/sfml-graphics-2.dll"
        "D:/Programming/IDE/CLionProjects/Tic-Tac-Toe-Game/sfml-system-2.dll"
        "D:/Programming/IDE/CLionProjects/Tic-Tac-Toe-Game/sfml-window-2.dll"
)
