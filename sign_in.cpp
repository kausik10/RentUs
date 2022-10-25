#include "sign_in.h"
#include "ui_sign_in.h"
#include "homepage.h"
#include "registration_.h"
#include "dashboard.h"
sign_in::sign_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);

    //if (ui->login_bt->click())

     //   QObject::connect(ui->login_bt ,SIGNAL(clicked(true)), this, SLOT(HomeClosed()));
}

sign_in::~sign_in()
{
    delete ui;
}


void sign_in::on_login_bt_clicked()
{
    this->close();
    auto h = new Homepage();
    h->setAttribute(Qt::WA_DeleteOnClose);
    h->close();
    auto page = new userpage();
    page->setAttribute(Qt::WA_DeleteOnClose);
    page->show();

    //Homepage *h;

}


void sign_in::on_signin_btn_3_clicked()
{
    this->close();
    auto reg = new registration_();
    reg->setAttribute(Qt::WA_DeleteOnClose);
    reg->show();

}
//void sign_in::HomeClosed()
//{
//    Homepage *h;
//    h = new Homepage(this);

//    h->close();
//}
