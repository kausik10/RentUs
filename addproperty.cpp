#include "addproperty.h"
#include "ui_addproperty.h"
#include <QMenu>
#include<QMenuBar>
#include "homepage.h"
#include "registration_.h"
addproperty::addproperty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addproperty)
{
    ui->setupUi(this);
      this->setFixedSize(this->geometry().width(),this->geometry().height());
    ui->menubtn->setText("Menu");
    ui->menubtn->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
    QAction *a1 = new QAction;
    QAction *a2 = new QAction;
    QAction *a3 = new QAction;

    a1->setText("Find Home");
    a1->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/findhome.jpg"));
    a2->setText("My Home");
    a2->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/hhome.png"));
    a3->setText("Feedback");
    a3->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/feedback.jpg"));

    QMenu *menu = new QMenu;
    menu->addAction(a1);
    menu->addAction(a2);
    menu->addAction(a3);
    ui->menubtn->setMenu(menu);


    // button enabling

    connect(ui->address, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
   // connect(ui->property_type, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));

    connect(ui->owner_name, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->contact_owner, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));

}

addproperty::~addproperty()
{
    delete ui;
}



void addproperty::on_pushButton_30_clicked()
{
    emit DashBoardClicked();
}


void addproperty::on_pushButton_26_clicked()
{
    Homepage *home;
    home = new Homepage(this);
    home->show();
}


void addproperty::checkLineEdits()
{
bool ok(true);
ok = !ui->address->text().isEmpty()
            && !ui->owner_name->text().isEmpty()
            && !ui->contact_owner->text().isEmpty();

ui->addproperty_btn->setEnabled(ok);
}

void addproperty::on_addproperty_btn_clicked()
{
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE", "mydb");
     database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");


    QString username,email ;
    QString location = ui->address->text();
    QString property_type = ui->property_type->currentText();
    QString owner_name = ui->owner_name->text();
    QString contact_owner = ui->contact_owner->text();

    if(database.open())
    {
   //Retrieve Data from Input Fields


        QSqlQuery qry;
        qry.prepare("SELECT * FROM user_detailss WHERE username=:username AND email =:email") ;

        qry.prepare("INSERT INTO property_details(username, email, location, property_type, owner_name, contact_owner) VALUES('"+username+"','"+email+"',  '"+location+"', '"+property_type+"','"+owner_name+"', '"+contact_owner+"')");

        qry.bindValue(":username",qry.value(1).toString());
        qry.bindValue(":email", qry.value(2).toString());
        qry.bindValue(":location", location);
        qry.bindValue(":property_type", property_type);
        qry.bindValue(":owner_name", owner_name);
        qry.bindValue(":contacat_owner", contact_owner);


        if(qry.exec())
        {

            QMessageBox::information(this, "Inserted", "Succesfully Added");

       } else
        {
            QMessageBox::information(this, "Not Connected", "Database is Not connected");
        }
    }
    else
    {
        qDebug() << "Datavase not connected" ;
    }
    database.close();

}


void addproperty::on_addproperty_btn_2_clicked()
{
//    ui->address->text().isEmpty();
//    ui->owner_name->text().isEmpty();
//    ui->contact_owner->text().isEmpty();
   if(!ui->address->text().isEmpty() && !ui->owner_name->text().isEmpty() && !ui->contact_owner->text().isEmpty())
   {
        ui->address->clear();
        ui->owner_name->clear();
        ui->contact_owner->clear();
   }

}

