cmake_minimum_required(VERSION 3.18.4)
project(TicTacToeGame VERSION 0.1)
#cmake_policy(SET CMP0111 NEW)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(SFML_DIR ${CMAKE_BINARY_DIR}/../SFML-2.5.1/lib/cmake/SFML) # specify by your own
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

add_executable(
        ${CMAKE_PROJECT_NAME} WIN32
        src/main.cpp
        src/cross.cpp
        src/cross.h
        src/line.cpp
        src/line.h
        src/line.h
        src/line.cpp
        src/mathfuncs.cpp
        src/mathfuncs.h
)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)
#link_directories(${CMAKE_BINARY_DIR}/../SFML-2.5.1/lib/cmake/SFML)
include_directories(${CMAKE_BINARY_DIR}/../SFML-2.5.1/include)

#WSL
#[[target_link_libraries(
        ${CMAKE_PROJECT_NAME}
        debug "${SFML_SYSTEM_LIBRARY_DEBUG}"
        debug "${SFML_WINDOW_LIBRARY_DEBUG}"
        debug "${SFML_GRAPHICS_LIBRARY_DEBUG}"
        debug "${SFML_AUDIO_LIBRARY_DEBUG}"
        optimized "${SFML_SYSTEM_LIBRARY_RELEASE}"
        optimized "${SFML_WINDOW_LIBRARY_RELEASE}"
        optimized "${SFML_GRAPHICS_LIBRARY_RELEASE}"
        optimized "${SFML_AUDIO_LIBRARY_RELEASE}"
)]]

#MinGW
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system)