#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class RoadWays
{
	RectangleShape road;
	int x;
	int y;
	int width;
	int length;
public:
	
	RectangleShape& getRoad()
	{
		return road;
	}
	RoadWays()
	{
		x = 0;
		y = 0;
		width = 0;
		length = 0;
	}
	FloatRect getBounds() 
	{
		return road.getGlobalBounds();
	}
	/*RoadWays(int x, int y, int width, int length)
	{
		road.setSize(Vector2f(width, length));
		road.setPosition(x, y);
		road.setFillColor(Color::Red);
	}*/
	void makeRoads(int x, int y, int width, int length)
	{
		road.setSize(Vector2f(width, length));
		road.setPosition(x, y);
		road.setFillColor(Color::Cyan);
	}
};