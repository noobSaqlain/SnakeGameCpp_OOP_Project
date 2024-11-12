#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SnakeSegment.h"
#include "MovableGameObject.h"
#include <SFML/Graphics.hpp>

enum class Direction { Up, Down, Left, Right }; // enum class is to store consts

class Snake : public MovableGameObject {
private:
    std::vector<SnakeSegment> segments; //// snake body segments
    Direction direction;
    int speed;
    int tileSize; //////// our window is made of invisible grids. this variable stores the tileSize
    const int initialBodySize = 5; /////// initially how long would the body be
    void setInitialBodySize() ;
public:
    Snake(int startX, int startY, int initialSpeed, int tileSize);
    void move();
    void grow();
    void changeDirection(Direction newDirection);
    bool checkSelfCollision() const;
    bool checkCollision() const;
    void resetSnake(); //// when gameover, snake has to be reset
    const std::vector<SnakeSegment>& getSegments() const { return segments; }
    std::vector<SnakeSegment> getAllSegments() const { return segments; }
    int getTileSize() const { return tileSize; }


};

#endif
