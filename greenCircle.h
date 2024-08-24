#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include "food.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GreenCircle: public Food
{
	static int life;
	float x;
	float y;
	float radius;
	bool check;
	CircleShape circle;
public:
	CircleShape& getCircle()
	{
		return circle;
	}
	GreenCircle()
	{
		x = 0;
		y = 0;
		radius = 0;
		check = false;
		//life = 0;
	}
	void setLife(static int life)
	{
		life = life;
		cout << "Life:  " << life << endl;
	}
	static int getLife()
	{
		return life;
	}
	GreenCircle(float x, float y, float radius)
	{	
		this->radius = radius;
		this->x = x;
		this->y = y;
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
	void makeFood(RenderWindow& window) override
	{
		circle.setRadius(radius);
		circle.setPosition(x, y);
		circle.setFillColor(Color::Green);
		window.draw(circle);
		
	}
};
int GreenCircle::life = 0;