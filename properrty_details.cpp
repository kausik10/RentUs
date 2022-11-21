#include "properrty_details.h"
#include "ui_properrty_details.h"


properrty_details::properrty_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::properrty_details)
{
    ui->setupUi(this);
  //  ui->stackedWidget->setCurrentIndex(2);

    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    if(db.open())
    {
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery * qry=new QSqlQuery();
        qry->prepare("select * from user_detailss, property_details");//WHERE username = :username AND email = :email");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        qDebug()<<(modal->rowCount());
    }
}

properrty_details::~properrty_details()
{
    delete ui;
}

void properrty_details::on_pushButton_7_clicked()
{
    emit admin_DashBoardClicked();
}


void properrty_details::on_pushButton_2_clicked()
{
   // ui->stackedWidget->setCurrentIndex(1);
}

