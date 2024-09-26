#include "ambulance.h"
#include <QtDebug>
#include <QObject>
#include <QTimer>
#include <QDateTime>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>


AMBULANCE::AMBULANCE()
{
    id=0;
    matricule=" ";
    dispo=" ";
    type=" ";
    kilo=0;
}

AMBULANCE::AMBULANCE(int id,QString matricule,QString dispo,QString type,int kilo)
{
    this->id=id ;
    this->matricule=matricule ;
    this->dispo=dispo ;
    this->type=type;
    this->kilo=kilo;
}

int AMBULANCE::getid()
{
    return id;
}

QString AMBULANCE::getmatricule()
{
    return matricule;
}

QString AMBULANCE::getdispo()
{
    return dispo;
}

QString AMBULANCE::gettype()
{
    return type;
}

int AMBULANCE::getkilo()
{
    return kilo;
}

void AMBULANCE::setid(int id)
{
    this->id=id;
}

void AMBULANCE::setmatricule(QString matricule)
{
    this->matricule=matricule;
}

void AMBULANCE::setdispo(QString dispo)
{
    this->dispo=dispo;
}
void AMBULANCE::settype(QString type)
{
    this->type=type;
}

void AMBULANCE::setkilo(int kilo)
{
    this->kilo=kilo;
}



