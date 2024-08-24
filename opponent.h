#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include <SFML/Graphics.hpp>
#include "roadWays.h"
using namespace std;
using namespace sf;

class Opponent
{
    RectangleShape shape;
    float direction; // Direction of movement for the box
    float x;
    float y;
    float length;
    float width;
    float leftBoundary;
    float rightBoundary;
    float upBoundary;
    float downBoundary;   
public:
    Opponent() : direction(1.0f)// Set a default direction (you can adjust as needed)
    {
        x = 0;
        y = 0;
        length = 0;
        width = 0;
        // Set default properties or leave them uninitialized as needed
    }
    RectangleShape& getShape()
    {
        return shape;
    }
    FloatRect getBounds()
    {
        return shape.getGlobalBounds();
    }
    //Getter and setter for direction
    //Direction
    float getDirection()
    {
        return direction;
    }
    void setDirection(float d)
    {
        direction = d;
    }
    //Setter gettr for leftBoundary
    void setLeftBoundaryOpp(float set)
    {
        leftBoundary = set;
    }
    float getLeftBoundaryOpp()
    {
        return leftBoundary;
    }
    //Setter getter for Right Boundary
    void setRightBoundaryOpp(float set)
    {
        rightBoundary = set;
    }
    float getRightBoundaryOpp()
    {
        return rightBoundary;
    }

    //setter getter for top boundary
    void setUpBoundaryOpp(float up)
    {
        upBoundary = up;
    }
    float getUpBoundaryOpp()
    {
        return upBoundary;
    }
    //Setter getter for doen boundary
    void setDownBoundaryOpp(float down)
    {
        downBoundary = down;
    }
    float getDownBoundaryOpp()
    {
        return  downBoundary;
    }
    
    void makeOppo(float x, float y, float length, float width)
    {
        // moveCar = true;
        shape.setSize(Vector2f(width, length));
        shape.setPosition(x, y); //This will set position on the plane 
        shape.setFillColor(Color::Blue); // Adjust the color as needed
    }
    void move(float speed, float offsetY)
    {
        shape.move(speed * direction, offsetY*direction);
    }
    void moveCarFunc(float offsetX, float offsetY)
    {
        // Move all components of the car by the specified offset
        shape.move(offsetX * direction, offsetY);
    }
};