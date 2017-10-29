cmake_minimum_required(VERSION 3.9)
project(Whatever)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11")
set(CXX_LINKER_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${CXX_LINKER_FLAGS}")

set(EXECUTABLE_NAME "Whatever")
set(SOURCE_FILES
        Main.cpp
        Codex.cpp Codex.hpp
        Animation.cpp Animation.hpp
        Easing.hpp
        Tween.hpp
        GameObject.hpp
        Camera.hpp Camera.cpp
        block/Block.hpp block/Block.cpp
        block/Inner.hpp block/Inner.cpp
        block/Outer.hpp block/Outer.cpp
        Handler.hpp Handler.cpp
        Player.hpp Player.cpp)

set(PLAYER_RESOURCES
        IdleRight.png IdleLeft.png
        WalkRight.png WalkLeft.png
        RunRight.png RunLeft.png
        JumpRight.png JumpLeft.png
        FallRight.png FallLeft.png)

foreach(RESOURCE ${PLAYER_RESOURCES})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/Player/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window)

include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})