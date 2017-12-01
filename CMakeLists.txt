cmake_minimum_required(VERSION 3.9)
project(Whatever)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++14")
endif(APPLE)

set(SFML_LIB_PATH /usr/local/lib)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CXX_LINKER_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${CXX_LINKER_FLAGS}")
set(SOURCE_FILES
        src/Main.cpp
        src/graphics/Codex.cpp src/graphics/Codex.hpp
        src/graphics/Animation.cpp src/graphics/Animation.hpp
        src/penner/Easing.hpp
        src/penner/Tween.hpp
        src/objects/GameObject.hpp
        src/window/Camera.hpp src/window/Camera.cpp
        src/objects/block/Block.hpp src/objects/block/Block.cpp
        src/window/Handler.cpp src/window/Handler.hpp
        src/objects/Player.cpp src/objects/Player.hpp
        src/game/State.cpp src/game/State.hpp
        src/game/StateMachine.cpp src/game/StateMachine.hpp
        src/game/Application.cpp src/game/Application.hpp
        src/game/SplashState.cpp src/game/SplashState.hpp
        src/game/PlayState.cpp src/game/PlayState.hpp
        src/game/MenuState.cpp src/game/MenuState.hpp
        src/gui/Menu.cpp src/gui/Menu.hpp
        src/gui/Item.cpp src/gui/Item.hpp
        src/scene/Scene.cpp src/scene/Scene.hpp
        src/scene/Fragment.cpp src/scene/Fragment.hpp
        src/Flags.hpp src/utils/Misc.hpp
        src/penner/Fader.cpp src/penner/Fader.hpp)

set(OTHER_RESOURCES
        Logo.png
        Level.png
        Polya.otf)

foreach(RESOURCE ${OTHER_RESOURCES})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/${RESOURCE}
        ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

set(SKELETON_RESOURCES
        IdleRight.png IdleLeft.png
        WalkRight.png WalkLeft.png
        ReactRight.png ReactLeft.png
        DeadRight.png DeadLeft.png
        HitRight.png HitLeft.png
        AttackRight.png AttackLeft.png)

foreach(RESOURCE ${SKELETON_RESOURCES})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/res/Skeleton/${RESOURCE}
            ${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE} COPYONLY)
endforeach(RESOURCE)

add_definitions(-DBUILD_${CMAKE_BUILD_TYPE})
message(STATUS "BUILDTYPE:" ${BUILD_TYPE})
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window)
include_directories(${SFML_INCLUDE_DIR} include)
link_directories(${SFML_LIB_PATH})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})