#include "Snake.h"

#include "Game.h"

Snake::Snake(int startX, int startY, int initialSpeed, int tileSize)
    : MovableGameObject(startX, startY), direction(Direction::Right), speed(initialSpeed), tileSize(tileSize) {
    segments.push_back(SnakeSegment(startX, startY));
}

void Snake::move() {
    // Move each segment to the position of the previous one
    for (int i = segments.size() - 1; i > 0; --i) {
        segments[i] = segments[i - 1];
    }

    // Update the head's position based on the current direction
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

void Snake::changeDirection(Direction newDirection) {
    // Prevent reversing direction
    if ((direction == Direction::Up && newDirection != Direction::Down) ||
        (direction == Direction::Down && newDirection != Direction::Up) ||
        (direction == Direction::Left && newDirection != Direction::Right) ||
        (direction == Direction::Right && newDirection != Direction::Left)) {
        direction = newDirection;
    }
}

bool Snake::checkSelfCollision() const {

    for (size_t i = 1; i < segments.size(); ++i) {
        if (segments[i].x == segments[0].x && segments[i].y == segments[0].y) {
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
    segments.push_back(SnakeSegment(x, y));
    direction = Direction::Right;
}

void Snake::draw(sf::RenderWindow& window) const {
    for (const auto& segment : segments) {
        sf::RectangleShape segmentShape(sf::Vector2f(tileSize, tileSize));
        segmentShape.setFillColor(sf::Color::Green);
        segmentShape.setPosition(static_cast<float>(segment.x), static_cast<float>(segment.y));
        window.draw(segmentShape);
    }
}
