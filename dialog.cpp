#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    gra(new C_Game()),
    scenaGlowna(new QGraphicsScene(0,0,szerokoscMapy, wysokoscMapy)),
    time(800)
{
    ui->setupUi(this);
    malarz.rysuj(gra->komorka, scenaGlowna);
    malarz.rysuj(gra->wskaznikZaby, scenaGlowna);
    ui->graphicsView->setScene(this->scenaGlowna);
    ui->graphicsView->setFixedSize(902,602);

    sceneTimer = new QTimer(this);
    sceneTimer2 = new QTimer (this);

    connect (this->sceneTimer, SIGNAL(timeout()), this, SLOT(advance()));
    connect (this->sceneTimer, SIGNAL(timeout()), this->scenaGlowna,SLOT(advance()));
    connect (this->sceneTimer2,SIGNAL(timeout()), this, SLOT(advance2()));
    connect (this->sceneTimer2,SIGNAL(timeout()), this->scenaGlowna,SLOT(advance2()));
    this->sceneTimer->start(20);
    this->sceneTimer2->start(time);
    ui->lcdNumber->display(gra->gracz->returnLevel());

}

void Dialog::keyPressEvent(QKeyEvent *k)
{
    switch (k->key()) {
        case Qt::Key_W:
            this->gra->wskaznikZaby->wysluchajRozkaz(gora);
            malarz.rysuj(gra->wskaznikZaby,scenaGlowna);
            gra->gracz->levelUp();
            this->ui->lcdNumber->display(this->gra->gracz->returnLevel());
            this->ui->lcdNumber_2->display(this->gra->wskaznikZaby->returnLifes());
            k->accept();
            break;
        case Qt::Key_S:
            this->gra->wskaznikZaby->wysluchajRozkaz(dol);
            k->accept();
            break;
        case Qt::Key_D:
            this->gra->wskaznikZaby->wysluchajRozkaz(prawo);
            k->accept();
            break;
        case Qt::Key_A:
            this->gra->wskaznikZaby->wysluchajRozkaz(lewo);
            k->accept();
            break;
        default:
            this->gra->wskaznikZaby->wysluchajRozkaz(nic);
            k->accept();
            break;
        }
}

Dialog::~Dialog()
{

    delete sceneTimer;
    delete sceneTimer2;
    delete scenaGlowna;
    delete gra;
    delete ui;
}


void Dialog::advance()
{

    gra->gracz->levelUp();
    malarz.rysuj(gra->komorka,scenaGlowna);
    gra->wskaznikZaby->move();
    malarz.rysuj(gra->wskaznikZaby,scenaGlowna);
    malarz.rysuj(gra->vector1, scenaGlowna);
    malarz.rysuj(gra->vector2, scenaGlowna);
    malarz.rysuj(gra->vector3, scenaGlowna);
    malarz.rysuj(gra->vector4, scenaGlowna);

    this->ui->lcdNumber->display(this->gra->gracz->returnLevel());
    this->ui->lcdNumber_2->display(this->gra->wskaznikZaby->returnLifes());

}
void Dialog::advance2()
{
    this->gra->allVectorProcess();
    this->gra->allVectorMoveProcess();
    if ((time - (30*(gra->gracz->returnLevel()-1)))>0)
    this->sceneTimer2->setInterval(time - (120*(gra->gracz->returnLevel()-1)));
}



