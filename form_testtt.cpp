#include "form_testtt.h"
#include "ui_form_testtt.h"

Form_testtt::Form_testtt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_testtt)
{
    ui->setupUi(this);
}

Form_testtt::~Form_testtt()
{
    delete ui;
}
