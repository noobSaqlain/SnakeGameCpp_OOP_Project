//
// Created by LENOVO on 04/11/2024.
//

#ifndef FOOD_H
#define FOOD_H

#include "MovableGameObject.h"

class Food : public MovableGameObject {
public:
    Food(int startX, int startY) : MovableGameObject(startX, startY) {}
    void generateNewPosition(int boardWidth, int boardHeight);
    bool checkIfEaten(const Snake& snake) const;
};

#endif

