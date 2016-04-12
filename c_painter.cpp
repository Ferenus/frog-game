#include "c_painter.h"
#include <QDebug>

C_Painter::C_Painter()
    :
      frogBImage(QPixmap(":/myGraphics/frog.png")),
    waterImage(QPixmap(":/myGraphics/woda.jpg")),
    grassImage(QPixmap(":/myGraphics/trawa.jpg")),
    asphaltImage(QPixmap(":/myGraphics/jezdnia.png")),
    carBImage(QPixmap(":/myGraphics/tirp.png")),
    carCImage(QPixmap(":/myGraphics/tirl.png")),
    waterB(QBrush(waterImage)),
    grassB(QBrush(grassImage)),
    asphaltB(QBrush(asphaltImage)),
    frogB(QBrush(frogBImage)),
    carB(QBrush(carBImage)),
    carC(QBrush(carCImage))
{

}
void C_Painter::rysuj(C_Map *a, QGraphicsScene *scena)
{
      for (int i = 0; i<(a->retLiczbaKomorekPion()); i++)
      {
          for (int j = 0; j<(a->retLiczbaKomorekPoziom()); j++)
          {
              if ((a->mapaGry[i][j].retTypeOfCell())==woda)
                  scena->addRect(j*100,i*100,100,100,QPen(Qt::transparent),waterB);
              if ((a->mapaGry[i][j].retTypeOfCell())==trawa)
                  scena->addRect(j*100,i*100,100,100,QPen(Qt::transparent),grassB);
              if ((a->mapaGry[i][j].retTypeOfCell())==asfalt)
                  scena->addRect(j*100,i*100,100,100,QPen(Qt::transparent),asphaltB);
          }
      }
}
void C_Painter::rysuj(C_Frog *a, QGraphicsScene *scena)
{
    scena->addRect((a->returnPosition().x)*100, (a->returnPosition().y)*100, 100,100, QPen(Qt::transparent), frogB);
}
void C_Painter::rysuj(QVector<C_Car *> vector, QGraphicsScene *scena)
{
    for (int i=0;i<vector.size();i++){
    this->pozxP = (vector.at(i)->returnPosition().x)*100;
    this->pozxL = (vector.at(i)->returnPosition().x)*100;
        if (vector.at(i)->returnKierunek()==prawo)
           scena->addRect(this->pozxP, (vector.at(i)->returnPosition().y)*100, 100, 100, QPen(Qt::transparent), carB);

        if (vector.at(i)->returnKierunek()==lewo)
           scena->addRect(this->pozxL, (vector.at(i)->returnPosition().y)*100, 100, 100, QPen(Qt::transparent), carC);


    }
}



