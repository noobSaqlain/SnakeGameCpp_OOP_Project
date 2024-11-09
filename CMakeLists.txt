cmake_minimum_required(VERSION 3.29)
project(snakeGameOOp)

set(CMAKE_CXX_STANDARD 20)

add_executable(snakeGameOOp
        main.cpp
        MovableGameObject.h
        SnakeSegment.h
        Snake.cpp
        Snake.h
        Food.cpp
        Food.h
        Game.cpp
        Game.h
        ScoreManager.cpp
        ScoreManager.h
        Board.cpp
        Board.h
        UIManager.cpp
        UIManager.h
        UIManager.cpp
        StorageManager.cpp
        StorageManager.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(snakeGameOOp PRIVATE sfml-graphics sfml-window sfml-system)





