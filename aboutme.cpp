#include "aboutme.h"
#include "ui_aboutme.h"
#include<QMenu>
#include<QMenuBar>
#include "homepage.h"
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



//    QString username = ui->username->text();
//    QString email = ui->email->text();
//    QString age = ui->age->text();
//    QString contact = ui->contact->text();
//    QString gender = ui->gender->text();
//    QString address  = ui->address->text();

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");


     if (database.open())
     {


         QSqlQuery query;

         query.prepare("SELECT * FROM user_detailss");

         //WHERE username='"+username+"' AND age='"+age+"' AND email='"+email+"' AND contact='"+contact+"' AND address='"+address+"'

//         query.bindValue(":username", username);
//         query.bindValue(":age", age);
//         query.bindValue(":email", email);
//         query.bindValue(":contact", contact);
//         query.bindValue(":gender", gender);
//         query.bindValue(":address", address);

         if (!query.exec())
         {
             QMessageBox::information(this, "Failed", "Data Not found");
         }
         else{
             while(query.next())
             {
                 ui->username->setText(query.value(1).toString());
                 ui->age->setText(query.value(4).toString());
                 ui->email->setText(query.value(2).toString());
                 ui->contact->setText(query.value(5).toString());
                 ui->gender->setText(query.value(6).toString());
                 ui->address->setText(query.value(7).toString());

//                 QString usernameFromDB = query.value(1).toString();
//                 QString ageFromDB = query.value(4).toString();
//                 QString emailFromDB = query.value(2).toString();
//                 QString contactFromDB = query.value(5).toString();
//                 QString genderFromDB = query.value(6).toString();
//                 QString addressFromDB = query.value(7).toString();

             }
         }
     }else{
         QMessageBox::information(this, "Not connected", "Retry");
     }
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

