cmake_minimum_required(VERSION 3.9)
project(DarkSnakesTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(DarkSnakesTest bosFunctions.cpp bosClient.cpp gameStates.cpp gameProperties.cpp snakeTypes.h helpers.cpp gameDraw.cpp input.cpp menu.cpp gameOver.cpp main.cpp ai.cpp ai.h map.cpp map.h game.cpp game.h)

target_link_libraries(DarkSnakesTest ws2_32 wsock32 advapi32 -static-libgcc -static-libstdc++)