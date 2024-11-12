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



////displays score data with the date and time it was played in
void ScoreManager::displayScore(sf::RenderWindow &window) {
    std::vector<ScoreEntry> scores = storage->loadScore(); ////// return a vector of data stored in file

    // Ensure the font loads correctly
    sf::Font font;
    if (!font.loadFromFile("C:/Users/LENOVO/Desktop/snakeGameOOp/fonts/Neucha-Regular.ttf")) { //// relative path was not working so I put absolute, you change accordingly
        std::cerr << "Error: Could not load font." << std::endl;
        return;
    }

    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);

    float startY = 100.0f;
    float offsetY = 40.0f;

    ///// if not score is saved -> no game has been played yet
    if (scores.empty()) {
        scoreText.setString("No scores available.");
        scoreText.setPosition(100, startY);
        window.draw(scoreText);
        return;
    }

    // Loop through the vector in reverse order, showing most recent first
    for (size_t i = 0; i < scores.size(); ++i) {
        const ScoreEntry &entry = scores[scores.size() - 1 - i];  // Get elements in reverse order
        scoreText.setString(std::to_string(i + 1) + "-   " + entry.score + "       " + entry.date + "    " + entry.time); /// format
        scoreText.setPosition(100, startY + i * offsetY);  // Normal positioning for i
        window.draw(scoreText);
    }
}


////reset when gameover or new game start
void ScoreManager::resetScore() {
    currentScore = 0;
}


int ScoreManager::getHighestScore() const{
    return highestScore;
}

///updates every time snake and food collision in detected
void ScoreManager::updateScore() {
    std::cout << currentScore;
    currentScore++;
}

int ScoreManager::getCurrScore() const {
    return currentScore;
}

/// saves the incoming formatted string to file
void ScoreManager::saveDataToFile(std::string data) {
    storage->saveScore(data);

}


