#ifndef C_PLAYER_H
#define C_PLAYER_H

#include "c_frog.h"
#include <qpainter.h>
#include <QKeyEvent>


///
/// \brief The C_player class Klasa reprezentująca gracza, którego rola ogranicza się do zdobywania poziomów.
///
class C_player
{
public:
    C_player(C_Frog *);
    int returnLevel();
    ///
    /// \brief levelUp Metoda powodująca awans gracza na wyższy poziom gry.
    ///
    void levelUp();
private:
    int poziom;
    ///
    /// \brief wskZaba Wskaźnik na żabę, dzięki któremu dowie się, że wygrał i może awansować na wyższy poziom.
    ///
    C_Frog *wskZaba;
};

#endif // C_PLAYER_H
