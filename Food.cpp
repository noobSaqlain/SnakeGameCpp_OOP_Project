//
// Created by LENOVO on 04/11/2024.
//

#include "Food.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

Food::Food(int startX, int startY, int tilesize)
    : tilesize(tilesize), MovableGameObject(startX, startY) {}


void Food::generateNewPosition(int boardWidth, int boardHeight) {
    x = (rand() % (boardWidth / tilesize)) * tilesize;
    y = (rand() % (boardHeight / tilesize)) * tilesize;
}

bool Food::checkIfEaten(const Snake& snake) const {
    return (x == snake.getSegments()[0].x && y == snake.getSegments()[0].y);
}
void Food::setFoodPosition(int x, int y) {
    this->x = x;
    this->y = y;
}


void Food::drawFood(sf::RenderWindow &window) {

}



