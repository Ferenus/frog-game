#ifndef C_MAP_H
#define C_MAP_H
#include "c_cell.h"
///
/// \brief The C_Map class Klasa reprezentująca logiczną mapę gry i odpowiadająca za jej stworzenie.
///
class C_Map
{
public:
    C_Map();
    ~C_Map();
    ///
    /// \brief tworzMape Metoda powodująca utworzenie mapy gry
    ///
    void tworzMape();
    static int retLiczbaKomorekPion()
    {
        return liczbaKomorekPion;
    }
    static int retLiczbaKomorekPoziom()
    {
        return liczbaKomorekPoziom;
    }
    ///
    /// \brief mapaGry
    /// Pole klasy reprezentujące mapę gry, będącą dwuwymiarową
    /// tablicą dynamiczną zmiennych enum TypeOfCell(np. woda, trawa itp.)
    C_Cell **mapaGry;

private:

    static const int liczbaKomorekPoziom = 9;
    static const int liczbaKomorekPion = 6;
};

#endif // C_MAP_H
