#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <SFML/Graphics.hpp>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "level.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
using namespace std;
using namespace sf;

class Game
{

    Level* ptr1;
    Level* ptr2;
    Level* ptr3;
    Level* ptr4;
    static int levelCount;
public:

    Game()
    {
        //Polymorphism
        ptr1 = new Level1;
        ptr2 = new Level2;
        ptr3 = new Level3;
        ptr4 = new Level4;
    }
    
    void start_game()
    {
        //bool get1 = ptr4->levels();
        /* bool get1 = ptr1->levels();
         if (get1 == true)
         {
             bool get2 = ptr2->levels();
             if (get2 == true)
             {
                 bool get3 = ptr3->levels();
                 if (get3 == true)
                 {
                     bool get4 = ptr4->levels();
                 }
             }
         }*/
        //foolwing is the code which will cal ech level one by one
         bool get1 = ptr1->levels();
         if (get1 == true) 
         {
             transitionScreen(2);
             bool get2 = ptr2->levels();
             if (get2 == true)
             {
                 transitionScreen(3);

                 bool get3 = ptr3->levels();
                 if (get3 == true)
                 {
                     transitionScreen(4);
                     bool get4 = ptr4->levels();
                     if (get4 == true) 
                     {
                         bool finish = lastScreen();
                         if (finish == true)
                         {
                             return;
                         }
                         // Continue with the next levels or end the game
                     }
                 }
             }
         }
    }
    //This si the function i implement for the transition of level to notify that which level is next
    bool transitionScreen(int levelNum)
    {
        srand(time(0));

        Clock clock;
        float timer = 0;
        RenderWindow window(VideoMode(800, 800), "Level Transition");

        Font font;
        font.loadFromFile("arial.ttf");

        Text level(" Level   " + to_string(levelNum), font, 100);
        level.setFillColor(Color::Green);
        level.setPosition(200, 300);

        //Adjust the window timer for transition
        while (window.isOpen() && timer < 2.0)
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            window.draw(level);
            window.display();
        }

        return true;
    }
    bool lastScreen()
    {
        srand(time(0));

        Clock clock;
        float timer = 0;
        RenderWindow window(VideoMode(800, 800), "Game won");

        Font font;
        font.loadFromFile("arial.ttf");

        Text finish("  You Won!   ",font, 100);
        finish.setFillColor(Color::Yellow);
        finish.setPosition(160, 310);

        //Adjust the window timer for transition
        while (window.isOpen() && timer < 2.0)
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
            }

            window.clear();
            window.draw(finish);
            window.display();
        }

        return true;
    }
};