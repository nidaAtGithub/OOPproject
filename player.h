#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Player
{
    RectangleShape shape;
    float direction; // Direction of movement for the box
    int x;
    int y;
    int length;
    int width;
    float leftBoundary;
    float rightBoundary;
    float upBoundary;
    float downBoundary;
    //float leftBound1;
    float speedIncrement;
public:    
    // Default constructor
    Player():direction(10)// Set a default direction (you can adjust as needed)
    {
        x = 0;
        y = 0;
        length = 0;
        speedIncrement = 1.0f;
        width = 0;

        // Set default properties or leave them uninitialized as needed
    }
    void setSpeedIncrement(float speedIncrement)
    {
        this->speedIncrement = speedIncrement;
    }
    RectangleShape& getShape()
    {
        return shape;
    }
    //Setter getter for left 1
   /* void setBound1(float set)
    {
        leftBound1 = set;
    }
    float getBound1()
    {
        return leftBound1;
    }*/
    FloatRect getBounds() 
    {
        return shape.getGlobalBounds();
    }
    //Getter and setter for direction
    //Direction
    void setDirection(float d)
    {
        direction = d;
    }
    float getDirection()
    {
        return direction;
    }
    //Setter gettr for leftBoundary
    void setLeftBoundary(float set)
    {
        leftBoundary = set;
    }
    float getLeftBoundary()
    {
        return leftBoundary;
    }
    //Setter getter for Right Boundary
    void setRightBoundary(float set)
    {
        rightBoundary = set;
    }
    float getRightBoundary()
    {
        return rightBoundary;
    }

    //setter getter for top boundary
    void setUpBoundary(float up)
    {
        upBoundary = up;
    }
    float getUpBoundary()
    {
        return upBoundary;
    }
    //Setter getter for doen boundary
    void setDownBoundary(int down)
    {
        downBoundary = down;
    }
    float getDownBoundary()
    {
        return  downBoundary;
    }
    //Setter
    void setDirection(int direction)
    {
        this->direction = direction;
    }
    void makeCar(int x, int y, int length, int width, int direction)
    {
        shape.setSize(Vector2f(width, length));
        shape.setPosition(x, y); //This will set position on the plane 
        shape.setFillColor(Color::Yellow); // Adjust the color as needed
    }
    //Move functions
    void move(float speed, float offsetY)
    {
           shape.move(speed * direction * speedIncrement, offsetY);
    }
    void moveCarFunc(float offsetX, float offsetY)
    {
        // Move all components of the car by the specified offset
        shape.move(offsetX * direction * speedIncrement, offsetY);
    }
  
};
