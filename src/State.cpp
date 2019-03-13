#include "State.h"

State::State()
{
    posNow.push_back(0.0),posNow.push_back(0.0);
    posBef.push_back(0.0),posBef.push_back(0.0);
    vel.push_back(0.0),vel.push_back(0.0);

}

vector<double> State::getPosBef()
{
    return posBef;
}

vector<double> State::getPosNow()
{
    return posNow;
}

vector<double> State::getVel()
{
    return vel;
}


void State::setPosNow(double x, double y)
{
    posNow[0]=x,posNow[1]=y;
}
void State::setPosBef(double x, double y)
{
    posBef[0]=x,posBef[1]=y;
}
void State::setVel(double ax, double ay, bool acelerado)
{

    if(acelerado)//MOTOR CON ACELERACION
    {

        vel[0]+=ax;
        vel[1]+=ay;

        if (vel[0]<=5.0&&vel[0]>=-5.0)
        {
            vel[0] = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel[0]>5.0)
                vel[0] -= 5.0;

            if(vel[0]<-5.0)
                vel[0] += 5.0;
        }

        if (vel[1]<=5.0&&vel[1]>=-5.0)
        {
            vel[1] = 0.0;
        }
        else
        {
            //decrease the speed
            if(vel[1]>5.0)
                vel[1] -= 5.0;

            if(vel[1]<-5.0)
                vel[1] += 5.0;
        }
    }
    else//MOTOR SIMPLE
    {

        vel[0]=ax;
        vel[1]=ay;
    }

}

void State::updateState(sf::Time et)
{

    posBef=posNow;
    //posNow[0] += acelX * et.asSeconds();
    //posNow[1] += acelY * et.asSeconds();

    cout<<"LETS UPDATE"<<endl;

    //if your speed is close to 0, stop


    posNow[0] += vel[0]*et.asSeconds();
    posNow[1] += vel[1]*et.asSeconds();









}

State::~State()
{
    //dtor
}
