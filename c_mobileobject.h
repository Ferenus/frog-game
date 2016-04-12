#ifndef C_MOBILEOBJECT_H
#define C_MOBILEOBJECT_H


#include "c_map.h"

///
/// \brief The C_MobileObject class Klasa abstrakcyjna reprezentująca obiekt mobilny.
///
class C_MobileObject
{
public:
    C_MobileObject();
    virtual ~C_MobileObject();
    ///
    /// \brief wskMapaZaba Wskaźnik obiektu mobilnego na mapę gry, zapewniający mu orientację na niej.
    ///
    C_Map *wskMapaZaba;
    virtual OrderDirection returnKierunek()=0;
    virtual S_Point returnPosition()=0;
    virtual S_Point returnStartPosition()=0;
    virtual void changePosition(int, int)=0;
    virtual void changeDirection(OrderDirection)=0;
    virtual void setStartPosition()=0;
    virtual void move()=0;
protected:
    ///
    /// \brief position Pozycja obiektu ruchomego na mapie
    ///
    S_Point position;
    ///
    /// \brief kierunek Kierunek, w jakim ma zamiar poruszyć się obiekt ruchomy.
    ///
    OrderDirection kierunek;
    ///
    /// \brief startPosition Domyślna pozycja startowa obiektu zaraz po jego stworzeniu.
    ///
    S_Point startPosition;

};

#endif // C_MOBILEOBJECT_H
