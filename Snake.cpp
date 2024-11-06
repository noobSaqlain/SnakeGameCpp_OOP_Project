//
// Created by LENOVO on 04/11/2024.
//

#include "Snake.h"




Snake::Snake(int startX, int startY, int initialSpeed)
    : MovableGameObject(startX, startY), direction(Direction::Right), speed(initialSpeed) {
    segments.push_back(SnakeSegment(startX, startY));
}

void Snake::move() {
    // Move the snake segments
    for (int i = segments.size() - 1; i > 0; --i) {
        segments[i] = segments[i - 1];
    }

    switch (direction) {
        case Direction::Up:    --segments[0].y; break;
        case Direction::Down:  ++segments[0].y; break;
        case Direction::Left:  --segments[0].x; break;
        case Direction::Right: ++segments[0].x; break;
    }
}

void Snake::grow() {
    segments.push_back(segments.back());
}

void Snake::changeDirection(Direction newDirection) {
    // Add logic to prevent reversing
    direction = newDirection;
}

bool Snake::checkSelfCollision() const {
    for (size_t i = 1; i < segments.size(); ++i) {
        if (segments[i].x == segments[0].x && segments[i].y == segments[0].y) {
            return true;
        }
    }
    return false;
}

void Snake::resetSnake() {
    segments.clear();
    segments.push_back(SnakeSegment(x, y));
    direction = Direction::Right;
}
