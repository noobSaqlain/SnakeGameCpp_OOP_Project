//
// Created by LENOVO on 04/11/2024.
//

#include "Game.h"
using namespace sf;

    Game::Game() {

    }

//     : snake(10, 10, 1), food(5, 5), isRunning(true), isPaused(false) {}

// void Game::startGame() {
//     snake.resetSnake();
//     scoreManager.resetScore();
//     isRunning = true;
// }

// void Game::pauseGame() {
//     isPaused = !isPaused;
// }

// void Game::updateGame() {
//     if (!isPaused && isRunning) {
//         snake.move();
//         if (food.checkIfEaten(snake)) {
//             snake.grow();
//             scoreManager.updateScore(10);
//             food.generateNewPosition(20, 20);  // Example board size
//         }
//         checkCollisions();
//     }
// }

// void Game::endGame() {
//     isRunning = false;
// }
//
// void Game::checkCollisions() {
//     if (snake.checkSelfCollision()) {
//         endGame();
//     }
// }


    void Game::draw(RenderWindow &window) {
    // Create a RectangleShape for the grid tile
    RectangleShape tile(Vector2f(tileSize, tileSize));
    tile.setFillColor(Color::Transparent); // Set tile color to transparent
    tile.setOutlineColor(Color::Green);     // Set outline color for grid lines
    tile.setOutlineThickness(0.2);             // Set thickness of the grid lines

    // Loop through the window dimensions to draw the grid
    for (int i = 0; i < window.getSize().x; i += tileSize) {
        for (int j = 0; j < window.getSize().y; j += tileSize) {
            // Set the position of the tile
            tile.setPosition(static_cast<float>(i), static_cast<float>(j));
            // Draw the tile
            window.draw(tile);
        }
    }
}


