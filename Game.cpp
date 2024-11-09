#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "UIManager.h"
using namespace sf;


Game::Game() : food(0, 0, TILE_SIZE),
            snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, TILE_SIZE),
            board(SCREEN_WIDTH,SCREEN_HEIGHT)
            {
    uiManager = new UIManager(this);
    setStates(true,false,false);
}
Game::~Game() {
    if (uiManager) delete uiManager;
}





void Game::build() {
    RenderWindow window(VideoMode(board.getScreenWidth(), board.getScreenHeight()), "Snake Game");

    Clock clock;
    timer = 0.0f;
    float delay = 0.1f;  // Delay for snake movement

    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;

        handleEvents(window);

        if (isRunning && timer > delay) { //// frames
            snake.move();
            timer = 0;

            if (snake.checkCollision() || snake.checkSelfCollision()) {
                setStates(false, false, true);  // Set game over state
            } else if (food.checkIfEaten(snake)) {
                snake.grow();

                food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
        }

        window.clear();
        if (isGameOver) {
            uiManager->drawRestart(window);  // Draw the game-over screen
        } else if (isPaused) {

            if(uiManager->getIsScorePageOpened())
                uiManager->drawScorePage(window);
            else
                uiManager->drawMainMenu(window); // Draw the main menu
        } else if (isRunning) {
            uiManager->drawGame(window,snake, food, board);     // Draw the game
        }
        window.display();

    }
}

void Game::handleEvents(sf::RenderWindow &window) {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        } else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            Vector2i mousePos = Mouse::getPosition(window);
            uiManager->handleInputs(mousePos,snake,food);
        }else if (event.type == Event::KeyPressed) {
            switch (event.key.code) {
                case Keyboard::Up: snake.changeDirection(Direction::Up); break;
                case Keyboard::Down: snake.changeDirection(Direction::Down); break;
                case Keyboard::Left: snake.changeDirection(Direction::Left); break;
                case Keyboard::Right: snake.changeDirection(Direction::Right); break;
                default: break;
            }
        }
    }
}

void Game::setStates(bool pause, bool run, bool over) {
    this->isPaused = pause;
    this->isRunning = run;
    this->isGameOver = over;
}

bool Game::getIsPausedStatus() const {
    return isPaused;
}
bool Game::getIsRunningStatus() const {
    return isRunning;
}
bool Game::getIsGameOverStatus() const {
    return isGameOver;
}






