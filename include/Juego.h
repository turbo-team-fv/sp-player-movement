#ifndef JUEGO_H
#define JUEGO_H
#include "Player.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#define UPDATE_TICK_TIME 1000/5
using namespace std;


class Juego
{
    public:
    Juego(int resol_x, int resol_y, string gamename);
    void loop();
    void render(float i);//Se le pasa la interpolacion
    void updateGameState(sf::Time et);
    void handleEvents();
    void handleInputs(sf::Keyboard::Key key, bool isPressed);
    void muestraDatos();




    private:
    /**GLOBAL **/
    static const sf::Time	timePerFrame;
    /**GLOBAL **/

    sf::RenderWindow * ventana;
     sf::Text Text;
    //Material interpolacion
    sf::Clock clock;
    sf::Clock updateClock;
    sf::Time restart;
    sf::Time sinceLastUpdate; //Tiempo desde la ultima actualizacion
    sf::Time elapsedTime;
    //Material interpolacion
    Player pl;

    int evento; //1 arriba, 2 abajo, 3 izquierda, 4 derecha. 0 release
    float acelX,acelY;//aceleracion
    float interpolation;

};

#endif // JUEGO1_H
