#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::seconds(1.f/1.f);
/** GLOBAL **/

Juego::Juego(int resol_x, int resol_y, string gamename)
{

    ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    ventana->setFramerateLimit(60);
    ventana->setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos
    evento=0;//Release

}
void Juego::loop()
{


    //clock=clock;
    sinceLastUpdate=sf::Time::Zero;
    elapsedTime = clock.restart();

    while (ventana->isOpen())
    {
        elapsedTime=clock.getElapsedTime();
        sinceLastUpdate += elapsedTime;
            //Actualizamos variables de tiempo


        //Proceso mis eventos
        handleEvents();
        cout<<"Elapsed time: ";
        cout<<elapsedTime.asMicroseconds()<<endl;
        while (sinceLastUpdate > timePerFrame)  //Cuando llegue el momento de hacer update se hace
        {
         elapsedTime = clock.restart();//el reloj se reinicia aqui aqui

            cout<<"Time to update"<<endl;
            sinceLastUpdate-=timePerFrame;

            updateGameState(sinceLastUpdate);
        }
        //Se calcula el porcentaje de interpolacion
        interpolation = (float)std::min(1.f, sinceLastUpdate.asSeconds() / timePerFrame.asSeconds());
        render(interpolation);

        void muestraDatos();



    }

}

void Juego::muestraDatos()
{

    sf::Font MyFont;

// Load from a font file on disk

    if (!MyFont.loadFromFile("resources/Lato-Regular.ttf"))
    {
        // Error...
    }


    Text.setFont(MyFont);
    Text.setString("Hello Bitch");
    Text.setColor(sf::Color(250, 250, 250));
    Text.setRotation(90.f);
    Text.setScale(1.f, 1.f);
    Text.move(240.f, 200.f);
   ventana->draw(Text);
}

void Juego::handleEvents()
{

    sf::Event event;
    while (ventana->pollEvent(event))
    {
        cout<<"Polling event"<<endl;

        switch (event.type)
        {
        case sf::Event::KeyPressed:
            cout<<"Key pressed"<<endl;
            handleInputs(event.key.code, true);
            break;

        case sf::Event::KeyReleased:
            handleInputs(event.key.code, false);
            break;

        case sf::Event::Closed:
            ventana->close();
            break;
        }
    }

}

void Juego::handleInputs(sf::Keyboard::Key key, bool isPressed)
{

if(isPressed){

    switch (key)
    {
    case sf::Keyboard::Up :
        evento=1;
        break;
    case sf::Keyboard::Down :
        evento=2;
        break;
    case sf::Keyboard::Left :
        evento=3;
        break;
    case sf::Keyboard::Right :
        evento=4;
        break;


    }
    }else{
    evento=0;
    }

}

void Juego::updateGameState(sf::Time t)
{
    float xm=0,ym=0;

    /*if(evento==4)
    {
        if(acelX<5&&acelX>(-5))
            acelX+=1;

        xm+=acelX;
        ym=0;
        pl.setDir(ym);
    }
    if(evento==3)
    {
        if(acelX<5&&acelX>(-5))
            acelX-=1;

        xm+=acelX;
        ym=0;
        pl.setDir(1);
    }
    if(evento==1)
    {
        if(acelY<5&&acelY>(-5))
        {
            acelY-=1;
            cout<<"Biiitch"<<endl;
        }


        xm=0;
        ym+=acelY;
        pl.setDir(2);
    }
    if(evento==2)
    {
        if(acelY<5&&acelY>(-5))
            acelY+=1;

        xm=0;
        ym+=acelY;
        pl.setDir(3);
    }


    if (((acelY)>-0.25&&(acelY)<0.25) && ((acelX)>-0.25&&(acelX)<0.25) )
    {
        acelY = 0,acelX=0;
    }
    else
    {
        //decrease the speed
        if(acelX>0)
            acelX -= 0.1f;

        if(acelX<0)
            acelX +=0.1;

        if(acelY>0)
            acelY -= 0.1f;

        if(acelY<0)
            acelY +=0.1;
        //acelY -= 0
        //acelY -= 0.1f;
        //pl.movePlayer(xm+acelX,ym+acelY);


    }*/

    if(evento==4)
    {


        xm+=10;
        ym=0;
        pl.setDir(ym);
    }
    if(evento==3)
    {

        xm-=10;
        ym=0;
        pl.setDir(1);
    }
    if(evento==1)
    {


        xm=0;
        ym-=10;
        pl.setDir(2);
    }
    if(evento==2)
    {
        xm=0;
        ym+=10;
        pl.setDir(3);
    }//pl.updatePlayer(xm+acelX,ym+acelY,t);
    pl.updatePlayer(xm,ym,t);
    // pl.movePlayer(0,0);





}

void Juego::render(float i)
{
    ventana->clear();
    pl.drawPlayer(*ventana,i);
    //ventana->draw(pl.getSprite());
    ventana->display();
}




