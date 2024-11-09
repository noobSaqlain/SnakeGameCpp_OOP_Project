#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>

#include "Board.h"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 25

class Game {
private:

    Food food;
    Snake snake;
    ScoreManager scoreManager;
    Board board;

    int score = 0;
    float timer;

    //  rect shape for buttons
    sf::RectangleShape startButton; // main page start button
    sf::RectangleShape scoreButton; // score page history button
    sf::RectangleShape restartButton; // restart button on gameover screen
    sf::RectangleShape backToMenuButton; // back to menu, button in gameover state

    // Texts
    sf::Text startText; /// main start text
    sf::Text scoreText; // score text of snake
    sf::Text gameOverText; // final game over text when collision
    sf::Text restartText; // restart button text
    sf::Text backToMenuText; // back to menu text when gameover

    bool isRunning;
    bool isPaused;
    bool isGameOver;
    // Font for text
    sf::Font font;

public:
    Game();
///////////////////////////
    void startGame();
    void pauseGame();
    void restartGame();
    void updateGame();
    void checkCollision();

/////////////

    void build();
    void handleEvents(sf::RenderWindow &window);
    void drawMainMenu(sf::RenderWindow &window);
    void drawGame(sf::RenderWindow &window);
    void drawRestart(sf::RenderWindow &window);
    void drawRestartButton(sf::RenderWindow &window);
    void initButtons();
    void setStates(bool pause, bool run, bool over);
};

#endif
