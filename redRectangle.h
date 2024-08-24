#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include "food.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class RedRectangle : public Food
{
	float x;
	float y;
	float length;
	float width;
	bool check;
	RectangleShape rect;
public:
	RedRectangle()
	{
		x = 0;
		y = 0;
		length = 0;
		check = false;
		width = 0;
	}
	RedRectangle(float x, float y, float length, float width)
	{
		this->x = x;
		this->y = y;
		this->length = length;
		this->width = width;
		check = true;
	}
	/*void setCheck(bool check)
	{
		this->check = check;
	}
	bool getCheck()
	{
		return check;
	}*/
	RectangleShape& getShape()
	{
		return rect;
	}
	void makeFood(RenderWindow& window) override
	{
		rect.setSize(Vector2f(width, length));
		rect.setPosition(x, y);
		window.draw(rect);
		rect.setFillColor(Color::Red); // Adjust the color as needed


	}
};