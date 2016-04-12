#ifndef C_GAME_H
#define C_GAME_H

#include "c_car.h"
#include "c_frog.h"
#include "c_player.h"

///
/// \brief The C_Game class Klasa reprezentująca logikę gry. Odpowiada za ciągłość ruchu samochodów oraz rejestrację momentu śmierci żaby.
/// Tworzy mapę gry, powołuje do życia żabę oraz gracza.
///
class C_Game
{
public:
    C_Game();
virtual ~C_Game();
    ///
    /// \brief komorka Wskaźnik na mapę gry.
    ///
    C_Map *komorka;
    ///
    /// \brief wskaznikZaby Wskaźnik na żabę.
    ///
    C_Frog *wskaznikZaby;
    ///
    /// \brief gracz Wskaźnik na gracza.
    ///
    C_player *gracz;
    ///
    /// \brief vector1 Wektor zawierający wszystkie samochody (ich wskaźniki) obecne na pierwszym pasie ruchu.
    ///
    QVector<C_Car*> vector1;
    ///
    /// \brief vector2 Wektor zawierający wszystkie samochody (ich wskaźniki) obecne na drugim pasie ruchu
    ///
    QVector<C_Car*> vector2;
    ///
    /// \brief vector3 Wektor zawierający wszystkie samochody (ich wskaźniki) obecne na trzecim pasie ruchu.
    ///
    QVector<C_Car*> vector3;
    ///
    /// \brief vector4 Wektor zawierający wszystkie samochody (ich wskaźniki) obecne na czwartym pasie ruchu.
    ///
    QVector<C_Car*> vector4;
    ///
    /// \brief allVectorMoveProcess Metoda wprawiająca w ruch wszystkie samochody na wszystkich pasach ruchu oraz wywołująca na ich rzecz metodę
    /// killFrog(), celem natychmiastowego sprawdzenia czy ruch nie spowodował uśmiercenia żaby.
    ///
    void allVectorMoveProcess();
    ///
    /// \brief allVectorProcess Metoda wywołująca kolejno metodę singleVectorConstProcess na rzecz każdego pasa ruchu oraz jednokrotnie metody
    /// singleVectorRandProcess na rzecz losowo wybranego pasa ruchu
    ///
    void allVectorProcess();


private:
    ///
    /// \brief singleVectorConstProcess Metoda zapewniająca minimalny ruch na konkretnym pasie jezdni. Tworzy samochód, gdy pas jest pusty.
    /// oraz usuwa go gdy przekroczy on mapę gry i przestaje być widoczny na ekranie. Ponadto dla każdego z samochodów na danym pasie ruchu
    /// sprawdza czy nie zabił on żaby.
    /// \param vect Parametr reprezentujący konkretny wektor (pas ruchu) zawierający samochody.
    /// \param a Parametr określający numer toru, który ma obsłużyć metoda.
    ///
    void singleVectorConstProcess(QVector<C_Car * >&vect, int a);
    ///
    /// \brief singleVectorRandProcess Metoda powodująca dodanie kolejnego samochodu na pasie ruchu, na rzecz którego zostaje wywołana.
    /// \param vect Parametr reprezentujący konkretny wektor (pas ruchu) zawierający samochody.
    /// \param a Parametr określający numer toru, który ma obsłużyć metoda.
    ///
    void singleVectorRandProcess(QVector<C_Car *>&vect , int a);
};

#endif // C_GAME_H
