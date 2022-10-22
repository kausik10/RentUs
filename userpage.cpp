#include "userpage.h"
#include "ui_userpage.h"
#include<QMenuBar>
#include<QMenu>

userpage::userpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userpage)
{
    ui->setupUi(this);
    ui->pushButton_5->setText("Menu");
    ui->pushButton_5->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
    QAction *a1 = new QAction;
    QAction *a2 = new QAction;
    QAction *a3 = new QAction;

    a1->setText("Find Home");
    a2->setText("My Home");
    a3->setText("Feedback");

    QMenu *menu = new QMenu;
    menu->addAction(a1);
    menu->addAction(a2);
    menu->addAction(a3);

    ui->pushButton_5->setMenu(menu);


     ui->pushButton->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/dashboard.png"));
      ui->pushButton_2->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/report.png"));
       ui->pushButton_6->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/home.png"));
        ui->pushButton_7->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/user.png"));


}

userpage::~userpage()
{
    delete ui;
}
