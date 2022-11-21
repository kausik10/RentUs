#include "sign_in.h"
#include "ui_sign_in.h"
//#include "homepage.h"
#include "registration_.h"
#include "dashboard.h"
#include "admin_dashboard.h"
#include "globals.h"
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
    QString username = ui->username_label->text();
    QString password = ui->password->text();

    if((username == "admin") && (password == "password" ))
    {
        this->close();
        auto admin_page = new admin_dashboard();
        admin_page->setAttribute(Qt::WA_DeleteOnClose);
        admin_page->show();
    }
    else
    {

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");


    if (database.open())
     {
         // Creaing Queries

         QSqlQuery query(QSqlDatabase::database("mydb"));

         query.prepare("SELECT * FROM user_detailss WHERE username = :username AND password = :password");

         query.bindValue(":username", username);
         query.bindValue(":password", password);

         if (!query.exec())
         {
             QMessageBox::information(this, "Failed", "Retry Login");
         }
         else{
             while(query.next())
             {
              //   int idFromDb = query.value(0).toInt();
                 QString usernameFromDB = query.value(1).toString();
                 QString passwordFromDB = query.value(3).toString();

                 if(usernameFromDB == username && passwordFromDB == password)
                 {

                     setUsername(usernameFromDB);

                     emit UsernameChanged();

                     this->close();

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
    }
}

//QString sign_in::validation(const QString &username, const QString &password)
//{

//    QSqlQuery query(QSqlDatabase::database("mydb"));
//    query.prepare(QString("SELECT * FROM user_detailss"));
//    if(!query.exec()) {
//        qDebug() << "failed to execute";
//    } else {
//        while (query.next()) {
//           // int idFromDb = query.value(0).toInt();

//            QString passwordFromDb = query.value(3).toString();
//            QString usernameFromDb = query.value(1).toString();


//            if ((username == usernameFromDb ) && (password == passwordFromDb)) { setUsername(usernameFromDb);}

//        }
//        return "fail";
//    }
//    return "fail";
//}



// Prompt to registration


void sign_in::on_signin_btn_3_clicked()
{
    this->close();
    auto reg = new registration_();
    reg->setAttribute(Qt::WA_DeleteOnClose);
    reg->show();

}// registration prompt close



int sign_in::UserId() const
{
    return m_UserId;
}

void sign_in::setUserId(int newUserId)
{

    if (m_UserId == newUserId)
    m_UserId = newUserId;
//    emit UserIdChanged();
}

//username setter

const QString &sign_in::Username() const
{
    return m_Username;
}

void sign_in::setUsername(const QString &newUsername)
{
    if (m_Username == newUsername)

    m_Username = newUsername;
    emit UsernameChanged();
}





