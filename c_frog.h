#ifndef C_FROG_H
#define C_FROG_H

#include "c_mobileobject.h"


///
/// \brief The C_Frog class Klasa reprezentująca żabę.
///
class C_Frog :public C_MobileObject
{
public:
    C_Frog();
    C_Frog(C_Map *, OrderDirection );
    S_Point returnPosition();
    ///
    /// \brief wysluchajRozkaz Metoda powodująca wysłuchanie rozkazu wydanego przez użytkownika żabie,
    /// co spowoduje wykonanie przez nią skoku.
    ///
    void wysluchajRozkaz(OrderDirection);
    ///
    /// \brief move Metoda powodująca skok żaby oraz jej wygraną gdy wskoczy do wody (co spowoduje także ustawienie jej na starcie
    /// celem rozegrania kolejnego poziomu gry.)
    ///
    void move();
    ///
    /// \brief frogWin
    ///
    void frogWin();
    ///
    /// \brief dead Metoda powodująca reinkarnację żaby w razie jej śmierci.
    /// \return Metoda zwraca wartość true, gdy po śmierci żaba ma jeszcze inne życia.
    ///
    bool dead();
    int returnWins();
    int returnLifes();
private:
    ///
    /// \brief deadFlag Flaga ustawiana na true, gdy żaba zostanie zabita przez auto.
    ///
    bool deadFlag;
    ///
    /// \brief wins Ilość wygranych żaby
    ///
    int wins;
    ///
    /// \brief lifes Ilość pozostałych żyć żaby.
    ///
    int lifes;
    ///
    /// \brief rozkaz Pole z kórego żaba nasłuchuje rozkazy.
    ///
    OrderDirection rozkaz;
    void setStartPosition();
    OrderDirection returnKierunek();


    S_Point returnStartPosition();
    void changePosition(int, int);
    void changeDirection(OrderDirection);
};

#endif // C_FROG_H
