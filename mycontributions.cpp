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

        QSqlQuery *qry=new QSqlQuery(db);
        qry->prepare("select owner_name, contact_owner, location, property_type  from property_details ORDER BY owner_name");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0, Qt::Horizontal, tr("OWNER OF PROPERTY"));
        modal->setHeaderData(1, Qt::Horizontal, tr("CONTACT OF OWNER"));
        modal->setHeaderData(2, Qt::Horizontal, tr("ADDRESS"));
        modal->setHeaderData(3, Qt::Horizontal, tr("PROPERTY TYPE"));

//        modal->setHeaderData(5, Qt::Horizontal, tr("ADDRESS"));

        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
        {
            ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        }


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

