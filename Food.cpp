//
// Created by LENOVO on 04/11/2024.
//

#include "Food.h"


#include "Snake.h"
#include <cstdlib>

void Food::generateNewPosition(int boardWidth, int boardHeight) {
    x = rand() % boardWidth;
    y = rand() % boardHeight;
}

bool Food::checkIfEaten(const Snake& snake) const {
    return (x == snake.getSegments()[0].x && y == snake.getSegments()[0].y);
}
