#include "dashboard.h"
#include "ui_dashboard.h"
#include<QMenuBar>
#include<QMenu>
#include "homepage.h"
userpage::userpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userpage)
{
//    ui->stackedWidget->setCurrentIndex(0);
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


    ui->stackedWidget->setCurrentIndex(0);

    ui->stackedWidget->insertWidget(2, &contributions);

    ui->stackedWidget->insertWidget(3, &myinfo);

    ui->stackedWidget->insertWidget(4, &property);

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
                ui->greeting_user_2->setText(user);
                  ui->greeting_user_2->setAlignment(Qt::AlignRight);

                     }
                }
        }

    }else{
        qDebug()<<"Database Not found";
    }

     database.close();

     QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE", "dab");
     db.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
     if(db.open())
     {
         QSqlQueryModel *modal =new QSqlQueryModel();

         QSqlQuery *qry=new QSqlQuery(db);
         qry->prepare("select username, email, owner_name, contact_owner, location, property_type  from property_details WHERE username =:username");
         qry->bindValue(":username", user);
         qry->exec();
         modal->setQuery(*qry);
         modal->setHeaderData(0, Qt::Horizontal, tr ("USERNAME"));
         modal->setHeaderData(1, Qt::Horizontal, tr ("EMAIL"));
         modal->setHeaderData(2, Qt::Horizontal, tr("OWNER OF PROPERTY"));
         modal->setHeaderData(3, Qt::Horizontal, tr("CONTACT OF OWNER"));
         modal->setHeaderData(4, Qt::Horizontal, tr("ADDRESS"));
         modal->setHeaderData(5, Qt::Horizontal, tr("PROPERTY TYPE"));

         ui->greeting_user_3->setText(user);
          ui->greeting_user_3->setAlignment(Qt::AlignRight);

         ui->tableView->setModel(modal);
         ui->tableView->resizeColumnsToContents();
         for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
         {
             ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
         }


     }
     db.close();


}

userpage::~userpage()
{
    delete ui;
}

void userpage::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void userpage::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void userpage::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
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


void userpage::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->menu_btn_2->setText("Menu");
    ui->menu_btn_2->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
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

    ui->menu_btn_2->setMenu(menu);


    ui->pushButton_2->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/report.png"));
    ui->pushButton_6->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/home.png"));
    ui->pushButton_7->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/user.png"));


}


void userpage::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void userpage::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void userpage::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void userpage::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

