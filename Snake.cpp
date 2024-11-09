#include "Snake.h"

#include "Game.h"

Snake::Snake(int startX, int startY, int initialSpeed, int tileSize)
    : MovableGameObject(startX, startY), direction(Direction::Right), speed(initialSpeed), tileSize(tileSize) {
    segments.push_back(SnakeSegment(startX, startY)); // Head segment
    setInitialBodySize();
}


// Initialize snake body by adding segments behind the head
void Snake::setInitialBodySize() {
    for (int i = 1; i <= initialBodySize; i++) {
        int offsetX = 0, offsetY = 0;
        switch (direction) {
            case Direction::Right: offsetX = -i * tileSize; break;
            case Direction::Left:  offsetX = i * tileSize; break;
            case Direction::Up:    offsetY = i * tileSize; break;
            case Direction::Down:  offsetY = -i * tileSize; break;
        }
        segments.push_back(SnakeSegment(segments[0].x + offsetX, segments[0].y + offsetY));
    }
}

void Snake::move() {
    for (size_t i = segments.size() - 1; i > 0; --i) {
        segments[i] = segments[i - 1];
    }

    // Move head in the current direction
    switch (direction) {
        case Direction::Up:    segments[0].y -= tileSize; break;
        case Direction::Down:  segments[0].y += tileSize; break;
        case Direction::Left:  segments[0].x -= tileSize; break;
        case Direction::Right: segments[0].x += tileSize; break;
    }
}

void Snake::grow() {
    // Add a new segment at the tail
    segments.push_back(segments.back());
}

// Change direction if it's not the opposite of the current one
void Snake::changeDirection(Direction newDirection) {
    if ((direction == Direction::Up && newDirection != Direction::Down) ||
        (direction == Direction::Down && newDirection != Direction::Up) ||
        (direction == Direction::Left && newDirection != Direction::Right) ||
        (direction == Direction::Right && newDirection != Direction::Left)) {
        direction = newDirection;
        }
}

bool Snake::checkSelfCollision() const {
    for (size_t i = 1; i < segments.size(); i++) {
        if (segments[0].x == segments[i].x && segments[0].y == segments[i].y) {
            return true;
        }
    }
    return false;
}


bool Snake::checkCollision() const {
    if (segments[0].x < 0 || segments[0].x >= SCREEN_WIDTH ||
        segments[0].y < 0 || segments[0].y >= SCREEN_HEIGHT) { // collision with boundaries
        return true;
        }
    return false;
}



    void Snake::resetSnake() {
        segments.clear();

        // Reinitialize the head segment at a default starting position
        int startX = SCREEN_WIDTH / 2;  // Set a default or initial X position
        int startY = SCREEN_HEIGHT / 2; // Set a default or initial Y position
        segments.push_back(SnakeSegment(startX, startY));  // Add the head segment

        setInitialBodySize();   // Rebuild the initial body segments
        direction = Direction::Right; // Reset the direction
    }




