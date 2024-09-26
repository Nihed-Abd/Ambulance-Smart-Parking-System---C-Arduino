#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include "connection.h"
#include "ambulance.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_3->setModel(A.afficher());
    ui->le_id->setValidator(new QIntValidator (0,99999999,this));
    ui->le_mat->setValidator(new QIntValidator (0,99999999,this));
    ui->le_dispo->setValidator(new QIntValidator (0,99999999,this));
    ui->le_type->setValidator(new QIntValidator (0,99999999,this));
    ui->le_kilo->setValidator(new QIntValidator (0,99999999,this));

}





void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString mat=ui->le_mat->text();
    QString dispo=ui->le_dispo->text();
    QString type=ui->le_type->text();
    int kilo=ui->le_kilo->text().toInt();

    AMBULANCE A(id, mat, dispo, type, kilo);
    bool test=A.ajouter();

    if(test)

    {
        //REFRESH
        ui->tableView_3->setModel(A.afficher());

            QMessageBox::information(nullptr,QObject::tr("Smart Printing System"),
                                 QObject::tr("Ajout effectué\n"
                                             "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);

        ui->le_id->clear();
        ui->le_mat->clear();
        ui->le_dispo->clear();
        ui->le_type->clear();
        ui->le_kilo->clear();
    }
    else
    {

            QMessageBox::critical(nullptr,QObject::tr("Smart Printing System"),
                                  QObject::tr("Ajout non effectué\n"
                                              "L'ID existe déjà\n"
                                              "Cliquez sur annuler pour quitter."),QMessageBox::Cancel);

        ui->le_id->clear();
    }
}

void MainWindow::on_pb_ajouter_2_clicked()
{
    
}
