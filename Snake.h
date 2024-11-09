#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SnakeSegment.h"
#include "MovableGameObject.h"
#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right }; // enum class is to store consts

class Snake : public MovableGameObject {
private:
    std::vector<SnakeSegment> segments;
    Direction direction;
    int speed;
    int tileSize;
    const int initialBodySize = 5;
    void setInitialBodySize() ;
public:
    Snake(int startX, int startY, int initialSpeed, int tileSize);

/////////////////////////////////
    void move();
    void grow();
    void changeDirection(Direction newDirection);
    bool checkSelfCollision() const;
    bool checkCollision() const;
    void resetSnake();

    /////////////////////////////
    ///
    const std::vector<SnakeSegment>& getSegments() const { return segments; }
    std::vector<SnakeSegment> getAllSegments() const { return segments; }
    int getTileSize() const { return tileSize; }


};

#endif
