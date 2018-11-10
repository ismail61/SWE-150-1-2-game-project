#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace sf;
using namespace std;

//Initialization Game Constant...
const double screen_width=800;
const double screen_height=600;
const int border_left=185;
const int border_right=615;
const int racer_width=45;
const int racer_height=65;
int score=0;
double game_speed=1;

//Creation Main Windows...
RenderWindow game(VideoMode(screen_width, screen_height), "Car Racing");

//Creation Random Number for Game Loop...
int getRandomNumber(int a, int b);

//Creation Game_Over Screen...
int gameOver();

int main()
{

    //Initialization Textures...
    Texture background, racer, ecar1, ecar2, ecar3, ecar4, game_over;

    //Load All Images...
    if(!background.loadFromFile("cars/background.png")) return EXIT_FAILURE;
    if(!racer.loadFromFile("cars/racer.png")) return EXIT_FAILURE;
    if(!ecar1.loadFromFile("cars/ecar1.png")) return EXIT_FAILURE;
    if(!ecar2.loadFromFile("cars/ecar2.png")) return EXIT_FAILURE;
    if(!ecar3.loadFromFile("cars/ecar3.png")) return EXIT_FAILURE;
    if(!ecar4.loadFromFile("cars/ecar4.png")) return EXIT_FAILURE;

    //Creation Sprites...
    Sprite Background(background), Background1(background), Racer(racer), Ecar1(ecar1), Ecar2(ecar2), Ecar3(ecar3), Ecar4(ecar4), Game_Over(game_over);

    //Initialize Position for Racer and Other Objects on the Road...
    double racerx, racery, ecar1x, ecar1y, ecar2x, ecar2y, ecar3x, ecar3y, ecar4x, ecar4y;

    // Set Position for Racer and Other Objects on the Road...
    racerx=screen_width/2;
    racery=screen_height-racer_height;
    ecar1x=getRandomNumber(border_left, border_right);
    ecar2x=getRandomNumber(border_left, border_right);
    ecar3x=getRandomNumber(border_left, border_right);
    ecar4x=getRandomNumber(border_left, border_right);
    ecar1y=0, ecar2y=-150, ecar3y=-300, ecar4y=-450;
    double backgroundy1=0, backgroundy2=-600;


    // Game Loop
    while(game.isOpen())
    {
        // Set Cars and Coin Position...
        Racer.setPosition(racerx, racery);
        Ecar1.setPosition(ecar1x, ecar1y);
        Ecar2.setPosition(ecar2x, ecar2y);
        Ecar3.setPosition(ecar3x, ecar3y);
        Ecar4.setPosition(ecar4x, ecar4y);

        // Create Scrolling Background
        Background.setPosition(0, backgroundy1);
        Background1.setPosition(0, backgroundy2);
        if(backgroundy2>0)
        {
            backgroundy1=0;
            backgroundy2=backgroundy1-600;
        }
        backgroundy1+=0.2;
        backgroundy2+=0.2;

        //Set Enemy Cars Loop...
        if(ecar1y>screen_height)
        {
            ecar1y=-10;
            ecar1x=getRandomNumber(border_left, border_right);
            score++;
        }
        else
        {
            ecar1y+=game_speed;
        }
        if(ecar2y>screen_height)
        {
            ecar2y=-10;
            ecar2x=getRandomNumber(border_left, border_right);
            score++;
        }
        else
        {
            ecar2y+=game_speed;
        }
        if(ecar3y>screen_height)
        {
            ecar3y=-10;
            ecar3x=getRandomNumber(border_left, border_right);
            score++;
        }
        else
        {
            ecar3y+=game_speed;
        }
        if(ecar4y>screen_height)
        {
            ecar4y=-10;
            ecar4x=getRandomNumber(border_left, border_right);
            score++;
        }
        else
        {
            ecar4y+=game_speed;
        }


        //Create Event to Handle Input from Keyboard...
        Event event;
        while(game.pollEvent(event))
        {
            if(event.type==Event::Closed)
                game.close();
            if(event.type==Event::KeyPressed)
            {
                if(event.key.code==Keyboard::Left)
                {
                    if(racerx>border_left) {racerx=racerx-15;}
                }
                if(event.key.code==Keyboard::Right)
                {
                    if(racerx<border_right) {racerx=racerx+15;}
                }
                if(event.key.code==Keyboard::Up)
                {
                    if(racery>0) {racery=racery-15;}
                }
                if(event.key.code==Keyboard::Down)
                {
                    if(racery<screen_height-70) {racery=racery+15;}
                }
            }
        }

        //Check if Accidents Happen
        if((racerx>=ecar1x-30 && racerx<=ecar1x+30) && (racery>=ecar1y-30 && racery<=ecar1y+30))
        {
            gameOver();
        }
        if((racerx>=ecar2x-30 && racerx<=ecar2x+30) && (racery>=ecar2y-30 && racery<=ecar2y+30))
        {
            gameOver();
        }
        if((racerx>=ecar3x-30 && racerx<=ecar3x+30) && (racery>=ecar3y-30 && racery<=ecar3y+30))
        {
            gameOver();
        }
        if((racerx>=ecar4x-30 && racerx<=ecar4x+30) && (racery>=ecar4y-30 && racery<=ecar4y+30))
        {
            gameOver();
        }

        //Clear and Redraw Position...
        game.clear();
        game.draw(Background);
        game.draw(Background1);
        game.draw(Racer);
        game.draw(Ecar1);
        game.draw(Ecar2);
        game.draw(Ecar3);
        game.draw(Ecar4);
        game.display();

    }
    return EXIT_SUCCESS;

}
//Create Start Game...

//Create Game Over...
int gameOver()
{
    Texture game_over, troll;
    if(!game_over.loadFromFile("cars/over.png")) return EXIT_FAILURE;
    if(!troll.loadFromFile("cars/troll.png")) return EXIT_FAILURE;

    Sprite Gameover(game_over);
    Sprite Troll(troll);
    Troll.setPosition(10, 325);

    while(game.isOpen())
    {
        Event event;
        while(game.pollEvent(event))
        {
            if(event.type==Event::Closed)
                game.close();
        }
        game.clear();
        game.draw(Gameover);
        game.draw(Troll);
        game.display();
    }
}

//Create Random Number...
int getRandomNumber(int a, int b)
{
    static bool first= true;
    if(first)
    {
        srand(time(NULL));
        first= false;
    }
    int result = a + rand()%((b+1)-a);;
    return result;
}
