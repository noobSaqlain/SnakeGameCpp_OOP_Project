//
// Created by LENOVO on 09/11/2024.
//

#include "UIManager.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Game.h"


UIManager::UIManager(Game* gameInstance) : game(gameInstance)  {
    scoreManager = new ScoreManager();
    initButtons();
}
UIManager::~UIManager() {
    delete game;
    delete scoreManager;
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

    /////back button on score page
    scorePageBackButton.setSize(sf::Vector2f(100,40));
    scorePageBackButton.setFillColor(sf::Color::Red);
    scorePageBackButton.setPosition(50,50);

    scorePageBacktext.setFont(font);
    scorePageBacktext.setString("Back");
    scorePageBacktext.setCharacterSize(24);
    scorePageBacktext.setFillColor(sf::Color::Black);
    sf::FloatRect scorePageBackTextRect = scorePageBackButton.getLocalBounds();
    scorePageBacktext.setOrigin(scorePageBackTextRect.width / 2.0f, scorePageBackTextRect.height / 2.0f);
    scorePageBacktext.setPosition(
        scorePageBackButton.getPosition().x + scorePageBackButton.getSize().x / 2,
        scorePageBackButton.getPosition().y + scorePageBackButton.getSize().y / 2
    );

    ////score Text
    score.setFont(font);
    score.setString(std::to_string(scoreManager->getCurrScore()));
    score.setCharacterSize(50);
    score.setFillColor(sf::Color::Red);
    score.setPosition(10, 10);  // Example: Top-left corner


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

    // Display "Score:" label (smaller font)
    sf::Text scoreLabel;
    scoreLabel.setFont(font);  // Ensure the font is the same as the score text
    scoreLabel.setString("Score:");  // Label text
    scoreLabel.setCharacterSize(20);  // Smaller font size for the label
    scoreLabel.setFillColor(sf::Color::White);  // Color for the label
    scoreLabel.setPosition(SCREEN_WIDTH / 2 - 35, SCREEN_HEIGHT / 2 - 180);  // Position above the actual score

    window.draw(scoreLabel);  // Draw the "Score:" label

    // Display current score
    score.setFont(font);  // Set the font again (if necessary)
    score.setString(std::to_string(scoreManager->getCurrScore()));  // Actual score
    score.setCharacterSize(100);  // Larger font size for the score
    score.setFillColor(sf::Color::White);  // Color for the score text
    score.setPosition(SCREEN_WIDTH / 2 - 40 , SCREEN_HEIGHT / 2 - 140);  // Position below "Score:" label

    window.draw(score);  // Draw the score text
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
    //score page when game is paused
    else if(game->getIsPausedStatus() && scoreButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        isScorePageOpened = true;
    }else if(isScorePageOpened && scorePageBackButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
        isScorePageOpened = false;
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

void UIManager::drawScorePage(sf::RenderWindow &window) {
    scoreManager->displayScore(window);
    drawScorePageBackButton(window);
}

bool UIManager::getIsScorePageOpened() const{
    return isScorePageOpened;
}
void UIManager::setIsScorePageOpened(const bool state) {
    this->isScorePageOpened = state;
}

void UIManager::drawScorePageBackButton(sf::RenderWindow& window) {
    window.draw(scorePageBackButton);
    window.draw(scorePageBacktext);
}

void UIManager::updateScore() {
    scoreManager->updateScore();
}

void UIManager::drawScore(sf::RenderWindow& window) {
    score.setString(std::to_string(scoreManager->getCurrScore())); /// everytime is should get updated
    window.draw(score);
}

