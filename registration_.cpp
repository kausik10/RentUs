#include "registration_.h"
#include "ui_registration_.h"

#include "homepage.h"
#include "sign_in.h"

registration_::registration_(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registration_)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
}

registration_::~registration_()
{
    delete ui;
}


void registration_::on_signin_btn_3_clicked()
{
    this->close();
    sign_in  *signin = new sign_in();
   /* signin->setAttribute(Qt::WA_DeleteOnClose)*/;
    signin->show();
}


void registration_::on_signin_btn_4_clicked()
{
    this->close();
    Homepage *home;
    home = new Homepage(this);
    home->setAttribute(Qt::WA_DeleteOnClose);
    home->show();
}


void registration_::on_register_btn_2_clicked()
{

    //Connecting to MySQL database

   QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");


//    database.setHostName("127.0.0.1");
//    database.setUserName("root");
//    database.setPassword("");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/mydb.sqlite");

    //database.setDatabaseName("qt_test_register");
    if(database.open())
    {
//        //Retrieve Data from Input Fields

        QString username = ui->username_2->text();
        QString email = ui->email_2->text();
        QString password = ui->password_->text();

//        //Run Our Insert Query

          QSqlQuery qry;

          qry.prepare("INSERT INTO rent_us(username, email, password)VALUES ('"+username+"', '"+email+"','"+password+"')");

        qry.bindValue(":username", username);
        qry.bindValue(":email", email);
        qry.bindValue(":password", password);

        if(qry.exec())
        {
            QMessageBox::information(this, "Inserted", "Succesfully Registered. Proceed to Login");

       } else
        {
            QMessageBox::information(this, "Not Connected", "Database is Not connected");
        }
}

}