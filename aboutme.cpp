#include "aboutme.h"
#include "ui_aboutme.h"
#include<QMenu>
#include<QMenuBar>
#include "homepage.h"
aboutme::aboutme(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aboutme)
{
    ui->setupUi(this);
    ui->menubtn->setText("Menu");
    ui->menubtn->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
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
    ui->menubtn->setMenu(menu);
}

aboutme::~aboutme()
{
    delete ui;
}

void aboutme::on_pushButton_23_clicked()
{
    emit DashBoardClicked();
}


void aboutme::on_pushButton_19_clicked()
{

    Homepage *home;
    home = new Homepage(this);
    home->show();
}

