//
// Created by LENOVO on 04/11/2024.
//

#ifndef FOOD_H
#define FOOD_H

#include "MovableGameObject.h"
#include "Snake.h"

class Food : public MovableGameObject {
    const int tilesize;

public:
    Food(int startX, int startY,int tilesize);
    void generateNewPosition(int boardWidth, int boardHeight);
    bool checkIfEaten(const Snake& snake) const;
    void drawFood( sf::RenderWindow& window);
    void setFoodPosition(int x, int y);
};

#endif

