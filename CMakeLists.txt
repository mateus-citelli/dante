cmake_minimum_required(VERSION 3.16)

project(gamedemo)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(game
    src/main.cpp
    src/game.cpp
    src/player.cpp
    src/map.cpp
    src/boss.cpp
    src/room.cpp
    src/collision.cpp
)

target_link_libraries(game
    sfml-graphics
    sfml-window
    sfml-system
)
