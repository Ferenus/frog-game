#include "c_car.h"
#include <QDebug>

C_Car::C_Car(int nrToru, C_Map *wskaznikNaMape, C_Car *wskCar, int poziom, C_Frog *wskaznikNaZabe)
    :
      numerToru(nrToru),
      wskNextCar(wskCar),
      velocity(poziom)
{
      this->wskFrog = wskaznikNaZabe;
      this->wskMapaZaba = wskaznikNaMape;
      this->setStartPosition();
}
C_Car::C_Car(C_Map *wskaznikNaMape, C_Car *wskCar, int poziom)
    :
        numerToru((std::rand() % 4 ) + 1),
        wskNextCar(wskCar),
        velocity(poziom)

{
    this->wskMapaZaba = wskaznikNaMape;
    setStartPosition();
}
void C_Car::setStartPosition()
{
    this->position.y=numerToru;
    switch (numerToru)
    {
    case 1:
        this->position.x=8;
        this->kierunek=lewo;
        break;
    case 2:
        this->position.x=8;
        this->kierunek=lewo;
        break;
    case 3:
        this->position.x=0;
        this->kierunek=prawo;
        break;
    case 4:
        this->position.x=0;
        this->kierunek=prawo;
        break;
    default:
        break;
    }
}
OrderDirection C_Car::returnKierunek()
{
    return this->kierunek;
}

S_Point C_Car::returnStartPosition()
{
    return this->startPosition;
}

S_Point C_Car::returnPosition()
{
return this->position;
}
void C_Car::changeDirection(OrderDirection)
{

}
void C_Car::changePosition(int, int)
{

}
void C_Car::move()
{

    int los = (std::rand() % 9 );
    if ((this->wskNextCar==NULL)&&(this->kierunek==prawo))
    {
        this->position.x++;

        if (this->velocity>5) this->position.x++;
        killFrog();
        if (los < this->velocity) this->position.x++;

    }
    if ((this->wskNextCar==NULL)&&(this->kierunek==lewo))
    {
        this->position.x--;
        if (this->velocity>5) this->position.x--;
        killFrog();
        if (los < this->velocity) this->position.x--;
    }
    if ((this->wskNextCar!=NULL)&&(this->kierunek==prawo))
    {
        this->position.x++;
        if (this->velocity>5) this->position.x++;
    }
    if ((this->wskNextCar!=NULL)&&(this->kierunek==lewo))
    {
        this->position.x--;
        if (this->velocity>5) this->position.x--;
    }
}
void C_Car::clearWskNextCar()
{
    this->wskNextCar = NULL;
}
void C_Car::killFrog()
{
    if ((this->wskFrog->returnPosition().x==this->returnPosition().x)&&(this->wskFrog->returnPosition().y==this->returnPosition().y))
        wskFrog->dead();
}
