#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : food(0, 0, TILE_SIZE),
            snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, TILE_SIZE),
            board(SCREEN_WIDTH,SCREEN_HEIGHT) {
    initButtons();
    setStates(true,false,false);

}
void Game::initButtons() {
    try {
        if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts/Neucha-Regular.ttf")) {
            std::cerr << "Error: Could not load font from the specified path." << std::endl;
            return;
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception caught during font loading: " << e.what() << std::endl;
    }

    // start button
    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color::Green);
    startButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 60);

    startText.setFont(font);
    startText.setString("Game Start");
    startText.setCharacterSize(24);
    startText.setFillColor(sf::Color::Black);
    sf::FloatRect startTextRect = startText.getLocalBounds();
    startText.setPosition(
        startButton.getPosition().x + (startButton.getSize().x - startTextRect.width) / 2,
        startButton.getPosition().y + (startButton.getSize().y - startTextRect.height) / 2 - 5
    );

    // score button
    scoreButton.setSize(sf::Vector2f(200, 50));
    scoreButton.setFillColor(sf::Color::Green);
    scoreButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 10);

    scoreText.setFont(font);
    scoreText.setString("Score History");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    sf::FloatRect scoreTextRect = scoreText.getLocalBounds();
    scoreText.setPosition(
        scoreButton.getPosition().x + (scoreButton.getSize().x - scoreTextRect.width) / 2,
        scoreButton.getPosition().y + (scoreButton.getSize().y - scoreTextRect.height) / 2 - 5
    );

    //restart button
    restartButton.setSize(sf::Vector2f(200, 50));
    restartButton.setFillColor(sf::Color::Red);
    restartButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 70);

    restartText.setFont(font);
    restartText.setString("Restart");
    restartText.setCharacterSize(24);
    restartText.setFillColor(sf::Color::White);
    sf::FloatRect restartTextRect = restartText.getLocalBounds();
    restartText.setPosition(
        restartButton.getPosition().x + (restartButton.getSize().x - restartTextRect.width) / 2,
        restartButton.getPosition().y + (restartButton.getSize().y - restartTextRect.height) / 2 - 5
    );

    /////back to menu button
    ///
    backToMenuButton.setSize(sf::Vector2f(200, 50));
    backToMenuButton.setFillColor(sf::Color::Blue);
    backToMenuButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 130);

    backToMenuText.setFont(font);
    backToMenuText.setString("Back to Menu");
    backToMenuText.setCharacterSize(24);
    backToMenuText.setFillColor(sf::Color::White);
    sf::FloatRect backToMenuTextRect = backToMenuText.getLocalBounds();
    backToMenuText.setPosition(
        backToMenuButton.getPosition().x + (backToMenuButton.getSize().x - backToMenuTextRect.width) / 2,
        backToMenuButton.getPosition().y + (backToMenuButton.getSize().y - backToMenuTextRect.height) / 2 - 5
    );
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
                score++;
                food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT);
            }
        }

        window.clear();
        if (isGameOver) {
            drawRestart(window);  // Draw the game-over screen
        } else if (isPaused) {
            drawMainMenu(window); // Draw the main menu
        } else if (isRunning) {
            drawGame(window);     // Draw the game
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
            if (isPaused && startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                setStates(false,true,false); /// start game, set run start to true and pause to false
            }
            else if (isGameOver && restartButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                setStates(false, true, false);  // Restart game, set running state to true
                snake.resetSnake();             // Reset snake to its initial state
                score = 0;                      // Reset the score
                                   // Reset any game timer if it affects game state
                food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT);  // Reset food position
            }

            else if (isGameOver && backToMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                setStates(true, false, false); // Go back to the main menu
                snake.resetSnake();            // Reset snake position and size
                score = 0;                     // Reset score if needed

            }
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

void Game::drawMainMenu(sf::RenderWindow &window) { ////// two buttons. one for start game and other for score history
    window.draw(startButton);
    window.draw(scoreButton);
}

void Game::drawGame(sf::RenderWindow &window) { /// when isRunning true, draw food, snake, and score;
    board.drawFood(food, window);
    board.drawSnake(snake, window);
}
void Game::drawRestart(sf::RenderWindow &window) {

    // Display Game Over text
    gameOverText.setFont(font);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("Game Over");
    gameOverText.setCharacterSize(50);
    sf::FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setPosition((SCREEN_WIDTH - textRect.width) / 2, (SCREEN_HEIGHT - textRect.height) / 2);

    window.draw(gameOverText);

    // Draw the restart and back to menu buttons
    drawRestartButton(window);
    window.draw(backToMenuButton);
    window.draw(backToMenuText);
}


void Game::drawRestartButton(sf::RenderWindow &window) {
    window.draw(restartButton);
    window.draw(restartText);
}

void Game::setStates(bool pause, bool run, bool over) {
    this->isPaused = pause;
    this->isRunning = run;
    this->isGameOver = over;
}




