#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace  sf;
class Food
{
public:
	
	virtual void makeFood(RenderWindow& window) = 0;
	//virtual bool getCheck() = 0;
	//virtual void setCheck(bool) = 0;
};