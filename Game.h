#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>

#include "Board.h"



///constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 25

/*
 * circular dependency is when two objects have to reference each other, making compiler confuse to which object compile first
 */
class UIManager; ///// to remove circular dependency
class Game {
private:
    UIManager* uiManager;
    Food food;
    Snake snake;
    Board board;

    float timer;
    ///// states of game
    bool isRunning;
    bool isPaused;
    bool isGameOver;


public:

    Game();
    ~Game();

    void build(); //// gui logic
    void handleEvents(sf::RenderWindow &window); ///// input events handler
    bool getIsPausedStatus() const;
    bool getIsRunningStatus() const;
    bool getIsGameOverStatus() const;
    void setStates(bool pause, bool run, bool over); /// state manager
};

#endif
