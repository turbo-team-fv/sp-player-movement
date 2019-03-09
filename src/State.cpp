#include "State.h"

State::State()
{
    posNow[0]=0.0,posNow[1]=0.0;
    posBef[0]=0.0,posBef[1]=0.0;
    acelX=0.0,acelY=0.0;

}

float* State::getPosBef()
{
    return posBef;
}

float* State::getPosNow()
{
    return posNow;
}

float State::getAcelX()
{
    return acelX;
}
float State::getAcelY()
{
    return acelY;
}

void State::setPosBef(float x, float y)
{
    posNow[0]=x,posNow[1]=y;
}
void State::setPosNow(float x, float y)
{
    posBef[0]=x,posBef[1]=y;
}
void State::setAcelX(float ax)
{
    acelX=ax;
}

void State::setAcelY(float ay)
{
    acelY=ay;
}

void State::updateState(sf::Time et)
{

    posBef[0] = posNow[0];
    posBef[1] = posNow[1];
    posNow[0] += acelX * et.asSeconds();
    posNow[1] += acelY * et.asSeconds();

}

State::~State()
{
    //dtor
}
