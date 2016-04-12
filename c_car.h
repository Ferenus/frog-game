#ifndef C_CAR_H
#define C_CAR_H

#include "c_frog.h"
#include <iostream>

///
/// \brief The C_Car class Klasa dziedzicząca po C_MobileObject. Reprezentuje samochód.
///
class C_Car : public C_MobileObject



{
public:
    C_Car(int , C_Map *, C_Car *, int, C_Frog * );

    C_Car(C_Map *, C_Car *, int);

    OrderDirection returnKierunek();
    S_Point returnPosition();
    S_Point returnStartPosition();
    void changePosition(int, int);
    void changeDirection(OrderDirection);
    void setStartPosition();
    ///
    /// \brief move Metoda powodująca ruch samochodu. Jej dokładne zachowanie zależne jest od obecnego poziomu gry.
    ///
    void move();
    ///
    /// \brief killFrog Metoda powodująca na odebranie jednego z żyć żabie (wywołanie przez żabę metody dead()) i w związku z tym
    /// jej ustawienie się na pozycji startowej.
    ///
    void killFrog();
    ///
    /// \brief clearWskNextCar Metoda wspomagająca orientację auta na inne znajdujące się przed nim.
    ///
    void clearWskNextCar();

    /// Wskaźnik na żabę zapewniający kierowcy auta wiedzę, gdzie się ona znajduje, dzięki czemu jest on w stanie ją zabić.
    C_Frog *wskFrog;


private:
    ///
    /// \brief wskNextCar Wskaźnik na samochód który ewentualnie może znajdować się przez danym samochodem.
    ///
    C_Car *wskNextCar;
    ///
    /// \brief numerToru Numer pasa ruchu po jakim ma poruszać się auto.
    ///
    int numerToru;
    ///
    /// \brief velocity Prędkość z jaką może poruszać się samochód, wysoce zależna od poziomu gry
    ///
    int velocity;
};

#endif // C_CAR_H
