#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_register_btn_clicked()
{

    //Connecting to MySQL database
    database = QSqlDatabase::addDatabase("QMYSQL");

    database.setDatabaseName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("qt_test_register");


    if(database.open())
    {
        //Retrieve Data from Input Fields

        QString username = ui->username->text();
        QString email = ui->email->text();

        //Run Our Insert Query

        QSqlQuery qry;

        qry.prepare("INSERT INTO users(username, email)" "VALUES (:username, :email)");

        qry.bindValue(":username", username);
        qry.bindValue(":email", email);

        if(qry.exec())
        {
            QMessageBox::information(this, "Inserted", "Data Inserted Successfully");

        }else{
            QMessageBox::information(this, "Not Connected", "Data not Inserted");
        }
       } else
        {
            QMessageBox::information(this, "Not Connected", "Database is Not connected");
        }

}

