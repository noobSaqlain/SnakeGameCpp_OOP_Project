//
// Created by LENOVO on 04/11/2024.
//

#ifndef SNAKE_H
#define SNAKE_H


#include <vector>
#include "SnakeSegment.h"
#include "MovableGameObject.h"

enum class Direction { Up, Down, Left, Right };

class Snake : public MovableGameObject {
private:
    std::vector<SnakeSegment> segments;
    Direction direction;
    int speed;

public:
    Snake(int startX, int startY, int initialSpeed);
    void move() override;
    void grow();
    void changeDirection(Direction newDirection);
    bool checkSelfCollision() const;
    void resetSnake();
    const std::vector<SnakeSegment>& getSegments() const { return segments; }
};

#endif



