#include "about_us.h"
#include "ui_about_us.h"
#include <QMenu>
#include <QMenuBar>
#include "homepage.h"
#include "sign_in.h"
#include "registration_.h"

about_us::about_us(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about_us)
{
    ui->setupUi(this);

    this->setFixedSize(this->geometry().width(),this->geometry().height());

   ui->pushButton_5->setText("Menu");
   ui->pushButton_5->setIcon(QIcon("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/images/menu.png"));
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

   ui->pushButton_5->setMenu(menu);
}

about_us::~about_us()
{
    delete ui;
}

void about_us::on_pushButton_3_clicked()
{
    this->close();
    auto hp = new Homepage();
    hp->setAttribute(Qt::WA_DeleteOnClose);
    hp->show();
}


void about_us::on_pushButton_clicked()
{
    auto signin = new sign_in();
    signin->setAttribute(Qt::WA_DeleteOnClose);
    signin->show();
}


void about_us::on_pushButton_2_clicked()
{
    auto reg = new registration_();
    reg->setAttribute(Qt::WA_DeleteOnClose);
    reg->show();
}


void about_us::on_pushButton_7_clicked()
{
    auto reg = new registration_();
    reg->setAttribute(Qt::WA_DeleteOnClose);
    reg->show();
}

