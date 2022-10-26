#include "sign_in.h"
#include "ui_sign_in.h"
#include "homepage.h"
#include "registration_.h"
#include "dashboard.h"
#include <QMessageBox>
sign_in::sign_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());

    //if (ui->login_bt->click())

     //   QObject::connect(ui->login_bt ,SIGNAL(clicked(true)), this, SLOT(HomeClosed()));
}

sign_in::~sign_in()
{
    delete ui;
}


void sign_in::on_login_bt_clicked()
{

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "mydb");


//     database.setHostName("127.0.0.1");
//     database.setUserName("root");
//     database.setPassword("");
     database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/mydb.sqlite");

     QString username = ui->username_label->text();
     QString password = ui->password->text();
     if (database.open())
     {
         // Creaing Queries
       //  QMessageBox::information(this, "SUccesfully conneced", "Logged IN");

         QSqlQuery query(QSqlDatabase::database("mydb"));

         query.prepare("SELECT * FROM rent_us WHERE username = :username AND password = :password");

         query.bindValue(":username", username);
         query.bindValue(":password", password);

         if (!query.exec())
         {
             QMessageBox::information(this, "Failed", "Retry Login");
         }
         else{
             while(query.next())
             {
                 QString usernameFromDB = query.value(1).toString();
                 QString passwordFromDB = query.value(3).toString();

                 if(usernameFromDB == username && passwordFromDB == password)
                 {
                     this->close();
                     auto h = new Homepage();
                     h->setAttribute(Qt::WA_DeleteOnClose);
                     h->close();
                     auto page = new userpage();
                     page->setAttribute(Qt::WA_DeleteOnClose);
                     page->show();

                 }
                 else{
                     QMessageBox::information(this, "Failed to login", "Retry");
                 }
             }
         }
     }else{
         QMessageBox::information(this, "Not connected", "Retry");
     }

    //Homepage *h;

}


void sign_in::on_signin_btn_3_clicked()
{
    this->close();
    auto reg = new registration_();
    reg->setAttribute(Qt::WA_DeleteOnClose);
    reg->show();

}
//void sign_in::HomeClosed()
//{
//    Homepage *h;
//    h = new Homepage(this);

//    h->close();
//}
