#include "aboutme.h"
#include "dashboard.h"
#include "ui_aboutme.h"
#include<QMenu>
#include<QMenuBar>
#include "homepage.h"
//#include "edit_profile.h"

//checking for email and phone number validation
int cntNum(long long num)
{
   int n=0;
   while(num!=0)
   {
       n++;
       num=num/10;
   }
   return n;
}
bool chckCharacter(QChar charc)
{
    return ((charc >= 'A' && charc <= 'Z') || (charc >= 'a' && charc <= 'z'));
}

bool chckEmail(QString email)
{
    int m_at, m_dot;

    m_at =-1;
    m_dot =-1;

    if (!chckCharacter(email[0]))
    {
        return 0;
    }

    for (int i = 0; i < email.length(); i++) {

        if (email[i] == '@') {

            m_at = i;
        }

        else if (email[i] == '.') {

            m_dot = i;
        }
    }

    if (m_at == -1 || m_dot == -1)
        return 0;

    if (m_at > m_dot)
        return 0;

    return !(m_dot >= (email.length() - 1));
}


aboutme::aboutme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutme)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
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


    extern QString user;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "mydb");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QFileInfo checkFile("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QSqlQuery query(database);

    if (checkFile.isFile())
    {

        if (database.open()){
            qDebug()<<"Connected to databse";

            query.prepare("SELECT * FROM user_detailss WHERE username = :username");
            query.bindValue(":username", user);


                 if (!query.exec())
                 {
                     QMessageBox::information(this, "Failed", "Data Not found");
                 }
                 else{
                     while(query.next())
                     {
                         QString ageFromDB = query.value(4).toString();
                         QString emailFromDB = query.value(2).toString();
                         QString contactFromDB = query.value(5).toString();
                         QString genderFromDB = query.value(6).toString();
                         QString addressFromDB = query.value(7).toString();
//                         QString passwordFromDB = query.value(3).toString();

                         ui->username->setText(user);
                         ui->age->setText(ageFromDB);
                         ui->email->setText(emailFromDB);
                         ui->contact->setText(contactFromDB);
                         ui->gender->setText(genderFromDB);
                         ui->address->setText(addressFromDB);
//                         ui->password->setText(passwordFromDB);

                     }
                }
        }

    }else{
        qDebug()<<"Database Not found";
    }

     database.close();


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
    ui->stackedWidget->setCurrentIndex(0);

}



void aboutme::on_pushButton_6_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "conn");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");


    if (database.open())

    {

    QString username = ui->username_2->text();
    QString password_n = ui->password_n->text();
    QString password_rn = ui->password_c->text();
    QString email = ui->email_2->text();
    QString age = ui->age_2->text();
    long long contact1 = ui->contact_2->text().toLongLong();
    QString contact = ui->contact_2->text();
    QString address = ui->address_2->text();
    QString gender = ui->gender_2->text();

    QSqlQuery qry_username(database), qry_email(database), qry_contact(database);

    qry_username.prepare("SELECT * FROM user_detailss, property_details WHERE username = :username");
    qry_username.bindValue(":username", username);

    qry_email.prepare("SELECT * FROM user_detailss, property_details WHERE email = :email");
    qry_email.bindValue(":email", email);

    qry_contact.prepare("SELECT * FROM user_detailss WHERE contact = :contact");
    qry_contact.bindValue(":contact", contact);


    qry_username.exec();
    qry_email.exec();
    qry_contact.exec();
    if (password_n != password_rn)
        QMessageBox::warning(this, "Retry", "Passwords don't match");
    if(cntNum(contact1) != 10)
        QMessageBox::warning(this, "Error", "Phone Number is not correct");
    else if (qry_username.next())
        QMessageBox::warning(this, "Error", "Username is already taken");
//    else if (qry_email.next() )
//        QMessageBox::warning(this, "Error", "Email is already taken");
    else if(!chckEmail(email))
        QMessageBox::warning(this, "Error", "Invalid Email");
//    else if(qry_contact.next())
//          QMessageBox::warning(this, "Error", "Phone number exists.");
    else
    {
        extern QString user;

        QSqlQuery query(database);
        QSqlQuery query_1(database);


        query.prepare("UPDATE user_detailss SET username = :username ,email= :email, password = :password_n , age= :age, contact= :contact, gender= :gender, address= :address WHERE username= :username_");
        query.bindValue(":username", username);
        query.bindValue(":email", email);
        query.bindValue(":password_n", password_n);
        query.bindValue(":age", age);
        query.bindValue(":contact", contact);
        query.bindValue(":gender", gender);
        query.bindValue(":address", address);
        query.bindValue(":username_", user);

        query_1.prepare("UPDATE property_details SET username=:username, email=:email WHERE username=:username_");

        query_1.bindValue(":username", username);
        query_1.bindValue(":email", email);
        query_1.bindValue(":username_", user);


        if (!query.exec() || !query_1.exec())
        {
            qDebug() << query.lastError().text();
            QMessageBox::information(this, "Failed", "Data Not found");

            database.close();
        }
        else{

            QMessageBox::information(this, "Update", "Data updated successfully");
//            qDebug() << query.lastError().text();
//            this->close();
//            userpage up;
//            up.close();

            QSqlDatabase::removeDatabase("QSQLITE");
//            auto *home = new Homepage();
//            home->setAttribute(Qt::WA_DeleteOnClose);
//            home->show();
        }
    }
    }
    else{
        QMessageBox::information(this, "Not connected", "Retry");
        QSqlDatabase::removeDatabase("QSQLITE");
    }

    database.close();
}


void aboutme::on_continue_to_edit_clicked()
{
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "mydb");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QFileInfo checkFile("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QSqlQuery query(database);
    QString password_ = ui->check_password->text();
    extern QString user;

      if (checkFile.isFile())
      {

          if (database.open()){
              qDebug()<<"Connected to databse";

              query.prepare("SELECT * FROM user_detailss WHERE username = :username");

              query.bindValue(":username", user);
              query.bindValue(":password", password_);


                   if (!query.exec())
                   {
                       QMessageBox::information(this, "Failed", "Data Not found");
                   }
                   else{
                       while(query.next())
                       {

                           QString passwordFromDB = query.value(3).toString();
                            if (password_ == passwordFromDB)
                            {

                                ui->stackedWidget->setCurrentIndex(2);

                                QString ageFromDB = query.value(4).toString();
                                QString emailFromDB = query.value(2).toString();
                                QString contactFromDB = query.value(5).toString();
                                QString genderFromDB = query.value(6).toString();
                                QString addressFromDB = query.value(7).toString();

                                ui->username_2->setText(user);
                                ui->age_2->setText(ageFromDB);
                                ui->email_2->setText(emailFromDB);
                                ui->contact_2->setText(contactFromDB);
                                ui->gender_2->setText(genderFromDB);
                                ui->address_2->setText(addressFromDB);
                            }

                            else{
                                QMessageBox::warning(this, "Retry", "Password doesn't match.");
                            }

                       }
                  }
          }

      }else{
          qDebug()<<"Database Not found";
      }

       database.close();

}

