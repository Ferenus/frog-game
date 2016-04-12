#ifndef C_PAINTER_H
#define C_PAINTER_H

#include <QImage>
#include <QBrush>
#include "c_frog.h"
#include "c_car.h"
#include <QGraphicsScene>

///
/// \brief The C_Painter class Klasa odpowiadająca za renderowanie grafiki.
///
class C_Painter
{
public:
    C_Painter();
    ///
    /// \brief rysuj Metoda odpowiadająca za rysowanie mapy gry.
    /// \param mapa Wskaźnik na mapę gry, na podstawie której będzie rysowana graficzna mapa gry.
    /// \param scena Scena, na której będzie rysowana mapa gry.
    ///
    void rysuj(C_Map *mapa, QGraphicsScene *scena);
    ///
    /// \brief rysuj Metoda odpowiadająca za rysowanie żaby na mapie gry.
    /// \param zaba Wskaźnik na żabę, na podstawie której jest rysowana graficzna żaba.
    /// \param scena Scena, na której będzie rysowana żaba
    ///
    void rysuj(C_Frog *zaba, QGraphicsScene *scena);
    ///
    /// \brief rysuj Metoda odpowiadająca za rysowanie samochodów na konkretnym pasie ruchu.
    /// \param wektor Wektor samochodów reprezentujący pas ruchu, na podstawie którego rysowane są graficzne samochody.
    /// \param scena Scena, na której rysowane są samochody.
    ///
    void rysuj(QVector<C_Car *> wektor , QGraphicsScene *scena);


private:
   int pozxP;
   int pozxL;
   QPixmap waterImage;
   QPixmap grassImage;
   QPixmap asphaltImage;
   QPixmap frogBImage;
   QPixmap carBImage;
   QPixmap carCImage;
   QBrush waterB;
   QBrush grassB;
   QBrush asphaltB;
   QBrush frogB;
   QBrush carB;
   QBrush carC;
   static const int wysokoscMapy = 600;
   static const int szerokoscMapy = 900;
};

#endif // C_PAINTER_H
