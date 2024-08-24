#pragma once
////////////////Nida Azam//////////////////////
///////////////Section A//////////////////////
///////////////Roll no 21I-0433///////////////
#include <iostream>
#include "level.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "roadWays.h"
#include "food.h"
#include "redRectangle.h"
#include "score.h"
#include "greenCircle.h"
#include "orangeHexagon.h"
#include "opponent.h"
#include "whiteTriangle.h"

using namespace std;
using namespace sf;

class Level4 : public Level
{
    static const int totalRedFood = 32;
    static const int numSmallBoxes = 5; // Set the number of small boxes
    static const int totalRoads = 30;
    static const int totalCircle = 2;
    static const int totalOpponent1 = 3;
    static const int totalOpponent2 = 3;
    static int countClose;
    static int count;
    Player smallBoxes[numSmallBoxes]; // Declare the array here
    int direction = 1; // Variable to store the direction of movement
    RoadWays roads[totalRoads];
    Food* ptr1[totalRedFood];
    Food* ptr2[totalCircle];
    Food* ptr3;
    Food* ptr4;
    GreenCircle lifeCount;
    HighScore score;

    bool powerUpActive = false;
    Clock powerUpTimer;
    float powerUpDuration;

    bool pause;
    bool reset;
    bool newGame;
    bool newGamePause;
    Opponent oppoCar[totalOpponent1];
    Opponent oppoCar2[totalOpponent2];
    Clock opponent;

public:
    Level4()
    {
        powerUpTimer.restart(); //This insures timer begin counting from 0
        powerUpActive = false;  //Initially the poweractive is false but once the condition met it will be tue 
        powerUpDuration = 10.0;   //Power duration is 10 because we want 10 sec for the pwer to increase
        pause = false;
        reset = false;
        newGame = false;
        newGamePause = false;
        makeCar();
        constructRoads();
        constructRedRect();
        constructCircle();
        constructHexagon();
        constructOpponent1();
        constructOpponent2();
        constructTriangle();
    }
    void constructTriangle()
    {
        ptr4 = new WhiteTriangle(269.f, 510.f, 13.f);
    }
    void constructOpponent1()
    {
        // Add code here to initialize small boxes as needed
        oppoCar[0].makeOppo(580.f, 144.f, 40.f, 20.f);    // Initial direction is 1 (right)
        oppoCar[1].makeOppo(570.f, 135.f, 20.f, 10.f);   // Initial direction is -1 (left)
        oppoCar[2].makeOppo(570.f, 173.f, 20.f, 10.f);   // Initial direction is -1 (left)
        // oppoCar[3].makeOppo(600.f, 685.f, 20.f, 10.f);   // Initial direction is -1 (left)
         //oppoCar[4].makeOppo(600.f, 720.f, 20.f, 10.f);   // Initial direction is -1 (left)


         //Boundary seeting
        oppoCar[0].setLeftBoundaryOpp(64);
        oppoCar[1].setLeftBoundaryOpp(54);
        oppoCar[2].setLeftBoundaryOpp(54);
        // oppoCar[3].setLeftBoundaryOpp(83);
         //oppoCar[4].setLeftBoundaryOpp(83);

         //This is for the Right boundary detection of the each block use for the car

        oppoCar[0].setRightBoundaryOpp(730);
        oppoCar[1].setRightBoundaryOpp(720);
        oppoCar[2].setRightBoundaryOpp(720);
        // oppoCar[3].setRightBoundaryOpp(750);
         //oppoCar[4].setRightBoundaryOpp(750);
    }
    void constructOpponent2()
    {
        // Add code here to initialize small boxes as needed
        oppoCar2[0].makeOppo(700.f, 144.f, 40.f, 20.f);    // Initial direction is 1 (right)
        oppoCar2[1].makeOppo(720.f, 173.f, 20.f, 10.f);   // Initial direction is -1 (left)
        oppoCar2[2].makeOppo(690.f, 173.f, 20.f, 10.f);   // Initial direction is -1 (left)
        // oppoCar[3].makeOppo(600.f, 685.f, 20.f, 10.f);   // Initial direction is -1 (left)
         //oppoCar[4].makeOppo(600.f, 720.f, 20.f, 10.f);   // Initial direction is -1 (left)


         //Boundary seeting
        oppoCar2[0].setLeftBoundaryOpp(64);
        oppoCar2[1].setLeftBoundaryOpp(54);
        oppoCar2[2].setLeftBoundaryOpp(54);
        // oppoCar[3].setLeftBoundaryOpp(83);
         //oppoCar[4].setLeftBoundaryOpp(83);

         //This is for the Right boundary detection of the each block use for the car

        oppoCar2[0].setRightBoundaryOpp(730);
        oppoCar2[1].setRightBoundaryOpp(720);
        oppoCar2[2].setRightBoundaryOpp(720);
        /*oppoCar[3].setRightBoundaryOpp(750);
        oppoCar[4].setRightBoundaryOpp(750);*/
        //Up boundary
        oppoCar2[0].setUpBoundaryOpp(130.0);
        oppoCar2[1].setUpBoundaryOpp(160.0);
        oppoCar2[2].setUpBoundaryOpp(160.0);

        //Down boundary
        oppoCar2[0].setDownBoundaryOpp(700.0);
        oppoCar2[1].setDownBoundaryOpp(730.0);
        oppoCar2[2].setDownBoundaryOpp(730.0);
    }
    void constructHexagon()
    {
        ptr3 = new OrangeHexagon(200.f, 620.f, 20.f);
    }
    void constructCircle()
    {
        ptr2[0] = new GreenCircle(190.f, 147.f, 13.f);
        //  ptr2[1] = new GreenCircle(175.f, 600.f, 14.f);
        ptr2[1] = new GreenCircle(690.f, 710.f, 13.f);
        //ptr2[3] = new GreenCircle(480.f, 320.f, 14.f);
    }
    void makeCar()
    {
        // Add code here to initialize small boxes as needed
        smallBoxes[0].makeCar(390.f, 144.f, 40.f, 20.f, 0.1);    // Initial direction is 1 (right)
        smallBoxes[1].makeCar(380.f, 135.f, 20.f, 10.f, 0.1);   // Initial direction is -1 (left)
        smallBoxes[2].makeCar(380.f, 173.f, 20.f, 10.f, 0.1);   // Initial direction is -1 (left)
        smallBoxes[3].makeCar(410.f, 135.f, 20.f, 10.f, 0.1);   // Initial direction is -1 (left)
        smallBoxes[4].makeCar(410.f, 173.f, 20.f, 10.f, 0.1);   // Initial direction is -1 (left)


        //Boundary seeting
        smallBoxes[0].setLeftBoundary(64);
        smallBoxes[1].setLeftBoundary(54);
        smallBoxes[2].setLeftBoundary(54);
        smallBoxes[3].setLeftBoundary(83);
        smallBoxes[4].setLeftBoundary(83);

        //This is for the Right boundary detection of the each block use for the car

        smallBoxes[0].setRightBoundary(720);
        smallBoxes[1].setRightBoundary(710);
        smallBoxes[2].setRightBoundary(710);
        smallBoxes[3].setRightBoundary(740);
        smallBoxes[4].setRightBoundary(740);

        //This is for the Up boundary detection for the each block use to make car 
        smallBoxes[0].setUpBoundary(124);
        smallBoxes[1].setUpBoundary(117);
        smallBoxes[3].setUpBoundary(117);
        smallBoxes[2].setUpBoundary(150);
        smallBoxes[4].setUpBoundary(150);

        //This is for the Down boundary detection for the each block use to make car
        smallBoxes[0].setDownBoundary(710);
        smallBoxes[1].setDownBoundary(702);
        smallBoxes[2].setDownBoundary(738);
        smallBoxes[3].setDownBoundary(702);
        smallBoxes[4].setDownBoundary(738);

        /* smallBoxes[0].setBound1(320);
         smallBoxes[1].setBound1(310);
         smallBoxes[2].setBound1(310);
         smallBoxes[3].setBound1(340);
         smallBoxes[4].setBound1(340);*/
    }
    //for the red rectangle food
    void constructRedRect()
    {

        //Top left first
        ptr1[0] = new RedRectangle(269.f, 330.f, 13.f, 37.f);   //divider  

        //Top left second
        ptr1[1] = new RedRectangle(170.f, 330.f, 13.f, 37.f); //divider
        ptr1[2] = new RedRectangle(170.f, 250.f, 13.f, 50.f); //divider
        ptr1[3] = new RedRectangle(269.f, 250.f, 13.f, 37.f); //divider

        //Tope left third
        ptr1[4] = new RedRectangle(70.f, 330.f, 13.f, 50.f); //divider 1
        ptr1[5] = new RedRectangle(70.f, 250.f, 13.f, 50.f); //divider 2
        ptr1[6] = new RedRectangle(70.f, 160.f, 13.f, 50.f); //divider 3
        // ptr1[7] = new RedRectangle(170.f, 160.f, 13.f, 50.f); //divider 4
        ptr1[7] = new RedRectangle(269.f, 160.f, 13.f, 37.f); //divide 5

        //Bottom left first
       //ptr1[8] = new RedRectangle(269.f, 530.f, 13.f, 37.f); //divider

        //Bottom left second
        ptr1[8] = new RedRectangle(170.f, 530.f, 13.f, 50.f);     //divider
        //ptr1[10] = new RedRectangle(170.f, 620.f, 13.f, 50.f);    //divider
        ptr1[9] = new RedRectangle(269.f, 620.f, 13.f, 37.f);    //divider

        //Bottom left third
        ptr1[10] = new RedRectangle(70.f, 521.f, 13.f, 50.f); //divider   5
        ptr1[11] = new RedRectangle(70.f, 620.f, 13.f, 50.f); //divider   4
        ptr1[12] = new RedRectangle(70.f, 719.f, 13.f, 50.f); //divider   3
        ptr1[13] = new RedRectangle(170.f, 719.f, 13.f, 50.f); //divider  2
        ptr1[14] = new RedRectangle(269.f, 719.f, 13.f, 37.f); //divider  1

        //Top right first
        ptr1[15] = new RedRectangle(487.f, 320.f, 13.f, 37.f);   //divider 

        //Top right second
        ptr1[16] = new RedRectangle(574.f, 317.f, 13.f, 50.f); //divider
        ptr1[17] = new RedRectangle(574.f, 250.f, 13.f, 50.f); //divider
        ptr1[18] = new RedRectangle(487.f, 250.f, 13.f, 37.f); //divider

        //Top right third
        ptr1[19] = new RedRectangle(680.f, 317.f, 13.f, 50.f); //divider
        ptr1[20] = new RedRectangle(680.f, 235.f, 13.f, 50.f); //divider
        ptr1[21] = new RedRectangle(680.f, 160.f, 13.f, 50.f); //divider
        ptr1[22] = new RedRectangle(487.f, 160.f, 13.f, 37.f); //divider
        ptr1[23] = new RedRectangle(574.f, 160.f, 13.f, 50.f); //divider

        //Bottom right first
        ptr1[24] = new RedRectangle(484.f, 530.f, 13.f, 37.f); //divider

        //Bottom right second
        ptr1[25] = new RedRectangle(484.f, 620.f, 13.f, 37.f); //divider
        ptr1[26] = new RedRectangle(574.f, 620.f, 13.f, 50.f); //divider
        ptr1[27] = new RedRectangle(574.f, 530.f, 13.f, 50.f); //divider

        //Bottom right third
        ptr1[28] = new RedRectangle(484.f, 719.f, 13.f, 37.f); //divider
        ptr1[29] = new RedRectangle(574.f, 719.f, 13.f, 50.f); //divider
        // ptr1[30] = new RedRectangle(680.f, 719.f, 13.f, 50.f); //divider
        ptr1[30] = new RedRectangle(680.f, 620.f, 13.f, 50.f); //divider
        ptr1[31] = new RedRectangle(680.f, 527.f, 13.f, 37.f); //divider

    }
    //For the road class
    void constructRoads()
    {
        // upper middle
        roads[0].makeRoads(355.f, 388.f, 8.f, 30.f);  //Left of the middle
        roads[1].makeRoads(360.f, 388.f, 80.f, 20.f);  //Middle rectangle
        roads[2].makeRoads(440.f, 388.f, 8.f, 30.f);  //Right of the road middle

        //Lower middle
        roads[3].makeRoads(356.f, 430.f, 8.f, 30.f); //Left side of the road (middle)
        roads[4].makeRoads(356.f, 458.f, 92.f, 20.f);  //Middle of the road (middle)
        roads[5].makeRoads(440.f, 430.f, 8.f, 30.f);  //Right of the road (middle)

        //Top left corner
        roads[6].makeRoads(250.f, 289.f, 100.f, 13.f); //middle road
        roads[7].makeRoads(242.f, 289.f, 8.f, 66.f);  //left corner


        //Top left second corner
        roads[8].makeRoads(140.f, 200.f, 210.f, 13.f); //middle of the road
        roads[9].makeRoads(140.f, 210.f, 10.f, 147.f);  //left corner

        //Third top left corner
        roads[10].makeRoads(40.f, 100.f, 308.f, 13.f); //middle of the road
        roads[11].makeRoads(40.f, 100.f, 10.f, 257.f);  //left corner

        //Bottom left corne
        roads[12].makeRoads(252.f, 570.f, 100.f, 13.f); //Middle of the road
        roads[13].makeRoads(247.f, 517.f, 8.f, 66.f); //left corner

        //Bottom left second corner
        roads[14].makeRoads(149.f, 660.f, 203.f, 13.f); //middle
        roads[15].makeRoads(139.f, 520.f, 10.f, 153.f); //left corner

        //third bottom left 
        roads[16].makeRoads(45.f, 760.f, 307.f, 13.f); //middle
        roads[17].makeRoads(43.f, 521.f, 10.f, 252.f); //left corner
        //Top right
        roads[18].makeRoads(448.f, 289.f, 100.f, 13.f); //middle corner
        roads[19].makeRoads(540.f, 289.f, 8.f, 66.f);  //riht corner

        //second top right
        roads[20].makeRoads(448.f, 200.f, 210.f, 13.f); //middle of the road
        roads[21].makeRoads(648.f, 210.f, 10.f, 147.f);  //left corner

        //third top right
        roads[22].makeRoads(448.f, 100.f, 308.f, 13.f); //middle of the road
        roads[23].makeRoads(750.f, 100.f, 10.f, 257.f);  //left corner

        //Right bottom
        roads[24].makeRoads(450.f, 570.f, 100.f, 13.f); //Middle of the road
        roads[25].makeRoads(542.f, 517.f, 8.f, 66.f); //left corner

        //Second right bottom
        roads[26].makeRoads(450.f, 660.f, 203.f, 13.f); //middle
        roads[27].makeRoads(650.f, 510.f, 10.f, 163.f); //left corner

        //Third rigth bottom
        roads[28].makeRoads(450.f, 760.f, 307.f, 13.f); //middle
        roads[29].makeRoads(754.f, 521.f, 10.f, 252.f); //left corner

    }

