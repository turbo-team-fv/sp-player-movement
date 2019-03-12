#include "State.h"

State::State()
{
    posNow.push_back(0.0),posNow.push_back(0.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    acel.push_back(0.0),acel.push_back(0.0);

}

vector<double> State::getPosBef()
{
    return posBef;
}

vector<double> State::getPosNow()
{
    return posNow;
}

vector<double> State::getAcel()
{
    return acel;
}


void State::setPosNow(double x, double y)
{
    posNow[0]=x,posNow[1]=y;
}
void State::setPosBef(double x, double y)
{
    posBef[0]=x,posBef[1]=y;
}
void State::setAcel(double ax, double ay)
{
   acel[0]=ax;
   acel[1]=ay;
}

void State::updateState(sf::Time et)
{

    posBef=posNow;
    //posNow[0] += acelX * et.asSeconds();
    //posNow[1] += acelY * et.asSeconds();
    posNow[0] += acel[0]*et.asSeconds();
    posNow[1] += acel[1]*et.asSeconds();

}

State::~State()
{
    //dtor
}
