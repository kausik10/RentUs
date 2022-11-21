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
    QSqlDatabase database=QSqlDatabase::addDatabase("QSQLITE");
     database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");

    if (ui->username_2->text().isEmpty() || ui->address->text().isEmpty() || ui->password_->text().isEmpty() || ui->contact->text().isEmpty() || ui->email_2->text().isEmpty() || ui->age->text().isEmpty())
    {
        QMessageBox::warning(this, "Empty", "One or more fields empty");

    }

    else
    {
        database.open();
   //Retrieve Data from Input Fields

        QString username = ui->username_2->text();
        QString email = ui->email_2->text();
        QString password = ui->password_->text();
        QString age = ui->age->text();
        QString contact = ui->contact->text();
        QString gender = ui->comboBox->currentText();
        QString address  = ui->address->text();

//        //Run Our Insert Query

          QSqlQuery qry;

          qry.prepare("INSERT INTO user_detailss(username, email, password, age, contact, gender, address)"
                      "VALUES "
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

       } else
        {
            QMessageBox::information(this, "Not Connected", "Database is Not connected");
        }
}
    database.close();

}
