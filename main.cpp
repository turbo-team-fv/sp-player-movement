#include <iostream>
#include <SFML/Graphics.hpp>
#include "Juego.h"
using namespace std;

#define kVel 5

int main(int argc, char *argv[])
{
   Juego * sp_movement = new Juego(640,480,"Space Pizza - Interpolated character movement");
    sp_movement->loop();
    return 0;
}

