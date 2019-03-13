#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::milliseconds(1000.0/25.0);
/** GLOBAL **/

Juego::Juego(int resol_x, int resol_y, string gamename)
{

    ventana= new sf::RenderWindow(sf::VideoMode(resol_x,resol_y),gamename);
    //ventana->setFramerateLimit(0);
    ventana->setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos
    evento=0;//Release
    eUp=false;
    eDown=false;
    eLeft=false;
    eRight=false;

}
void Juego::loop()
{

    while (ventana->isOpen())
    {

        //Actualizamos variables de tiempo
        //Proceso mis eventos

        handleEvents();
        /*cout<<"Elapsed time: ";
        cout<<updateClock.getElapsedTime().asMilliseconds()<<endl;
        cout<<"Update tick: ";
        cout<<timePerFrame.asMilliseconds()<<endl;*/

        if(updateClock.getElapsedTime().asMilliseconds()>timePerFrame.asMilliseconds())
        {
//         elapsedTime = clock.restart();//el reloj se reinicia aqui aqui
            elapsedTime=updateClock.restart();
            /*cout<<"Time to update"<<endl;*/
            updateGameState(elapsedTime);
        }

        //Se calcula el porcentaje de interpolacion
        interpolation = std::min(1.0,(double)updateClock.getElapsedTime().asMilliseconds() / (double)timePerFrame.asMilliseconds());

        /*cout<<"Interpolacion: ";
        cout<<interpolation<<endl;*/
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
    if (ventana->pollEvent(event))
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

    if (key == sf::Keyboard::Up)            //Traslaciones
		eUp = isPressed;
	else if (key == sf::Keyboard::Down)
		eDown = isPressed;
	else if (key == sf::Keyboard::Left)
		eLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		eRight = isPressed;

}

void Juego::updateGameState(sf::Time t)
{

    double velx=0,vely=0;

    if(eRight)
    {
        /*pl.increaseVelo(15.0,0.0);
        pl.setDir(0);*/
        velx=15.0;
        vely=0.0;
    }
    if(eLeft)
    {
        velx=-15.0;
        vely=0.0;
    }
    if(eUp)
    {
        velx=0.0;
        vely=-15.0;
    }
    if(eDown)
    {
        velx=0.0;
        vely=15.0;

    }


    //pl.updatePlayer(pl.getVelo()[0],pl.getVelo()[1],t);
    pl.updatePlayer(velx,vely,t);

}

void Juego::render(double i)
{
    ventana->clear();
    pl.drawPlayer(*ventana,i);
    //ventana->draw(pl.getSprite());
    ventana->display();
}




