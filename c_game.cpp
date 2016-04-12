#include "c_game.h"
#include <QDebug>

C_Game::C_Game()
    :
      komorka(new C_Map),
      wskaznikZaby (new C_Frog(komorka, nic)),
      gracz(new C_player(wskaznikZaby))
{

}
C_Game::~C_Game()
{
    for (int j=0; j<this->vector1.size();j++)
        delete this->vector1[j];
    for (int j=0; j<this->vector2.size();j++)
        delete this->vector2[j];
    for (int j=0; j<this->vector3.size();j++)
        delete this->vector3[j];
    for (int j=0; j<this->vector4.size();j++)
        delete this->vector4[j];
    delete komorka;
    delete wskaznikZaby;
    delete gracz;
}
void C_Game::allVectorMoveProcess()
{
    for (int j=0; j<this->vector1.size();j++)
    {
        this->vector1[j]->move();
        this->vector1[j]->killFrog();
    }
    for (int j=0; j<this->vector2.size();j++)
       {this->vector2[j]->move();
        this->vector2[j]->killFrog();
    }
    for (int j=0; j<this->vector3.size();j++)
       {
        this->vector3[j]->move();
        this->vector3[j]->killFrog();
    }
    for (int j=0; j<this->vector4.size();j++)
       {this->vector4[j]->move();
        this->vector4[j]->killFrog();
}
    }

void C_Game::allVectorProcess()
{
    singleVectorConstProcess(this->vector1, 1);
    singleVectorConstProcess(this->vector2, 2);
    singleVectorConstProcess(this->vector3, 3);
    singleVectorConstProcess(this->vector4, 4);

    int losowyTor = (std::rand() % 4 ) + 1;

    if (losowyTor==1)
        singleVectorRandProcess(this->vector1, losowyTor);
    if (losowyTor==2)
        singleVectorRandProcess(this->vector2, losowyTor);
    if (losowyTor==3)
        singleVectorRandProcess(this->vector3, losowyTor);
    if (losowyTor==4)
        singleVectorRandProcess(this->vector4, losowyTor);

}
void C_Game::singleVectorConstProcess(QVector<C_Car *> &singleVector, int nrToru)
{

    if (singleVector.size()==0){
        singleVector.append(new C_Car(nrToru ,komorka, NULL, gracz->returnLevel(),wskaznikZaby));
    }
    if (singleVector.size()!=0)
    {
        for (int i=0; i<singleVector.size(); i++)
        {
            singleVector[i]->killFrog();
            if (((singleVector[i]->returnPosition().y)<=2)&&(singleVector[i]->returnPosition().x<-1))
            {
                if (singleVector.size()>1)
                    singleVector[i+1]->clearWskNextCar();

                delete singleVector[i];
                singleVector.removeAt(i);
                break;
            }
            if (((singleVector[i]->returnPosition().y)>2)&&(singleVector[i]->returnPosition().x>10))
            {
                if (singleVector.size()>1)
                    singleVector[i+1]->clearWskNextCar();

                delete singleVector[i];
                singleVector.removeAt(i);
                break;
            }
        }
    }
}
void C_Game::singleVectorRandProcess(QVector<C_Car *> &singleVector, int nrToru)
{

    if ((singleVector.size()==1)&&(singleVector[0]->returnKierunek() == prawo)&&
       (singleVector[0]->returnPosition().x>(this->komorka->retLiczbaKomorekPoziom()+1)/2))
            singleVector.append(new C_Car(nrToru, komorka, singleVector.at(0), gracz->returnLevel(), wskaznikZaby));
    if ((singleVector.size()==1)&&(singleVector[0]->returnKierunek() == lewo)&&
       (singleVector[0]->returnPosition().x<(this->komorka->retLiczbaKomorekPoziom()-1)/2))
            singleVector.append(new C_Car(nrToru, this->komorka, singleVector.at(0), gracz->returnLevel(), wskaznikZaby));
}
