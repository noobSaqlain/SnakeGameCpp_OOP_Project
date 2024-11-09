//
// Created by LENOVO on 09/11/2024.
//

#include "UIManager.h"

#include <iostream>
#include "Game.h"


UIManager::UIManager(Game* gameInstance) : game(gameInstance)  {
    initButtons();
}


void UIManager::initButtons()  {
    try {
        if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts/Neucha-Regular.ttf")) {
            std::cerr << "Error: Could not load font from the specified path." << std::endl;
            return;
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception caught during font loading: " << e.what() << std::endl;
    }


    // Start Button and Text
    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color(0, 128, 255)); // Green shade
    startButton.setPosition(SCREEN_WIDTH / 2 - startButton.getSize().x / 2, SCREEN_HEIGHT / 2 - 60);

    startText.setFont(font);
    startText.setString("Game Start");
    startText.setCharacterSize(24);
    startText.setFillColor(sf::Color::White);

    sf::FloatRect startTextRect = startText.getLocalBounds();
    startText.setOrigin(startTextRect.width / 2.0f, startTextRect.height / 2.0f);
    startText.setPosition(startButton.getPosition().x + startButton.getSize().x / 2,
                          startButton.getPosition().y + startButton.getSize().y / 2);

    // Score Button and Text
    scoreButton.setSize(sf::Vector2f(200, 50));
    scoreButton.setFillColor(sf::Color(0, 204, 0)); // Purple color
    scoreButton.setPosition(SCREEN_WIDTH / 2 - scoreButton.getSize().x / 2, SCREEN_HEIGHT / 2 + 10);

    scoreText.setFont(font);
    scoreText.setString("Score History");
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);

    sf::FloatRect scoreTextRect = scoreText.getLocalBounds();
    scoreText.setOrigin(scoreTextRect.width / 2.0f, scoreTextRect.height / 2.0f);
    scoreText.setPosition(scoreButton.getPosition().x + scoreButton.getSize().x / 2,
                          scoreButton.getPosition().y + scoreButton.getSize().y / 2);

    //restart button
    restartButton.setSize(sf::Vector2f(200, 50));
    restartButton.setFillColor(sf::Color::Red);
    restartButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 70);

    restartText.setFont(font);
    restartText.setString("Restart");
    restartText.setCharacterSize(24);
    restartText.setFillColor(sf::Color::White);
    sf::FloatRect restartTextRect = restartText.getLocalBounds();
    restartText.setOrigin(restartTextRect.width / 2.0f, restartTextRect.height / 2.0f);
    restartText.setPosition(
        restartButton.getPosition().x + restartButton.getSize().x / 2,
        restartButton.getPosition().y + restartButton.getSize().y / 2
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
    backToMenuText.setOrigin(backToMenuTextRect.width / 2.0f, backToMenuTextRect.height / 2.0f);
    backToMenuText.setPosition(
        backToMenuButton.getPosition().x + backToMenuButton.getSize().x / 2,
        backToMenuButton.getPosition().y + backToMenuButton.getSize().y / 2
    );
}

void UIManager::drawMainMenu(sf::RenderWindow &window) { ////// two buttons. one for start game and other for score history
    window.draw(startButton);
    window.draw(startText);
    window.draw(scoreButton);
    window.draw(scoreText);
}

void UIManager::drawGame(sf::RenderWindow &window,Snake& snake, Food& food, Board& board) { /// when isRunning true, draw food, snake, and score;
    board.drawFood(food, window);
    board.drawSnake(snake, window);
}

void UIManager::drawRestart(sf::RenderWindow &window) {

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


void UIManager::drawRestartButton(sf::RenderWindow &window) {
    window.draw(restartButton);
    window.draw(restartText);
}

void UIManager::handleInputs(sf::Vector2i& mousePos, Snake& snake, Food& food) {
    // Start game if the game is paused and the start button is clicked
    if (game->getIsPausedStatus() && startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        game->setStates(false, true, false);  // Start the game, set running state to true and pause to false
    }

    // Restart game if the game is over and the restart button is clicked
    else if (game->getIsGameOverStatus() && restartButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        game->setStates(false, true, false);  // Restart the game, set running state to true
        snake.resetSnake();                 // Reset snake to its initial state
        food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT);  // Reset food position
        // Optionally reset game-related timers if any (e.g., countdown)
    }

    // Go back to main menu if the game is over and the "Back to Menu" button is clicked
    else if (game->getIsGameOverStatus() && backToMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        game->setStates(true, false, false);  // Go back to the main menu, set paused state to true and game over to false
        snake.resetSnake();                 // Reset snake position and size
        food.generateNewPosition(SCREEN_WIDTH, SCREEN_HEIGHT); // Reposition food
        // Optionally reset score and game state if needed
    }
}

