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
    bool checkIfEaten(const Snake& snake) const; /// check collision of snake head and food
    void setFoodPosition(int x, int y);
    int getX() const {return x;}
    int getY() const {return y;}
    int getTileSize() const { return tilesize; }
};

#endif

