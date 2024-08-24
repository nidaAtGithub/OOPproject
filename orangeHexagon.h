#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include "food.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class OrangeHexagon: public Food
{
    ConvexShape hexagon;
    float x;
    float y;
    bool check;
    float sizeHexa;
public:
    OrangeHexagon()
    {
        x = 0.0;
        y = 0.0;
        check = false;
        sizeHexa = 0.0;
    }
    ConvexShape& getHexa()
    {
        return hexagon;
    }
    OrangeHexagon(int x, float y, float sizeHexa)
    {
        this->x = x;
        this->y = y;
        this->sizeHexa = sizeHexa;
        check = true;
    }
   /* void setCheck(bool check)
    {
        this->check = check;
    }
    bool getCheck()
    {
        return check;
    }*/
    // Draw the hexagon on the window
    void makeFood(RenderWindow& window)
    {
       //Thjis is because hexagon has  sides so froom that
        hexagon.setPointCount(6);
        // Calculate the coordinates of the hexagon's vertices
        for (int i = 0; i < 6; i++)
        {
            //To calculate the angel between the verytices 
            float angle = i * 2 * 3.14 / 6; 
            //To calculate the value or index of x and y
            float valueX = sizeHexa * cos(angle);
            float valueY = sizeHexa * sin(angle);
            hexagon.setPoint(i, Vector2f(x + valueX, y + valueY));
        }
        hexagon.setFillColor(Color::Yellow);
        window.draw(hexagon);
    }
};