    bool levels() override
    {
        Font font;
        Text scoreDisplay;
        Text lifeDisplay;
        font.loadFromFile("arial.ttf");

        srand(time(0));
        RenderWindow window(VideoMode(800, 800), "Level 4");
        Clock clock;
        float timer = 0;

        scoreDisplay.setFont(font);
        scoreDisplay.setCharacterSize(40);
        scoreDisplay.setFillColor(Color::Yellow);
        scoreDisplay.setPosition(60, 30);

        lifeDisplay.setFont(font);
        lifeDisplay.setCharacterSize(40);
        lifeDisplay.setFillColor(Color::Yellow);
        lifeDisplay.setPosition(600, 30);

        while (window.isOpen())
        {

            scoreDisplay.setString("Score    " + to_string(score.getScore()));
            lifeDisplay.setString("Life     " + to_string(count));

            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            //cout << "Timer:  " << timer << endl;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {

                    window.close();
                }
                if (e.type == Event::KeyPressed && e.key.code == Keyboard::P)
                {
                    // Toggle pause state on Space key press
                    pause = true;
                }

            }

            if (!pause || newGame)
            {
                //restartGame();
                window.clear(Color::Black);
                // Move and draw small boxes

                for (int i = 0; i < numSmallBoxes; ++i)
                {


                    float speed = 0.04f;  //To chnage the speed this is the value that control speed
                    //smallBoxes[i].move(speed, 0.0f);   //To change direction this is the vertical direction 
                    if (Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        //This condition is to restrict the UPward boundary 
                        if (smallBoxes[i].getShape().getPosition().y > smallBoxes[i].getUpBoundary())
                        {
                            smallBoxes[i].move(0.0f, -0.7f);
                        }
                        //smallBoxes[i].move(0.0f, -0.7f);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        // this condition restrict the boundary from the dow side 
                        if (smallBoxes[i].getShape().getPosition().y < smallBoxes[i].getDownBoundary())
                        {
                            smallBoxes[i].move(0.0f, 0.7f);
                        }
                        //smallBoxes[i].move(0.0f, 0.7f);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Left))
                    {
                        //smallBoxes[i].move(-speed, 0.0f);
                        //This condition restrict the boundary from the left side 
                        if (smallBoxes[i].getShape().getPosition().x > smallBoxes[i].getLeftBoundary())
                        {
                            smallBoxes[i].move(-speed, 0.0f);
                        }
                    }
                    //For right movement
                    if (Keyboard::isKeyPressed(Keyboard::Right))
                    {
                        //This sets the boundary of the right side so that the car don't go out pf bound from the right side
                        if (smallBoxes[i].getShape().getPosition().x < smallBoxes[i].getRightBoundary())
                        {
                            smallBoxes[i].move(speed, 0.0f);
                        }
                    }

                    ////Collision of roads and cars
                    //These values will keep trach of collision of car and roads 
                    //these value ewill seyt new offset values and check for the
                    //x and y values
                    float valueX = 0.0f;
                    float valueY = 0.0f;
                    float newOffsetX = 0.0f;
                    float newOffsetY = 0.0f;
                    for (int k = 0; k < totalRoads; k++)
                    {
                        if (smallBoxes[i].getShape().getGlobalBounds().intersects(roads[k].getBounds()))
                        {
                            // cout << "In collision\n";
                            // smallBoxes[i].stopCar();
                            // smallBoxes[i].handleCollision(roads, k); 
                            valueX = smallBoxes[i].getShape().getPosition().x - roads[k].getBounds().left;
                            valueY = smallBoxes[i].getShape().getPosition().y - roads[k].getBounds().top;

                            // Determine the direction of the collision and move away
                           /* newOffsetX = (std::abs(valueX) > std::abs(valueY)) ? ((valueX > 0) ? 1.0f : -1.0f) : 0.0f;
                            newOffsetY = (std::abs(valueX) > std::abs(valueY)) ? 0.0f : ((valueY > 0) ? 1.0f : -1.0f);*/

                            //This will set the value for the horizontal movement after collision
                            if (abs(valueX) > abs(valueY))
                            {
                                if (valueX > 0)
                                {
                                    newOffsetX = 1.4f;
                                }
                                else
                                {
                                    newOffsetX = -1.4f;
                                }
                                newOffsetY = 0.0f;
                            }
                            //This is for the vertical movement of cars after collision
                            else
                            {
                                newOffsetX = 0.0f;

                                if (valueY > 0)
                                {
                                    newOffsetY = 1.4f;
                                }
                                else
                                {
                                    newOffsetY = -1.4f;
                                }
                            }
                            //This is becausein this way all the rectangle boxes of car will move equally
                            //To  make them move equally their offset will be set according to thta
                            for (int w = 0; w < numSmallBoxes; w++)
                            {

                                smallBoxes[w].moveCarFunc(newOffsetX, newOffsetY);
                            }
                        }
                    }
                    //Checking collision for the redRectangles
                    for (int j = 0; j < totalRedFood; j++)
                    {
                        //Here i am doing dynamic cast because the one function makeFood is commaon to all base 
                        // classes but each class have one different function 
                        //getshape so toaccess that i am doing casting so that i can get the bounds o the each shape sepertaely
                        RedRectangle* redRectBounds = dynamic_cast<RedRectangle*>(ptr1[j]);
                        //This will check if the bond is null or not
                        if (redRectBounds != nullptr)
                        {
                            //Float rect bound wiil get the floatig point precision of the rectangle
                            FloatRect bound = redRectBounds->getShape().getGlobalBounds();

                            //Thjis condition is checking for the collison
                            if (smallBoxes[i].getShape().getGlobalBounds().intersects(bound))
                            {
                                //ptr1[j]->setCheck(false);
                                countClose++;
                                //This wil make all the rectangls zero
                                ptr1[j] = new RedRectangle(0.f, 0.f, 0.f, 0.f);
                                score.calculateScoreRed();
                               // score.createFile();
                            }

                        }
                    }
                    //Collision for the circles
                    
                    for (int j = 0; j < totalCircle; j++)
                    {
                        //Here i am doing dynamic cast because the one function makeFood is commaon to all base 
                        // classes but each class have one different function 
                        //getshape so toaccess that i am doing casting so that i can get the bounds o the each shape sepertaely
                        GreenCircle* circleBound = dynamic_cast<GreenCircle*>(ptr2[j]);
                        //This will check if the bond is null or not
                        if (circleBound != nullptr)
                        {
                            //Float rect bound wiil get the floatig point precision of the rectangle
                            FloatRect bound = circleBound->getCircle().getGlobalBounds();
                            //Thjis condition is checking for the collison
                            if (smallBoxes[i].getShape().getGlobalBounds().intersects(bound))
                            {
                                //This wil make all the rectangls zero
                                //ptr2[j]->setCheck(false);
                                count++;
                                countClose++;
                                lifeCount.setLife(count);
                                ptr2[j] = new GreenCircle(0.f, 0.f, 0.f);
                                score.calculateScoreCircle();

                            }
                        }
                    }
                    //For hexagon
                    OrangeHexagon* hexagonBound = dynamic_cast<OrangeHexagon*>(ptr3);
                    if (hexagonBound != nullptr)
                    {
                        FloatRect bound = hexagonBound->getHexa().getGlobalBounds();

                        if (smallBoxes[i].getShape().getGlobalBounds().intersects(bound))
                        {
                            //This will remove the hexagon
                            ptr3 = new OrangeHexagon(0.f, 0.f, 0.f);
                            //Will call the score function to calculate score
                            score.calculateScoreHexa();
                            countClose++;
                            // ptr3->setCheck(false);
                             // Set the duration of the power-up effect (e.g., 10 seconds)
                             //float powerUpDuration = 10.0;
                             //powerUpTimer.restart();
                             //this for the spped increment in all the car boxes
                            for (int j = 0; j < numSmallBoxes; ++j)
                            {
                                smallBoxes[j].setSpeedIncrement(1.5);
                            }
                            //this will set the flag true that speed increase now
                            powerUpActive = true;
                            //cout << "Power-up activated! Speed increased for all rectangles." << endl'\;
                        }
                    }
                    //This conditon will check if the power active is true tand powerUptime is greater so this will become true and  rest all the values again
                    if (powerUpTimer.getElapsedTime().asSeconds() >= powerUpDuration)
                    {
                        for (int j = 0; j < numSmallBoxes; ++j)
                        {
                            smallBoxes[j].setSpeedIncrement(1.0f);
                        }
                        powerUpActive = false;
                        //cout << "Power-up duration ended. Speed reset for all rectangles." << endl;
                    }

                    //For triangle
                    WhiteTriangle* triBound = dynamic_cast<WhiteTriangle*>(ptr4);
                    if (triBound != nullptr)
                    {
                        FloatRect bound = triBound->getTriangle().getGlobalBounds();

                        if (smallBoxes[i].getShape().getGlobalBounds().intersects(bound))
                        {
                            //This will remove the hexagon
                            ptr4 = new WhiteTriangle(1200.f, 1200.f, 0.f);
                            //for (int j = 0; j < totalOpponent1; ++j)
                            //{
                            //    oppoCar[j].makeOppo(0.0f, 0.0f, 0.0f, 0.0f);
                            //    oppoCar2[j].makeOppo(0.0f, 0.0f, 0.0f, 0.0f);
                            //}
                            ////Clock to restart counting time
                            //opponent.restart();
                            //
                        }
                    }
                    //This conditon will check if the power active is true tand powerUptime is greater so this will become true and  rest all the values again
                    //if (opponent.getElapsedTime().asSeconds() >= 10.f)
                    //{
                    //    constructOpponent1();
                    //    constructOpponent1();
                    //    //oppoCar[0].makeOppo(580.f, 144.f, 40.f, 20.f);    // Initial direction is 1 (right)
                    //    //oppoCar[1].makeOppo(570.f, 135.f, 20.f, 10.f);   // Initial direction is -1 (left)
                    //    //oppoCar[2].makeOppo(570.f, 173.f, 20.f, 10.f);
                    //    for (int j = 0; j < totalOpponent1; j++)
                    //    {

                    //        // constructOpponent();
                    //        float oppSpeed = 0.06f;
                    //        //cout << "In moving condition1\n";
                    //        oppoCar[j].move(oppSpeed * oppoCar[j].getDirection(), 0.0f);  //Here the y axis is zer as in level 1 the opponent car 


                    //        //take top and bottom turns so y axis can't change so that's why
                    //        if (smallBoxes[i].getShape().getGlobalBounds().intersects(oppoCar[j].getShape().getGlobalBounds()))
                    //        {
                    //            cout << "Reset\n";
                    //            //This will call the reset function after collision
                    //            resetGame();
                    //        }
                    //        if (oppoCar[j].getShape().getPosition().x + oppoCar[j].getShape().getSize().x > 730 ||
                    //            smallBoxes[i].getShape().getPosition().x < 50)
                    //        {
                    //            oppoCar[j].setDirection(-oppoCar[j].getDirection());
                    //        }
                    //        //The conditions will check for the 

                    //        if (oppoCar[j].getShape().getPosition().x > oppoCar[j].getLeftBoundaryOpp())
                    //        {

                    //            oppoCar[j].setDirection(-oppoCar[j].getDirection());

                    //            // oppoCar[i].setDirection(-1);  // Change dire
                    //        }
                    //        if (oppoCar[j].getShape().getPosition().x < oppoCar[j].getRightBoundaryOpp())
                    //        {

                    //            oppoCar[j].setDirection(-oppoCar[j].getDirection());

                    //        }

                    //    }
                    //    for (int j = 0; j < totalOpponent2; j++)
                    //    {

                    //        // constructOpponent();
                    //        float oppSpeed = 0.06f;
                    //        //cout << "In moving condition1\n";
                    //        oppoCar2[j].move(oppSpeed * oppoCar[j].getDirection(), 0.0f);  //Here the y axis is zer as in level 1 the opponent car 


                    //        //take top and bottom turns so y axis can't change so that's why
                    //        if (smallBoxes[i].getShape().getGlobalBounds().intersects(oppoCar2[j].getShape().getGlobalBounds()))
                    //        {
                    //            cout << "Reset\n";
                    //            //This will call the reset function after collision
                    //            resetGame();
                    //        }
                    //        if (oppoCar2[j].getShape().getPosition().x + oppoCar2[j].getShape().getSize().x > 730 ||
                    //            smallBoxes[i].getShape().getPosition().x < 50)
                    //        {
                    //            oppoCar2[j].setDirection(-oppoCar2[j].getDirection());
                    //        }
                    //        //The conditions will check for the 

                    //        if (oppoCar2[j].getShape().getPosition().x > oppoCar2[j].getLeftBoundaryOpp())
                    //        {

                    //            oppoCar2[j].setDirection(-oppoCar2[j].getDirection());

                    //            // oppoCar[i].setDirection(-1);  // Change dire
                    //        }
                    //        if (oppoCar2[j].getShape().getPosition().x < oppoCar2[j].getRightBoundaryOpp())
                    //        {

                    //            oppoCar2[j].setDirection(-oppoCar2[j].getDirection());

                    //        }

                    //    }
                    //}
                    //Opponent collision detection
                    for (int j = 0; j < totalOpponent1; j++)
                    {
                        float oppSpeed = 0.08f;
                        oppoCar[j].move(oppSpeed, 0.0f);  //Here the y axis is zer as in level 1 the opponent car 

                        //take top and bottom turns so y axis can't change so that's why
                        if (smallBoxes[i].getShape().getGlobalBounds().intersects(oppoCar[j].getShape().getGlobalBounds()))
                        {
                            count--;
                            //cout << count;
                            //lifeCount.setLife(count);
                            //This will call the reset function after collision
                            resetGame();
                        }
                        /*if (oppoCar[i].getShape().getPosition().x + oppoCar[i].getShape().getSize().x > 730 ||
                            smallBoxes[i].getShape().getPosition().x < 50)
                        {
                            oppoCar[i].setDirection(-oppoCar[i].getDirection());
                        }*/
                        //The conditions will check for the 

                        if (oppoCar[j].getShape().getPosition().x > oppoCar[j].getLeftBoundaryOpp())
                        {
                            oppoCar[j].setDirection(-oppoCar[j].getDirection());

                            // oppoCar[i].setDirection(-1);  // Change dire
                        }
                        if (oppoCar[j].getShape().getPosition().x < oppoCar[j].getRightBoundaryOpp())
                        {
                            oppoCar[j].setDirection(-oppoCar[j].getDirection());

                            //oppoCar[i].setDirection(-1);
                        }

                        window.draw(oppoCar[j].getShape());
                    }
                    //Second opponent car
                    for (int j = 0; j < totalOpponent2; j++)
                    {
                        float oppSpeed = 0.06f;
                        oppoCar2[j].move(0.0f, oppSpeed);  //Here the y axis is zer as in level 1 the opponent car 


                        //take top and bottom turns so y axis can't change so that's why
                        if (smallBoxes[i].getShape().getGlobalBounds().intersects(oppoCar2[j].getShape().getGlobalBounds()))
                        {
                            //This will call the reset function after collision
                            resetGame();
                        }
                        /*if (oppoCar[i].getShape().getPosition().x + oppoCar[i].getShape().getSize().x > 730 ||
                            smallBoxes[i].getShape().getPosition().x < 50)
                        {
                            oppoCar[i].setDirection(-oppoCar[i].getDirection());
                        }*/
                        //The conditions will check for the 

                        if (oppoCar2[j].getShape().getPosition().y < oppoCar2[j].getUpBoundaryOpp())
                        {

                            // cout << "Up: " << oppoCar[j].getShape().getPosition().y << endl;
                            oppoCar2[j].setDirection(-oppoCar2[j].getDirection());

                        }
                        if (oppoCar2[j].getShape().getPosition().y > oppoCar2[j].getDownBoundaryOpp())
                        {
                            //cout << "Down: " << oppoCar[j].getShape().getPosition().y << endl;
                            oppoCar2[j].setDirection(-oppoCar2[j].getDirection());
                            //oppoCar[i].setDirection(-1);
                        }
                        window.draw(oppoCar2[j].getShape());

                    }
                    window.draw(smallBoxes[i].getShape());

                }

                //Draw Roads
                for (int i = 0; i < totalRoads; i++)
                {
                    window.draw(roads[i].getRoad());
                }

                //Draw dividers
                for (int i = 0; i < totalRedFood; i++)
                {
                    //To make implement the polymorphism i poss windows as argumne os each clas have the same function
                    ptr1[i]->makeFood(window);
                }
                //Draw Circles
                for (int i = 0; i < totalCircle; i++)
                {
                    //To make implement the polymorphism i poss windows as argument os each clas have the same function
                    ptr2[i]->makeFood(window);
                }
                ptr3->makeFood(window);
                ptr4->makeFood(window);
                int wait = 0;
                if (countClose == 35)
                {
                    window.close();
                    return true;
                }
                //Draw live score on board
                window.draw(scoreDisplay);
                window.draw(lifeDisplay);
                window.display();

            }
            else
            {

                // Create a new RenderWindow for the pause screen
                RenderWindow pauseWindow(VideoMode(800, 800), "Level 4");
                pauseWindow.clear(Color::Black);
                //Font to write text
                Font font;
                //This will load text file to write on screen
                font.loadFromFile("arial.ttf");
                //Text to write on screen
                Text titleText("Pause game", font, 60);
                titleText.setFillColor(Color::Cyan);
                titleText.setPosition(240, 80);
                titleText.setStyle(Text::Bold);

                Text option1("1.Start New Game ", font, 40);
                option1.setFillColor(Color::White);
                option1.setPosition(240, 240);

                Text option2("2.High Score ", font, 40);
                option2.setFillColor(Color::White);
                option2.setPosition(300, 340);

                Text option3("3.Help", font, 40);
                option3.setFillColor(Color::White);
                option3.setPosition(350, 440);

                Text option4("4.Exit", font, 40);
                option4.setFillColor(Color::White);
                option4.setPosition(350, 540);

                Text option5("5.Continue", font, 40);
                option5.setFillColor(Color::White);
                option5.setPosition(320, 640);


                while (pauseWindow.isOpen())
                {
                    Event e1;
                    while (pauseWindow.pollEvent(e1))
                    {
                        if (e1.type == Event::Closed)
                            pauseWindow.close();

                        if (e1.type == Event::KeyPressed && e1.key.code == Keyboard::Num1)
                        {
                            newGame = true;
                            resetGame();
                            pauseWindow.close();
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Num2))  //Working for high score
                        {
                            RenderWindow scoreWindow(VideoMode(800, 800), "High Score Screen");
                            score.createFile(scoreWindow);
                            // window.close();
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Num3))   //Working for help
                        {
                            pauseHelp();
                        }
                        if (Keyboard::isKeyPressed(Keyboard::Num5))  //Woking for continue
                        {
                            pause = false;
                            pauseWindow.close();
                        }

                        if (Keyboard::isKeyPressed(Keyboard::Escape))    //Working for exit
                        {
                            pauseWindow.close();
                            window.close();
                        }
                        pauseWindow.clear();
                        pauseWindow.draw(titleText);
                        pauseWindow.draw(option1);
                        pauseWindow.draw(option2);
                        pauseWindow.draw(option3);
                        pauseWindow.draw(option4);
                        pauseWindow.draw(option5);
                        //Display tet window
                        pauseWindow.display();
                    }
                }
            }

        }

    }
    //This is the game rest function when the two cras will collide all the things in game will go bak to initial 
    //position and gae will start again
    //Also this function is repsonsible for restarting game
    void resetGame()
    {
       //Calling these functions again to reset 
        makeCar();
        constructRoads();
        constructRedRect();
        constructCircle();
        constructHexagon();
        constructOpponent1();
        constructOpponent2();
        constructTriangle();

        countClose = 0;
        srand(time(0));
        RenderWindow window(VideoMode(800, 800), "OOP-Project, Spring-2023");
        Clock clock;
        float timer = 0;

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            //cout << "Timer:  " << timer << endl;
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {

                    window.close();
                }
            }
            window.clear(Color::Black);

            for (int i = 0; i < totalOpponent1; i++)
            {
                window.draw(oppoCar[i].getShape());
            }
            for (int i = 0; i < totalOpponent2; i++)
            {
                window.draw(oppoCar2[i].getShape());
            }
            for (int i = 0; i < numSmallBoxes; i++)
            {
                window.draw(smallBoxes[i].getShape());
            }
            for (int i = 0; i < totalRedFood; i++)
            {
                ptr1[i]->makeFood(window);
            }
            //Draw Circles
            for (int i = 0; i < totalCircle; i++)
            {
                //To make implement the polymorphism i poss windows as argument os each clas have the same function
                ptr2[i]->makeFood(window);
            }
            ptr3->makeFood(window);
            ptr4->makeFood(window);
            window.display();
            window.close();
            levels();
        }
    }
    void pauseHelp()
    {
        RenderWindow window(VideoMode(800, 600), "HELP SCREEN");
        /* Clock clock;
         float timer = 0;*/
        Font font;
        //This will load text file to write on screen
        font.loadFromFile("arial.ttf");
        //Thes efoolow are teh tecxts
        Text titleText("Help", font, 80);
        titleText.setFillColor(Color::Cyan);
        titleText.setPosition(220, 50);
        titleText.setStyle(Text::Bold | Text::Underlined);

        // Menu option 1;
        Text option1("1.To start new game press 1 from Keyboard.", font, 20);
        option1.setFillColor(Color::White);
        option1.setPosition(150, 200);

        //Menu option 2
        Text option2("2.To exit press escape.", font, 20);
        option2.setFillColor(Color::White);
        option2.setPosition(150, 270);

        Text option3("3.To continue you have to press 5 on pause Screen ", font, 20);
        option3.setFillColor(Color::White);
        option3.setPosition(150, 340);

        Text option4("4.To exit this help Screen press Escape key", font, 20);
        option4.setFillColor(Color::White);
        option4.setPosition(150, 410);

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window.close();
                }
                if (Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    levels();
                    window.close();
                    //display_menu();

                }

            }

            window.clear();

            window.draw(titleText);
            window.draw(option1);
            window.draw(option2);
            window.draw(option3);
            window.draw(option4);

            window.display();
        }
    }
};
int Level4::countClose = 0;
int Level4::count = 3;