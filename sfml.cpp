#include<bits/stdc++.h>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

const double SCREEN_WIDTH=1280;
const double SCREEN_HEIGH=700;
const int borderLeft=245;
const int borderRight=975;
const int carWidth=75;
const int carHeight=70;
int getRandomNumber(int a,int b);
double BackgroundY1=0,BackgroundY2=-700;
int obs1X,obs1Y;
Color notSelected(255,255,255),done(255,255,0);

int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(1280,700),"Car Racing Game.....");
    ///    window.SetFramerateLimit(60);
    Font myfont;

    if (!myfont.loadFromFile("Fonts/font1.ttf"))
    {

        return EXIT_FAILURE;
    }
    float time=0.0f;
    Clock key;
    Font style1,style2,style3;
    double carX,carY,Obs1X, Obs1Y,Obs2X, Obs2Y,Obs3X, Obs3Y,Obs4X, Obs4Y,gameSpeed=0.6,Obs5X,Obs5Y;
    Text scoretxt,lifetxt,mgzntxt,gametxt,newgametxt,leveltxt,helptxt,exittxt,loadgametxt,note,gameovertxt,helptext,highscoretxt,level1txt;
    Texture backgroundTexture,carTexture,obs1Texture,obs2Texture,obs3Texture,obs4Texture,obs5Texture,game_fornt,game_overTexture,bullet1,game_fornt2;
    SoundBuffer gameSound,crashSound;


    ///Font
    style1.loadFromFile("Fonts/Font1.ttf");
    gametxt.setFont(style1);
    gametxt.setString("Car Racing!!!");
    gametxt.setCharacterSize(100);
    gametxt.setScale(1.f,1.f);
    gametxt.setFillColor(Color::Red);

    style2.loadFromFile("Fonts/Font2.ttf");
    newgametxt.setFont(style2);
    newgametxt.setString("play Game ");
    newgametxt.setCharacterSize(80);
    newgametxt.setScale(0.7f,0.7f);
    newgametxt.setFillColor(notSelected);

    helptxt.setFont(style2);
    helptxt.setString("HELP ");
    helptxt.setCharacterSize(80);
    helptxt.setScale(0.7f,0.7f);
    helptxt.setFillColor(notSelected);

    exittxt.setFont(style2);
    exittxt.setString("Exit ");
    exittxt.setCharacterSize(80);
    exittxt.setScale(0.7f,0.7f);
    exittxt.setFillColor(notSelected);

    note.setFont(style1);
    note.setString("*****Please Press E To Select****");
    note.setCharacterSize(50);
    note.setScale(0.7f,0.7f);
    note.setFillColor(Color::Green);

    helptext.setFont(style2);
    helptext.setString("Press 'up arrow' to go up.\n Press 'down arrow' to down.\n Press 'right arrow' to go right.\n Press 'left arrow' to go left. \n Press 'space' to go to main menu. \n");
    helptext.setCharacterSize(50);
    helptext.setScale(0.7f,0.7f);
    helptext.setFillColor(Color::Green);

    carX=SCREEN_WIDTH/2;
    carY=SCREEN_HEIGH-carHeight;
    Obs1X=getRandomNumber(borderLeft,borderRight);
    Obs2X=getRandomNumber(borderLeft,borderRight);
    Obs3X=getRandomNumber(borderLeft,borderRight);
    Obs4X=getRandomNumber(borderLeft,borderRight);
    Obs5X=getRandomNumber(borderLeft,borderRight);
    Obs1Y=-200,Obs2Y=-400,Obs3Y=-600,Obs4Y=-800;
    Obs5Y=-1000;



    crashSound.loadFromFile("sound/crash.wav");
    Music fgame;
    fgame.openFromFile("Sound//sound.wav");
    backgroundTexture.loadFromFile("Textures/background.png");
    game_overTexture.loadFromFile("Textures/overgame.jpg");
    carTexture.loadFromFile("Textures/obs111.png");
    obs1Texture.loadFromFile("Textures/obs1.png");
    obs2Texture.loadFromFile("Textures/obs2.png");
    obs3Texture.loadFromFile("Textures/obs3.png");
    obs4Texture.loadFromFile("Textures/obs4.png");
    obs5Texture.loadFromFile("Textures/obs5.png");
    game_fornt.loadFromFile("Textures/11.png");
    Texture coin;
    coin.loadFromFile("Textures//coin.png");
    Sprite Coin(coin);
    Coin.setScale(0.2f,0.2f);
    double coinx,coiny;
    coinx=getRandomNumber(borderLeft,borderRight);
    coiny=-500;
    Texture coin1;
    coin1.loadFromFile("Textures//coin.png");
    Sprite Coin1(coin1);
    Coin1.setScale(0.2f,0.2f);
    double coin1x,coin1y;
    coin1x=getRandomNumber(borderLeft,borderRight);
    coin1y=-500;

    Sound GameSound,menubutton;
    GameSound.setBuffer(gameSound);
    GameSound.play();
    GameSound.setLoop(true);

    ///Initial game music
    Sound CrashSound;
    CrashSound.setBuffer(crashSound);


    ///create sprite
    Sprite background1(backgroundTexture);
    Sprite background2(backgroundTexture);
    Sprite game_over(game_overTexture);
    Sprite car(carTexture);
    Sprite obs1(obs1Texture);
    Sprite obs2(obs2Texture);
    Sprite obs3(obs3Texture);
    Sprite obs4(obs4Texture);
    Sprite obs5(obs5Texture);
    Sprite game_front(game_fornt);
    Sprite game_front21(game_fornt2);

    bool menu=true,game=false,help=false, gameover=false,highscoreg=false;
    Clock   clock,cl;
    float tym;
    tym=clock.getElapsedTime().asSeconds();

    int menuselect=1,score=0,highscore,level1=1,i=1,j=0,m=7;
    fgame.play();
    fgame.setLoop(true);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==event.Closed)
            {
                window.close();
            }
        }
        if(menu)
        {


            ///GameSound.stop();

            gametxt.setPosition(40.f,3.f);
            newgametxt.setPosition(700.f,200.f);
            helptxt.setPosition(700.f,300.f);
            exittxt.setPosition(700.f,400.f);
            note.setPosition(600.f,640.f);

            window.clear();
            game_front.setScale(1.f,1.f);

            window.draw(game_front);
            window.draw(gametxt);
            window.draw(newgametxt);
            window.draw(helptxt);
            window.draw(exittxt);
            window.draw(note);
            window.display();
            time=key.getElapsedTime().asSeconds();

            if(Keyboard::isKeyPressed(Keyboard::Down) && time > 0.2)
            {
                menubutton.play();
                menuselect++;
                key.restart();
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) && time > 0.2)
            {
                menubutton.play();
                menuselect--;
                key.restart();
            }
        }
        if(menuselect%3==1)
        {
            newgametxt.setFillColor(done);
            helptxt.setFillColor(notSelected);
            exittxt.setFillColor(notSelected);

            if(Keyboard::isKeyPressed(Keyboard::L) && game==false)
            {
                level1=1,i=1,j=0,m=7,score=0;
                gameSpeed=0.4;
                game=true;
                gameover=false;
                menu=false;
                CrashSound.stop();

            }
        }

        else if(menuselect%3==2)
        {
            helptxt.setFillColor(done);
            exittxt.setFillColor(notSelected);
            newgametxt.setFillColor(notSelected);
            if(Keyboard::isKeyPressed(Keyboard::L))
            {
                help=true;
            }
        }
        else if(menuselect%3==0)
        {
            exittxt.setFillColor(done);
            newgametxt.setFillColor(notSelected);
            helptxt.setFillColor(notSelected);

            if(Keyboard::isKeyPressed(Keyboard::L) && game==false)
            {
                return 0;
            }
        }


        if(game)
        {
            if(score==0)
            {
                level1=1;
            }
            char ss[50];
            sprintf(ss,"Score:%d",score);
            Text text(ss,myfont,30);
            text.setPosition(5,0);
            text.setFillColor(sf::Color::Red);


            if(Keyboard::isKeyPressed(Keyboard::Escape) && game==true)
            {
                game=false;
                gameover=false;
                menu=true;
                CrashSound.stop();
            }

            background1.setPosition(0,BackgroundY1);
            background2.setPosition(0,BackgroundY2);
            if (BackgroundY2>0)
            {
                BackgroundY1=0;
                BackgroundY2=BackgroundY1-700;
            }
            BackgroundY1+=0.3;
            BackgroundY2+=0.3;

            ///Set car position
            car.setPosition(carX,carY);
            obs1.setPosition(Obs1X,Obs1Y);
            obs2.setPosition(Obs2X,Obs2Y);
            obs3.setPosition(Obs3X,Obs3Y);
            obs4.setPosition(Obs4X,Obs4Y);
            obs5.setPosition(Obs5X,Obs5Y);
            Coin.setPosition(coinx,coiny);
            Coin1.setPosition(coin1x,coin1y);

            if(score==0)
            {
                gameSpeed=0.6;

            }

            if(score%m==0 && score>0)
            {
                i++;
                m=m+50;
                level1=i;
            }
            if(i>j)
            {
                j=i;
                gameSpeed+=.2;
                BackgroundY1+=0.2;
                BackgroundY2+=0.2;

            }

            scoretxt.setPosition(5.0f,0.0f);
            scoretxt.setCharacterSize(20);

            ///Set Obs
            if (Obs1Y>SCREEN_HEIGH)
            {
                Obs1Y=-200;
                Obs1X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Obs1Y=Obs1Y+gameSpeed;
            }
            if (Obs2Y>SCREEN_HEIGH)
            {
                Obs2Y=-400;
                Obs2X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Obs2Y=Obs2Y+gameSpeed;
            }
            if (Obs3Y>SCREEN_HEIGH)
            {
                Obs3Y=-600;
                Obs3X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Obs3Y=Obs3Y+gameSpeed;
            }
            if (Obs4Y>SCREEN_HEIGH)
            {
                Obs4Y=-800;
                Obs4X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Obs4Y=Obs4Y+gameSpeed;
            }
            if (Obs5Y>SCREEN_HEIGH)
            {
                Obs5Y=-1000;
                Obs5X=getRandomNumber(borderLeft,borderRight);
                score++;
            }
            else
            {
                Obs5Y=Obs5Y+gameSpeed;
            }
            if (coiny>SCREEN_HEIGH)
            {
                coiny=0;
                coinx=getRandomNumber(borderLeft,borderRight);

            }
            else
            {
                coiny=coiny+gameSpeed;
            }
            if (coin1y>SCREEN_HEIGH)
            {
                coin1y=0;
                coin1x=getRandomNumber(borderLeft,borderRight);

            }
            else
            {
                coin1y=coin1y+gameSpeed;
            }

            while(window.pollEvent(event))
            {
                if(event.type==event.Closed)
                {
                    window.close();
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                if(carX>borderLeft)
                {
                    carX-=.7;
                    car.move(-15.f,0.0f);

                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Right))
            {

                if(carX<borderRight)
                {
                    carX=carX+.7;
                    car.move(15.f,0.0f);
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                if(carY>0)
                {
                    carY=carY-.5;
                    car.move(0.0f,-15.f);
                }
            }
            if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                if(carY<SCREEN_HEIGH-70)
                {
                    carY=carY+.5;
                    car.move(0.0f,15.f);
                }
            }
            ///accident happen
            if (((carX>=(Obs1X-50)) &&(carX<=(Obs1X+50)))&&((carY>=(Obs1Y-90)) &&(carY)<=(Obs1Y+90)))
            {
                fgame.stop();
                gameover=true;
                CrashSound.play();
            };
            if (((carX>=(Obs2X-50)) &&(carX<=(Obs2X+50)))&&((carY>=(Obs2Y-80)) &&(carY)<=(Obs2Y+80)))
            {
                fgame.stop();
                gameover=true;
                CrashSound.play();
            };
            if (((carX>=(Obs3X-45)) &&(carX<=(Obs3X+45)))&&((carY>=(Obs3Y-89)) &&(carY)<=(Obs3Y+80)))
            {
                fgame.stop();
                gameover=true;
                CrashSound.play();
            };
            if (((carX>=(Obs4X-50)) &&(carX<=(Obs4X+50)))&&((carY>=(Obs4Y-90)) &&(carY)<=(Obs4Y+99)))
            {
                fgame.stop();
                gameover=true;
                CrashSound.play();
            };
            if (((carX>=(Obs5X-50)) &&(carX<=(Obs5X+50)))&&((carY>=(Obs5Y-109)) &&(carY)<=(Obs5Y+109)))
            {
                fgame.stop();
                gameover=true;
                CrashSound.play();
            };


            window.clear();
            window.draw(background1);
            window.draw(background2);
            window.draw(text);
            window.draw(level1txt);
            window.draw(car);
            window.draw(obs1);
            window.draw(obs2);
            window.draw(obs3);
            window.draw(obs4);
            window.draw(obs5);
            window.draw(Coin);
            if (((carX>=(coinx-30)) &&(carX<=(coinx+30)))&&((carY>=(coiny-50)) &&(carY)<=(coiny+50)))
            {
                coinx=SCREEN_WIDTH+100;
                coiny=SCREEN_WIDTH+100;
                window.draw(Coin1);
                score+=5;
            }


            window.display();
        }
        if(gameover)
        {
            game=false;
            menu=false;

            GameSound.stop();
            char sss[50];
            sprintf(sss,"Your Score:%d",score);
            Text textt(sss,myfont,30);
            textt.setPosition(50,30);
            textt.setFillColor(sf::Color::Red);

            window.draw(game_over);
            window.draw(textt);
            window.display();

            tym=clock.getElapsedTime().asSeconds();
            if(tym>20.0f)
            {
                GameSound.play();
                menu=true;
                gameover=false;
                game=false;
                clock.restart();
                tym=0.0;

            }

            if(Keyboard::isKeyPressed(Keyboard::L))
            {
                ///Set racer and Obs position
                carX=SCREEN_WIDTH/2;
                carY=SCREEN_HEIGH-carHeight;
                Obs1X=getRandomNumber(borderLeft,borderRight);
                Obs2X=getRandomNumber(borderLeft,borderRight);
                Obs3X=getRandomNumber(borderLeft,borderRight);
                Obs4X=getRandomNumber(borderLeft,borderRight);
                Obs1Y=0,Obs2Y=-100,Obs3Y=-200,Obs4Y=-300;

                gameSpeed=0.4;
                score=0;
                menu=true;
                gameover=false;
                game=false;
                CrashSound.stop();
                fgame.play();
            }
            if(Keyboard::isKeyPressed(Keyboard::L))
            {
                gametxt.setPosition(20.f,3.f);
                newgametxt.setPosition(700.f,200.f);
                loadgametxt.setPosition(700.f,280.f);
                leveltxt.setPosition(700.f,360.f);
                helptxt.setPosition(700.f,440.f);
                exittxt.setPosition(700.f,520.f);
                note.setPosition(600.f,640.f);
                level1=1,i=1,j=0,m=7,score=0;

                gameover==false;
                game=false;
                menu=true;
                CrashSound.stop();

            }
        }
        if(help)
        {
            menu=false;
            game=false;
            helptext.setPosition(400.0f,160.0f);


            window.draw(game_front21);
            window.draw(helptext);
            window.display();
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {

                menu=true;
                help=false;
            }

        }


    }
    return 0;
}
int getRandomNumber(int a, int b)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    int result=a + rand() % (( b + 1 ) -a);
    return result;
}
