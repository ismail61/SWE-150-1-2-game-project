#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
//#include<SFML/System.hpp>
//#include<SFML/Network.hpp>
#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<bits/stdc++.h>
const double SCREEN_HEIGHT=630.0;
const double SCREEN_WEIGHT=650.0;
const int borderLeft=90;
const int borderRight=540;
using namespace sf;
using namespace std;
double Speed=1;
RenderWindow window(VideoMode(SCREEN_HEIGHT,SCREEN_WEIGHT),"Car Racing Game....");
int coinrand(int a, int b);
int gameover();
int main()
{

    window.setFramerateLimit(60);
    ///Road
    Texture t;
    t.loadFromFile("pic//background1.png");
    Sprite s(t),s1(t);
    ///car
    Texture car;
    car.loadFromFile("pic//car2.png");
    Sprite Car(car);
    ///Car1
    Texture car1;
    car1.loadFromFile("pic//car3.png");
    Sprite Car1(car1);
    double car1x,car1y;
    ///Car2
    Texture car2;
    car2.loadFromFile("pic//car4.png");
    Sprite Car2(car2);
    double car2x,car2y;
    car2x=coinrand(borderLeft,borderRight);
    car2y=-100;
    ///Car3
    Texture car3;
    car3.loadFromFile("pic//car5.png");
    Sprite Car3(car3);
    double car3x,car3y;
    car3x=coinrand(borderLeft,borderRight);
    car3y=-200;
    ///Car4
    Texture car4;
    car4.loadFromFile("pic//car6.png");
    Sprite Car4(car4);
    double car4x,car4y;
    car4x=coinrand(borderLeft,borderRight);
    car4y=-300;
    ///Car5
    Texture car5;
    car5.loadFromFile("pic//car7.png");
    Sprite Car5(car5);
    double car5x,car5y;
    car5x=coinrand(borderLeft,borderRight);
    car5y=-400;
    ///COIN PICTURE.....
    Texture coin;
    coin.loadFromFile("pic//coin.png");
    Sprite Coin(coin);
    Coin.setScale(0.2f,0.2f);
    double coinx,coiny;
    coinx=coinrand(borderLeft,borderRight);
    coiny=-500;
    Texture coin1;
    coin1.loadFromFile("pic//coin.png");
    Sprite Coin1(coin1);
    Coin1.setScale(0.2f,0.2f);
    double coin1x,coin1y;
    coin1x=coinrand(borderLeft,borderRight);
    coin1y=-500;
    double carx,cary;
    carx=SCREEN_WEIGHT/2-36;
    cary=SCREEN_HEIGHT-60;
    double y1=0;
    double y2=-630;
    double left=38.0;
    double right=548.0;
    car1x=coinrand(borderLeft,borderRight);
    car1y=0;
    while(window.isOpen())
    {
        ///car position setup.......
        Car.setPosition(carx,cary);
        Car1.setPosition(car1x,car1y);
        Car2.setPosition(car2x,car2y);
        Car3.setPosition(car3x,car3y);
        Car4.setPosition(car4x,car4y);
        Car5.setPosition(car5x,car5y);
        ///Coin position setup.......
        Coin.setPosition(coinx,coiny);
        Coin1.setPosition(coin1x,coin1y);
        ///Road position  setup.....
        s.setPosition(0,y1);
        s1.setPosition(0,y2);
        ///Road scroll.......
        if (y2>=0)
        {
            y1=0;
            y2=y1-650;
        }
        y1+=0.5;
        y2+=0.5;
        ///CAR setup in road......
        if (car1y>SCREEN_HEIGHT)
            {
                car1y=0;
                car1x=coinrand(borderLeft,borderRight);
            }
        else
            {
                car1y=car1y+Speed;
            }
        if (car2y>SCREEN_HEIGHT)
            {
                car2y=0;
                car2x=coinrand(borderLeft,borderRight);
            }
        else
            {
                car2y=car2y+Speed;
            }
        if (car3y>SCREEN_HEIGHT)
            {
                car3y=0;
                car3x=coinrand(borderLeft,borderRight);
            }
        else
            {
                car3y=car3y+Speed;
            }
        if (car4y>SCREEN_HEIGHT)
            {
                car4y=0;
                car4x=coinrand(borderLeft,borderRight);
            }
        else
            {
                car4y=car4y+Speed;
            }
        if (car5y>SCREEN_HEIGHT)
            {
                car5y=0;
                car5x=coinrand(borderLeft,borderRight);
            }
        else
            {
                car5y=car5y+Speed;
            }
        ///COIN setup in road.........
        if (coiny>SCREEN_HEIGHT)
            {
                coiny=0;
                coinx=coinrand(borderLeft,borderRight);
            }
        else
            {
                coiny=coiny+Speed;
            }
        if (coin1y>SCREEN_HEIGHT)
            {
                coin1y=0;
                coin1x=coinrand(borderLeft,borderRight);
            }
        else
            {
                coin1y=coin1y+Speed;
            }
        Event event;
        ///Keyboard press & Move car......
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Left)
                        {
                            if(carx>left)
                                {
                                    carx=carx-10;
                                }
                        }
                    if (event.key.code == Keyboard::Right)
                        {
                            if(carx<right)
                                {
                                    carx=carx+10;
                                 }
                        }
                    if (event.key.code == Keyboard::Up)
                        {
                            if(cary>0)
                                {
                                    cary=cary-10;
                                }
                        }
                    if (event.key.code == Keyboard::Down)
                        {
                            if(cary<570)
                                {
                                    cary=cary+10;
                                }
                        }
                }

        }
        ///CAR CRASH.......
        if (((carx>=(car1x-30)) &&(carx<=(car1x+30)))&&((cary>=(car1y-50)) &&(cary)<=(car1y+50)))
            {
                gameover();
            }
        if (((carx>=(car2x-30)) &&(carx<=(car2x+30)))&&((cary>=(car2y-50)) &&(cary)<=(car2y+50)))
            {
                gameover();
            }
        if (((carx>=(car3x-30)) &&(carx<=(car3x+30)))&&((cary>=(car3y-50)) &&(cary)<=(car3y+50)))
            {
                gameover();
            }
        if (((carx>=(car4x-30)) &&(carx<=(car4x+30)))&&((cary>=(car4y-50)) &&(cary)<=(car4y+50)))
            {
                gameover();
            }
        if (((carx>=(car5x-30)) &&(carx<=(car5x+30)))&&((cary>=(car5y-50)) &&(cary)<=(car5y+50)))
            {
                gameover();
             }
        window.clear();
        window.draw(s);
        window.draw(s1);
        window.draw(Car);
        window.draw(Car1);
        window.draw(Car2);
        window.draw(Car3);
        window.draw(Car4);
        window.draw(Car5);
        window.draw(Coin);
        ///new coin setup..........
        if (((carx>=(coinx-30)) &&(carx<=(coinx+30)))&&((cary>=(coiny-50)) &&(cary)<=(coiny+50)))
            {
                coinx=SCREEN_WEIGHT+100;
                coiny=SCREEN_WEIGHT+100;
                window.draw(Coin1);
            }
        window.display();
    }
    return 0;
}
int gameover()
{
    Texture over;
    over.loadFromFile("pic//overgame.png");
    Sprite Over(over);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(Over);
        window.display();

    }

}
int coinrand(int a, int b)
{
        static bool first = true;
        if (first){
        srand( time(NULL) );
        first = false;}
        int result=a + rand() % (( b + 1 ) - a);
        result=(result/10)*10;
        return result;
}
