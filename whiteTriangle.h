#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include "food.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class WhiteTriangle: public Food
{
	CircleShape triangle;
	float radius;
	float x;
	float y;
public:
	WhiteTriangle()
	{
		radius = 0.0;
		x = 0.0;
		y = 0.0;
	}
	CircleShape& getTriangle()
	{
		return triangle;
	}
	WhiteTriangle(float x, float y, float radius)
	{
		this->radius = radius;
		this->x = x;
		this->y = y;
	}
	void makeFood(RenderWindow& window) override
	{
		triangle.setRadius(20);
		triangle.setPointCount(3);
		triangle.setPosition(x, y);
		triangle.setFillColor(Color::White);
		window.draw(triangle);
		
	}
};