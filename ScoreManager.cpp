//
// Created by LENOVO on 08/11/2024.
//

#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

ScoreManager::ScoreManager() {
    storage = new StorageManager();
}
ScoreManager::~ScoreManager() {
    delete storage;
}

void ScoreManager::displayScore(sf::RenderWindow &window) {
    std::vector<ScoreEntry> scores = storage->loadScore();

    sf::Font font;
    if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts/Neucha-Regular.ttf")) {
        std::cerr << "Error: Could not load font." << std::endl;
        return;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);

    float startY = 100.0f;
    float offsetY = 40.0f;

    if (scores.empty()) {
        scoreText.setString("No scores available.");
        scoreText.setPosition(100, startY);
        window.draw(scoreText);
        return;
    }

    for (size_t i = 0; i < scores.size(); ++i) {
        const ScoreEntry &entry = scores[i];
        scoreText.setString(std::to_string(i + 1) + " - " + entry.score + " " + entry.date + " " + entry.time);
        scoreText.setPosition(100, startY + i * offsetY);
        window.draw(scoreText);
    }
}

void ScoreManager::resetScore() {
    currentScore = 0;
}
int ScoreManager::getHighestScore() const{
    return highestScore;
}

void ScoreManager::updateScore() {
    std::cout << currentScore;
    currentScore++;
}

int ScoreManager::getCurrScore() const {
    return currentScore;
}




