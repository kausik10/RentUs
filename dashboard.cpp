#include "dashboard.h"
#include "ui_dashboard.h"
#include<QMenuBar>
#include<QMenu>
#include "homepage.h"
userpage::userpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userpage)
{
   // ui->stackedWidget->setCurrentIndex(0);
    ui->setupUi(this);
      this->setFixedSize(this->geometry().width(),this->geometry().height());

    ui->menu_btn->setText("Menu");
    ui->menu_btn->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
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

    ui->menu_btn->setMenu(menu);


    ui->pushButton_2->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/report.png"));
    ui->pushButton_6->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/home.png"));
    ui->pushButton_7->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/user.png"));

    //ADD USER CONDE HERE

    ui->stackedWidget->insertWidget(1, &contributions);

    ui->stackedWidget->insertWidget(2, &myinfo);

    ui->stackedWidget->insertWidget(3, &property);

    //signals slot
    connect(&contributions, SIGNAL(DashBoardClicked()), this, SLOT(Dashboard()));
    connect(&property, SIGNAL(DashBoardClicked()), this, SLOT(Dashboard()));
    connect(&myinfo, SIGNAL(DashBoardClicked()), this, SLOT(Dashboard()));

    extern QString user;

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "mydb123");
    database.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QFileInfo checkFile("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    QSqlQuery query(database);

    if (checkFile.isFile())
    {

        if (database.open()){
            qDebug()<<"Connected to databse";

            query.prepare("SELECT COUNT(username)FROM property_details WHERE username = :username");
            query.bindValue(":username", user);

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

                ui->count->setText(QString::number(val));
                ui->count->setAlignment(Qt::AlignCenter);

                     }
                }
        }

    }else{
        qDebug()<<"Database Not found";
    }

     database.close();


}

userpage::~userpage()
{
    delete ui;
}

void userpage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void userpage::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void userpage::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void userpage::Dashboard()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void userpage::on_pushButton_3_clicked()
{
    Homepage *home;
    home = new Homepage(this);
    home->show();
}



