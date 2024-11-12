#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "UIManager.h"
using namespace sf;

/////////  CONSTRUCTOR   //////////
Game::Game() : food(0, 0, TILE_SIZE),
            snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, TILE_SIZE),
            board(SCREEN_WIDTH,SCREEN_HEIGHT)
            {
    uiManager = new UIManager(this);
    setStates(true,false,false);
}
////////  DESTRUCTOR  ///////////
Game::~Game() {
    if (uiManager) delete uiManager;
}



////////  UI logic  ////////////
void Game::build() {
    RenderWindow window(VideoMode(board.getScreenWidth(), board.getScreenHeight()), "Snake Game");///scren created

    /*
     * clock is used to track and control the timing of events, specifically for updating the snake’s movement.
     * a clock object can be used to track the time since it was created or last reset.
     */
    Clock clock;
    timer = 0.0f; /// elapsed timr -> amount of time that has passed between two points in time.
    float delay = 0.1f;  // Delay for snake movement -> snake moves in every 0.1 seconds

    while (window.isOpen()) { ///// while our screen in open
        float time = clock.restart().asSeconds(); // this resets the clock and returns the elapsed time (in seconds) since the last reset.
        timer += time; // This elapsed time is added to timer, which accumulates time between updates.

        handleEvents(window); // input handler

        if (isRunning && timer > delay) { //// if timer exceeds 0.1 second and isRunning true, then the movement of snake occurs and timer is set to 0 again
            snake.move();
            timer = 0; // reset timer
            if (snake.checkCollision() || snake.checkSelfCollision()) { ////// game over collision check
                setStates(false, false, true);  // Set game over state
            } else if (food.checkIfEaten(snake)) { ///// contact logic between snake head and food
                snake.grow();
                uiManager->updateScore();
                food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT); //// generate food in new random place
            }
        }

        window.clear(); //This clears the window at the beginning of each frame to remove any previous drawings. This is a common practice to prevent overlapping visuals from previous frames.
        ///////pages management based on states
        if (isGameOver) {
            uiManager->drawRestart(window);  // Draw the game-over screen
        } else if (isPaused) { //// paused have to buttons so two conditions
            if(uiManager->getIsScorePageOpened())
                uiManager->drawScorePage(window); // Draw score page
            else
                uiManager->drawMainMenu(window); // Draw the main menu
        } else if (isRunning) {
            uiManager->drawGame(window,snake, food, board);     // Draw the game
            uiManager->drawScore(window);
        }
        window.display();//This command displays everything drawn in this frame

    }
}

//input handler
void Game::handleEvents(sf::RenderWindow &window) {
    Event event; /// event such as mouse pressed, hover, keyboard listener etc.
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        } else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) { /// if mouse click or mouse button pressed
            Vector2i mousePos = Mouse::getPosition(window);////// to get position of mouse cursor relative to specific window
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

/////state manager
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






