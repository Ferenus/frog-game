#include "c_map.h"


C_Map::C_Map()
{
    this->mapaGry = new C_Cell *[liczbaKomorekPion];
    for (int i=0;i<liczbaKomorekPion; i++)
    {
        this->mapaGry[i] = new C_Cell [liczbaKomorekPoziom];
    }
    tworzMape();



}

C_Map::~C_Map()
{
    for (int i=0;i<liczbaKomorekPion; i++)
    {
        delete [] this->mapaGry[i];
    }
    delete [] this->mapaGry;
}
void C_Map::tworzMape()
{
    for (int i=0; i<liczbaKomorekPion; i++)
        for (int j=0; j<liczbaKomorekPoziom; j++)
        {
            if (i==0)
                this->mapaGry[i][j].changeTypeOfCell(woda);
            if ((i>0)&&(i<(liczbaKomorekPion-1)))
                this->mapaGry[i][j].changeTypeOfCell(asfalt);
            if (i==(liczbaKomorekPion-1))
                this->mapaGry[i][j].changeTypeOfCell(trawa);
        }
}
