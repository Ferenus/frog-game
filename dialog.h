#ifndef DIALOG_H
#define DIALOG_H

#include <QPainter>
#include <QTimer>
#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QObject>
#include <QImage>
#include <QGraphicsScene>
#include "c_painter.h"
#include "c_game.h"

namespace Ui {

class Dialog;
}
    ///
    /// \brief The Dialog class Klasa reprezentująca okno gry, tworząca grę, będącą silnikiem gry oraz malarza,
    /// który zarządza grafiką oraz odpowiadająca za obsługę zdarzeń wywoływanych wciśnięciem klawiszy klawiatury
    ///
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    ///
    /// \brief keyPressEvent Metoda nasłuchująca i obsługująca zdarzenia wywołane z poziomu klawiatury.
    /// \param k
    ///
void keyPressEvent(QKeyEvent *k);
private:
    ///
    /// \brief scenaGlowna Scena graficzna gry.
    ///
    QGraphicsScene *scenaGlowna;
    ///
    /// \brief gra Zmienna, reprezentująca silnik gry.
    ///
    C_Game *gra;
    ///
    /// \brief time Zmienna reprezentująca interwał czasowy poruszania się samochodów
    ///
    int time;
    ///
    /// \brief sceneTimer Timer odpowiedzialny za odświeżanie grafiki.
    ///
    QTimer *sceneTimer;
    ///
    /// \brief sceneTimer2 Timer odpowiedzialny za ruch silnika gry.
    ///
    QTimer *sceneTimer2;
    Ui::Dialog *ui;
    static const int wysokoscMapy = 600;
    static const int szerokoscMapy = 900;
    ///
    /// \brief malarz Obiekt dostarczający metody do rysowania konkretnych elementów grafiki.
    ///
    C_Painter malarz;

private slots:
    ///
    /// \brief advance Metoda powodująca odświeżenie ekranu graficznego, wyzwalana sygnałem z timera.
    ///
    void advance();
    ///
    /// \brief advance2 Metoda powodująca krok silnika, wyzwalana sygnałem z timera.
    ///
    void advance2();

};

#endif // DIALOG_H
