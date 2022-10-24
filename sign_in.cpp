#include "sign_in.h"
#include "ui_sign_in.h"
//#include "homepage.cpp"
sign_in::sign_in(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);

    //if (ui->login_bt->click())

}

sign_in::~sign_in()
{
    delete ui;
}

