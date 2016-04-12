#include "c_frog.h"

C_Frog::C_Frog()
{
    setStartPosition();
}

C_Frog::C_Frog(C_Map *wskaznikZabaNaMapie, OrderDirection b)
    :
     rozkaz(b),
     wins(1),
     lifes(3),
     deadFlag(true)

{
    this->wskMapaZaba = wskaznikZabaNaMapie;
    setStartPosition();
}
OrderDirection C_Frog::returnKierunek()
{
    return kierunek;
}
S_Point C_Frog::returnPosition()
{
    return position;
}

S_Point C_Frog::returnStartPosition()
{
    return startPosition;
}
void C_Frog::changePosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void C_Frog::changeDirection(OrderDirection zwrot)
{
    kierunek = zwrot;
}
void C_Frog::setStartPosition()
{
    startPosition.x = ((wskMapaZaba->retLiczbaKomorekPoziom())-1)/2;
    startPosition.y = (wskMapaZaba->retLiczbaKomorekPion())-1;
    position = startPosition;
}
void C_Frog::move()
{
    if (this->position.y==0)
    {
        setStartPosition();
        frogWin();
    }

    if ((this->rozkaz == gora)&&((position.y)>0))
    {
        (this->position.y)--;
        this->changeDirection(this->rozkaz);

    }
    if ((this->rozkaz == dol)&&((this->position.y)<((this->wskMapaZaba->retLiczbaKomorekPion())-1)))
    {
        (this->position.y)++;
        this->changeDirection(this->rozkaz);
    }
    if ((this->rozkaz == prawo)&&((this->position.x)<((this->wskMapaZaba->retLiczbaKomorekPoziom())-1)))
    {
        (this->position.x)++;
        this->changeDirection(this->rozkaz);
    }
    if ((this->rozkaz == lewo)&&((this->position.x)>0))
    {
        (this->position.x)--;
        this->changeDirection(this->rozkaz);
    }
    this->rozkaz = nic;
}
void C_Frog::wysluchajRozkaz(OrderDirection a)
{
    switch (a) {
    case gora:
        this->rozkaz = gora;
        break;
    case dol:
        this->rozkaz = dol;
        break;
    case prawo:
        this->rozkaz = prawo;
        break;
    case lewo:
        this->rozkaz = lewo;
        break;
    default:
        break;
    }
}
void C_Frog::frogWin()
{
    this->wins++;
}

int C_Frog::returnWins()
{
   return this->wins;
}
bool C_Frog::dead()
{
    bool a = false;
    if (lifes!=0)
    {
        setStartPosition();
        this->lifes--;
        a = true;
    }
    if (this->lifes==0)
    {
        this->wins = 0;
        this->lifes = 3;
    }
        return a;
}
int C_Frog::returnLifes()
{
   return this->lifes;
}
