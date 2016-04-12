#include "c_player.h"

C_player::C_player(C_Frog * wskazZaba)
    :
      wskZaba(wskazZaba)

{
    poziom = wskZaba->returnWins();
}


int C_player::returnLevel()
{
    return this->poziom;
}
void C_player::levelUp()
{
    if (wskZaba->returnWins()!=poziom)
        this->poziom = wskZaba->returnWins();
}


