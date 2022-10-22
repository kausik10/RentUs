#include "regsitration.h"
#include "homepage.h"
#include "ui_mainwindow.h"
//#include "ui_homepage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_signin_2_btn_clicked()
{
    Homepage h;
    h.show();
}

void MainWindow::on_register_btn_clicked()
{

    //Connecting to MySQL database

   QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");


    database.setHostName("127.0.0.1");
    database.setUserName("root");
    database.setPassword("");
  //  database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/mydb.sqlite");

    database.setDatabaseName("qt_test_register");
    if(database.open())
    {
//        //Retrieve Data from Input Fields

        QString username = ui->username->text();
        QString email = ui->email->text();

//        //Run Our Insert Query



          QSqlQuery qry;

          qry.prepare("INSERT INTO qt_register(username, email)VALUES ('"+username+"', '"+email+"')");

           qry.bindValue(":username", username);
        qry.bindValue(":email", email);

        if(qry.exec())
        {
            QMessageBox::information(this, "Inserted", "Data Inserted Successfully");

//        }else{
       } else
        {
            QMessageBox::information(this, "Not Connected", "Database is Not connected");
        }
}

}

