#ifndef AMBULANCE_H
#define AMBULANCE_H
#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlQueryModel>



class AMBULANCE
{
public:
    AMBULANCE();
    AMBULANCE (int id,QString matricule,QString dispo,QString type,int kilo);

    /*getters*/
    int getid();
    QString getmatricule();
    QString getdispo();
    QString gettype();
    int getkilo();

    /*setters*/
    void setid(int);
    void setmatricule(QString);
    void setdispo(QString);
    void settype(QString);
    void setkilo(int);


    bool ajouter();
   QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();


private:
    int id,kilo;
    QString matricule, dispo, type;
};

#endif // AMBULANCE_H
