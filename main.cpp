#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace sf;
using namespace std;

//Initialization Game Constant...
const double screen_width=800;
const double screen_height=600;
const int border_left=140;
const int border_right=660;
const int racer_width=40;
const int racer_height=80;

//Creation Main Windows...
RenderWindow game(VideoMode(screen_width, screen_height), "Car Racing");

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


int main()
{

    //Initialization Textures...
    Texture background, racer;


    //Load Images...
    if(!background.loadFromFile("background.png")) return EXIT_FAILURE;
    if(!racer.loadFromFile("racer.png")) return EXIT_FAILURE;

    //Create Sprites...
    Sprite Background(background), Background1(background), Racer(racer);

    //Initialize Position for Racer...
    double racerx, racery;

    // Set Position for Racer...
    racerx=screen_width/2;
    racery=screen_height-racer_height;
    double backgroundy1=0, backgroundy2=800;

    // Game Loop
    while(game.isOpen())
    {

        // Set Car Position...
        Racer.setPosition(racerx, racery);

        // Create Scrolling Background
        Background.setPosition(0, backgroundy1);
        Background1.setPosition(0, backgroundy2);
        if(backgroundy2>0)
        {
            backgroundy1=0;
            backgroundy2=backgroundy1-835;
        }
        backgroundy1+=0.2;
        backgroundy2+=0.2;



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
                    if(racery<screen_height-80) {racery=racery+15;}
                }
            }
        }


        //Clear and Redraw Position...
        game.clear();
        game.draw(Background);
        game.draw(Background1);
        game.draw(Racer);
        game.display();

    }
    return EXIT_SUCCESS;

}
