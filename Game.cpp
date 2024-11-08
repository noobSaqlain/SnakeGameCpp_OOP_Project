#include "Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game() : food(0, 0, TILE_SIZE), snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, TILE_SIZE), gameState(0) {
   initButtons();
}
void Game::initButtons() {
     // Load the font
    if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts//Neucha-Regular.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return;
    }

    // Configure the start button
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

    // Configure the score button
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
}


void Game::build() {
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game");

    Clock clock;
    float timer = 0.0f;
    float delay = 0.1f;  // Delay for snake movement

    while (window.isOpen()) {
        float time = clock.restart().asSeconds();
        timer += time;

        handleEvents(window);

        if (gameState == 1 && timer > delay) {
            snake.move();
            timer = 0;
        }

        window.clear();
        if(snake.checkCollision() || snake.checkCollision()) {
            drawRestart(window);
        }
        if(food.checkIfEaten(snake)) {
            snake.grow();
            score++;
            food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT);
        }

        if (gameState == 0) {
            drawMainMenu(window);
        } else if (gameState == 1) {
            drawGame(window);
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
            if (startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                gameState = 1;
            }
            else if (restartButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                gameState = 1;  // start game again
                snake.resetSnake();  // Optionally, reset snake to initial state if needed
                score = 0;      // Optionally reset the score
                food.generateNewPosition(SCREEN_WIDTH,SCREEN_HEIGHT);
            }
        } else if (event.type == Event::KeyPressed) {
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

void Game::drawMainMenu(sf::RenderWindow &window) {
    window.draw(startButton);
    window.draw(scoreButton);
}

void Game::drawGame(sf::RenderWindow &window) {
    snake.draw(window);
    food.drawFood(window);
}
void Game::drawRestart(sf::RenderWindow &window) {
    // Check if the font is loaded, else load it
    if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts/Neucha-Regular.ttf")) {

        return;
    }
    food.setFoodPosition(-99999,-99999);
    drawRestartButton(window);
    // Setup game over text
    gameOverText.setFont(font);                      // Set the font
    gameOverText.setFillColor(sf::Color::Red);       // Set the text color
    gameOverText.setString("Game Over");             // Set the string
    gameOverText.setCharacterSize(50);               // Set text size

    // Center the text on the screen
    sf::FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setPosition(
        (SCREEN_WIDTH - textRect.width) / 2,          // Center horizontally
        (SCREEN_HEIGHT - textRect.height) / 2         // Center vertically
    );

    window.draw(gameOverText);
}

void Game::drawRestartButton(sf::RenderWindow &window) {
    window.draw(restartButton);
    window.draw(restartText);
}



