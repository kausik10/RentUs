#include "mycontributions.h"
#include "ui_mycontributions.h"
#include<QMenu>
#include<QMenuBar>

#include "homepage.h"
mycontributions::mycontributions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mycontributions)
{
    ui->setupUi(this);

      this->setFixedSize(this->geometry().width(),this->geometry().height());
    ui->pushButton_9->setText("Menu");
    ui->pushButton_9->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
    QAction *A1 = new QAction;
    QAction *A2 = new QAction;
    QAction *A3 = new QAction;

    A1->setText("Find Home");
    A1->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/findhome.jpg"));
    A2->setText("My Home");
    A2->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/hhome.png"));
    A3->setText("Feedback");
    A3->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/feedback.jpg"));

    QMenu *menu = new QMenu;
    menu->addAction(A1);
    menu->addAction(A2);
    menu->addAction(A3);
    ui->pushButton_9->setMenu(menu);



    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE", "db");
    db.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    if(db.open())
    {
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery * qry=new QSqlQuery();
        qry->prepare("select * from property_details");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
//        qDebug()<<(modal->rowCount());


    }
    db.close();


}

mycontributions::~mycontributions()
{
    delete ui;
}

void mycontributions::on_pushButton_15_clicked()
{
    emit DashBoardClicked();
}



void mycontributions::on_pushButton_10_clicked()
{
    Homepage *home;
    home = new Homepage(this);
    home->show();
}

