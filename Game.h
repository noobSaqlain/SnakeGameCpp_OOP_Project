#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>

#include "Board.h"




#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 25

class UIManager;
class Game {
private:
    UIManager* uiManager;
    Food food;
    Snake snake;
    Board board;

    float timer;
    bool isRunning;
    bool isPaused;
    bool isGameOver;


public:

    Game();
    ~Game();
///////////////////////////
    void startGame();
    void pauseGame();
    void restartGame();
    void updateGame();
    void checkCollision();

/////////////

    void build();
    void handleEvents(sf::RenderWindow &window);
    bool getIsPausedStatus() const;
    bool getIsRunningStatus() const;
    bool getIsGameOverStatus() const;
    void setStates(bool pause, bool run, bool over);
};

#endif
