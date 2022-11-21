#include "aboutme.h"
#include "ui_aboutme.h"
#include<QMenu>
#include<QMenuBar>
#include "homepage.h"
//#include "registration_.h"
#include "sign_in.h"
//#include "globals.h"

aboutme::aboutme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutme)
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


}



aboutme::~aboutme()
{
    delete ui;
}

void aboutme::on_pushButton_23_clicked()
{
    emit DashBoardClicked();
}


void aboutme::on_pushButton_19_clicked()
{

    Homepage *home;
    home = new Homepage(this);
    home->show();
}


void aboutme::on_pushButton_5_clicked()
{
    ui->username->setReadOnly(false);
    ui->email->setReadOnly(false);
    ui->age->setReadOnly(false);
    ui->address->setReadOnly(false);
    ui->gender->setReadOnly(false);
    ui->age->setReadOnly(false);

    QString username = ui->username->text();
    QString email = ui->email->text();
    QString age = ui->age->text();
    QString contact = ui->contact->text();
    QString gender = ui->gender->text();
    QString address  = ui->address->text();

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");

     if (database.open())
     {


         QSqlQuery query;

         query.prepare("SELECT * FROM user_detailss WHERE username='"+username+"' AND age='"+age+"' AND email='"+email+"' AND contact='"+contact+"' AND address='"+address+"'");

         query.bindValue(":username", username);
         query.bindValue(":age", age);
         query.bindValue(":email", email);
         query.bindValue(":contact", contact);
         query.bindValue(":gender", gender);
         query.bindValue(":address", address);

         if (!query.exec())
         {
             QMessageBox::information(this, "Failed", "Data Not found");
         }
         else{
             while(query.next())
             {


                 QString usernameFromDB = query.value(1).toString();
                 QString ageFromDB = query.value(4).toString();
                 QString emailFromDB = query.value(2).toString();
                 QString contactFromDB = query.value(5).toString();
                 QString genderFromDB = query.value(6).toString();
                 QString addressFromDB = query.value(7).toString();

                 ui->username->setText(usernameFromDB);
                 ui->age->setText(ageFromDB);
                 ui->email->setText(emailFromDB);
                 ui->contact->setText(contactFromDB);
                 ui->gender->setText(genderFromDB);
                 ui->address->setText(addressFromDB);

             }
         }
     }else{
         QMessageBox::information(this, "Not connected", "Retry");
     }
}


void aboutme::on_pushButton_clicked()
{

         ui->username->setReadOnly(true);
         ui->email->setReadOnly(true);
         ui->age->setReadOnly(true);
         ui->address->setReadOnly(true);
         ui->gender->setReadOnly(true);
         ui->age->setReadOnly(true);
}





void aboutme::on_pushButton_7_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "mydb");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QFileInfo checkFile("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QSqlQuery query(database);

    if (checkFile.isFile())
    {

        if (database.open()){
            qDebug()<<"Connected to databse";

//            QString username = sign.Username();
           // sign_in sign;// = new sign_in();
          //  int id = sign.UserId();
            sign_in sign_;// = new sign_in();

           QString name = sign_.Username();



            query.prepare("SELECT * FROM user_detailss WHERE username = :username");
            query.bindValue(":username", name);


                 if (!query.exec())
                 {
                     QMessageBox::information(this, "Failed", "Data Not found");
                 }
                 else{
                     while(query.next())
                     {
//                         int idFromDb = query.value(0).toInt();

                         QString usernameFromDB ;
                         QString ageFromDB = query.value(4).toString();
                         QString emailFromDB = query.value(2).toString();
                         QString contactFromDB = query.value(5).toString();
                         QString genderFromDB = query.value(6).toString();
                         QString addressFromDB = query.value(7).toString();

                         ui->username->setText(usernameFromDB.append(query.value(1).toString()+""));

                         ui->age->setText(ageFromDB);
                         ui->email->setText(emailFromDB);
                         ui->contact->setText(contactFromDB);
                         ui->gender->setText(genderFromDB);
                         ui->address->setText(addressFromDB);

                     }
                }
        }

    }else{
        qDebug()<<"Database Not found";
    }

     database.close();

}

