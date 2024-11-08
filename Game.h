#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 25

class Game {
private:
    int gameState;  // 0 for main menu, 1 for game
    Food food;
    Snake snake;
    int score = 0;

    //  rect shape for buttons
    sf::RectangleShape startButton; // main page start button
    sf::RectangleShape scoreButton; // score page history button
    sf::RectangleShape restartButton; // restart button on gameover screen

    // Texts
    sf::Text startText; /// main start text
    sf::Text scoreText; // score text of snake
    sf::Text gameOverText; // final game over text when collision
    sf::Text restartText; // restart button text


    // Font for text
    sf::Font font;

public:
    Game();
    void build();
    void handleEvents(sf::RenderWindow &window);
    void drawMainMenu(sf::RenderWindow &window);
    void drawGame(sf::RenderWindow &window);
    void drawRestart(sf::RenderWindow &window);
    void drawRestartButton(sf::RenderWindow &window);
    void initButtons();
};

#endif
