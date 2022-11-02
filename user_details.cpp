#include "user_details.h"
#include "ui_user_details.h"


User_details::User_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_details)
{
   // ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(1, &property);
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    if(db.open())
    {
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery * qry=new QSqlQuery();
        qry->prepare("select * from user_detailss");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug()<<(modal->rowCount());
    }
}

User_details::~User_details()
{
    delete ui;
}

void User_details::on_pushButton_7_clicked()
{
    emit admin_DashBoardClicked();
}




