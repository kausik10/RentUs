#include "registration_.h"
#include "ui_registration_.h"

#include "homepage.h"
#include "sign_in.h"


//checking for email and phone number validation
int countNum(long long num)
{
   int n=0;
   while(num!=0)
   {
       n++;
       num=num/10;
   }
   return n;
}
bool checkCharacter(QChar charc)
{
    return ((charc >= 'A' && charc <= 'Z') || (charc >= 'a' && charc <= 'z'));
}

bool checkEmail(QString email)
{
    int m_at, m_dot;

    m_at =-1;
    m_dot =-1;

    if (!checkCharacter(email[0]))
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



// beginning of constructors
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

    //Connecting to SQL database
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE", "mydb");
     database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");


    if (ui->username_2->text().isEmpty() || ui->address->text().isEmpty() || ui->password_->text().isEmpty() || ui->contact->text().isEmpty() || ui->email_2->text().isEmpty() || ui->age->text().isEmpty())
    {
        QMessageBox::warning(this, "Empty", "One or more fields empty");

    }

    else
    {
        if (database.open())

        {
            QString username = ui->username_2->text();
            QString email = ui->email_2->text();

            QString password = ui->password_->text();

            QString age = ui->age->text();
            long long contact1 = ui->contact->text().toLongLong();
            QString contact = ui->contact->text();
            QString gender = ui->comboBox->currentText();
            QString address  = ui->address->text();

    //        //Run Our Insert Query

              QSqlQuery qry_username(database), qry_email(database), qry_contact(database);

              qry_username.prepare("SELECT * FROM user_detailss WHERE username = :username");
              qry_username.bindValue(":username", username);

              qry_email.prepare("SELECT * FROM user_detailss WHERE email = :email");
              qry_email.bindValue(":email", email);

              qry_contact.prepare("SELECT * FROM user_detailss WHERE contact = :contact");
              qry_contact.bindValue(":contact", contact);


              qry_username.exec();
              qry_email.exec();
              qry_contact.exec();

              if(countNum(contact1) != 10)
                  QMessageBox::warning(this, "Error", "Phone Number is not correct");
              else if (qry_username.next())
                  QMessageBox::warning(this, "Error", "Username is already taken");
              else if (qry_email.next())
                  QMessageBox::warning(this, "Error", "Email is already taken");
              else if(!checkEmail(email))
                  QMessageBox::warning(this, "Error", "Invalid Email");
              else if(qry_contact.next())
                    QMessageBox::warning(this, "Error", "Phone number exists.");
              else
              {

                  QSqlQuery qry(database);

                  qry.prepare("INSERT INTO user_detailss(username, email, password, age, contact, gender, address)"
                              "VALUES"
                              "('"+username+"', '"+email+"','"+password+"', '"+age+"', '"+contact+"', '"+gender+"', '"+address+"')");

                qry.bindValue(":username", username);
                qry.bindValue(":email", email);
                qry.bindValue(":password", password);
                qry.bindValue(":age", age);
                qry.bindValue(":contact", contact);
                qry.bindValue(":gender", gender);
                qry.bindValue(":address",address);

                if(qry.exec())
                {
                    this->close();
                    QMessageBox::information(this, "Inserted", "Succesfully Registered. Proceed to Login");
                    QSqlDatabase::removeDatabase("QSQLITE");

               }
                else
                {
                    QMessageBox::information(this, "Not Connected", "Database is Not connected");
                }
                }

            }

}
    database.close();

}
