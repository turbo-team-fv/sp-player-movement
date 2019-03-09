#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace std;

/** GLOBAL **/
const sf::Time Juego::timePerFrame = sf::seconds(1.f/15.f);
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

    while (ventana->isOpen())
    {
       elapsedTime = clock.restart();     //Actualizamos variables de tiempo
		sinceLastUpdate += elapsedTime;

        //Proceso mis eventos
        handleEvents();
        cout<<"Elapsed time: ";
        cout<<elapsedTime.asMicroseconds()<<endl;
       while (sinceLastUpdate > timePerFrame){ //Cuando llegue el momento de hacer update se hace

            cout<<"Time to update"<<endl;
            sinceLastUpdate-=timePerFrame;

            updateGameState(timePerFrame);
        }
        //Se calcula el porcentaje de interpolacion
        interpolation = (float)std::min(1.f, sinceLastUpdate.asSeconds() / timePerFrame.asSeconds());
        render(interpolation);

    }

}

void Juego::handleEvents(){

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


    switch (key){
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

}

void Juego::updateGameState(sf::Time tpf)
{
    float xm=0,ym=0;

    if(evento==4)
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
        if(acelY<5&&acelY>(-5)){
        acelY-=1;
        cout<<"Biiitch"<<endl;}


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
        pl.movePlayer(xm+acelX,ym+acelY);

    }

    // pl.movePlayer(0,0);





}

void Juego::render(float i)
{
    ventana->clear();
    ventana->draw(pl.getSprite());
    ventana->display();
}




