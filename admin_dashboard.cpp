#include "admin_dashboard.h"
#include "ui_admin_dashboard.h"

admin_dashboard::admin_dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_dashboard)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &user_info);
    ui->stackedWidget->insertWidget(2, &property);

    connect(&user_info, SIGNAL(admin_DashBoardClicked()), this, SLOT(admin_DashBoard()));
    connect(&property, SIGNAL(admin_DashBoardClicked()), this, SLOT(admin_DashBoard()));


    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "mydb");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QFileInfo checkFile("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QSqlQuery query(database);
    QSqlQuery query_1(database);

    if (checkFile.isFile())
    {

        if (database.open()){
            qDebug()<<"Connected to databse";

            query.prepare("SELECT COUNT(username) FROM user_detailss");
            query_1.prepare("SELECT COUNT(user_id) FROM property_details");


            int val = 0;

                 if (!query.exec())
                 {
                     QMessageBox::information(this, "Failed", "Data Not found");
                 }
                 else{
                     while(query.next())
                     {
                          val = query.value(0).toInt();
                                  qDebug()<< val;


//                ui->count_2->setStyleSheet("QTextEdit{text-align: center;background: rgba(123,145,156,13); border-radius:5px; border: none;}");
                ui->count_2->setText(QString::number(val));
                ui->count_2->setAlignment(Qt::AlignCenter);

                     }
                }
                 if (!query_1.exec())
                 {
                     QMessageBox::information(this, "Failed", "Data Not found");
                 }
                 else{
                     while(query_1.next())
                     {
                          val = query_1.value(0).toInt();
                                  qDebug()<< val;


//                ui->count_2->setStyleSheet("QTextEdit{text-align: center;background: rgba(123,145,156,13); border-radius:5px; border: none;}");
                ui->count_3->setText(QString::number(val));
                ui->count_3->setAlignment(Qt::AlignCenter);

                     }
                }
        }

    }else{
        qDebug()<<"Database Not found";
    }

     database.close();

}

admin_dashboard::~admin_dashboard()
{
    delete ui;
}

void admin_dashboard::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void admin_dashboard::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void admin_dashboard::admin_DashBoard()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void admin_dashboard::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void admin_dashboard::on_pushButton_20_clicked()
{
        ui->stackedWidget->setCurrentIndex(2);
}

