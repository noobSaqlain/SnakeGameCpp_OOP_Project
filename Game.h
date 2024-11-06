//
// Created by LENOVO on 04/11/2024.
//

#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
// #include "ScoreManager.h"
// #include "UIManager.h"
// #include "Board.h"

using namespace sf;
class Game {
private:
    //Snake snake;
    Food food;
    // ScoreManager scoreManager;
    // UIManager uiManager;
    // Board board;
    bool isRunning;
    bool isPaused;
    const int tileSize = 25;
public:
    Game();
    // void startGame();
    // void pauseGame();
    // void updateGame();
    // void endGame();
    // void checkCollisions();
    void draw(RenderWindow& window);
};

#endif




