#include "addproperty.h"
#include "ui_addproperty.h"
#include <QMenu>
#include<QMenuBar>
#include "homepage.h"

addproperty::addproperty(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addproperty)
{
    ui->setupUi(this);
      this->setFixedSize(this->geometry().width(),this->geometry().height());
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

addproperty::~addproperty()
{
    delete ui;
}



void addproperty::on_pushButton_30_clicked()
{
    emit DashBoardClicked();
}




void addproperty::on_pushButton_26_clicked()
{
    Homepage *home;
    home = new Homepage(this);
    home->show();
}

