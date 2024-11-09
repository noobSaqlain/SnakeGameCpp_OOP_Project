//
// Created by LENOVO on 09/11/2024.
//


#include "UIManager.h"
#include <iostream>

#include "Game.h"

UIManager::UIManager() {
    // Load font
    if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts/Neucha-Regular.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
    initButtons();
}

void UIManager::initButtons() {
    // Configure start button and text
    startButton.setSize(sf::Vector2f(200, 50));
    startButton.setFillColor(sf::Color::Green);
    startButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 60);
    startText.setFont(font);
    startText.setString("Game Start");
    startText.setCharacterSize(24);
    startText.setFillColor(sf::Color::Black);
    startText.setPosition(startButton.getPosition().x + 45, startButton.getPosition().y + 10);

    // Configure other buttons (similar to above)
    // ...

    // Configure the back-to-menu button
    backToMenuButton.setSize(sf::Vector2f(200, 50));
    backToMenuButton.setFillColor(sf::Color::Blue);
    backToMenuButton.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 130);
    backToMenuText.setFont(font);
    backToMenuText.setString("Back to Menu");
    backToMenuText.setCharacterSize(24);
    backToMenuText.setFillColor(sf::Color::White);
    backToMenuText.setPosition(backToMenuButton.getPosition().x + 25, backToMenuButton.getPosition().y + 10);
}

void UIManager::drawMainMenu(sf::RenderWindow &window) {
    window.draw(startButton);
    window.draw(startText);
    window.draw(scoreButton);
    window.draw(scoreText);
}

void UIManager::drawGameOverMenu(sf::RenderWindow &window) {
    window.draw(restartButton);
    window.draw(restartText);
    window.draw(backToMenuButton);
    window.draw(backToMenuText);
}

bool UIManager::isStartClicked(const sf::Vector2i &mousePos) {
    return startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

bool UIManager::isRestartClicked(const sf::Vector2i &mousePos) {
    return restartButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

bool UIManager::isBackToMenuClicked(const sf::Vector2i &mousePos) {
    return backToMenuButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}
