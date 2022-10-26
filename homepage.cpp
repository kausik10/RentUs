#include "homepage.h"
#include "ui_homepage.h"
#include <QMenu>
#include<QMenuBar>



Homepage::Homepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Homepage)
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
  //  ui->pushButton_5->setStyleSheet("::menu-indicator{ image: none; }");
   // QApplication::instance()->setAttribute(Qt::AA_DontShowIconsInMenus, true);

   // QObject::connect( ui->pushButton,SIGNAL(on_pushButton_2_clicked()) , this, SLOT(Homepage::close()));

  //  QObject::connect(ui->pushButton_2, SIGNAL(click()), this, SLOT(openRegistration()));





   }

Homepage::~Homepage()
{
    delete ui;


}

void Homepage::on_pushButton_clicked()
{
    auto signin = new sign_in();
    signin->setAttribute(Qt::WA_DeleteOnClose);
    signin->show();
}


void Homepage::on_pushButton_2_clicked()
{
//    registration_ R;
    auto reg = new registration_();
       reg->setAttribute(Qt::WA_DeleteOnClose);
       reg->show();

}
//void Homepage::openRegistration(){
//    registration = new registration_();
//    registration->show();
//}




void Homepage::on_pushButton_7_clicked()
{
    auto reg = new registration_();
       reg->setAttribute(Qt::WA_DeleteOnClose);
       reg->show();

}

