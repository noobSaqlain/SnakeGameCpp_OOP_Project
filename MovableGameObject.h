//
// Created by LENOVO on 04/11/2024.
//

#ifndef MOVABLEGAMEOBJECT_H
#define MOVABLEGAMEOBJECT_H

#include <SFML/Graphics.hpp>

class MovableGameObject ///// parent of food and snake
{
protected:
    int x, y; // coordinates

public:
    MovableGameObject(int startX, int startY) : x(startX), y(startY) {}
    virtual void move() = 0; // pure virtual
    sf::Vector2i getPosition() const { return sf::Vector2i(x, y); }
};

#endif
