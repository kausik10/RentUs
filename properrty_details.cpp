#include "properrty_details.h"
#include "ui_properrty_details.h"


properrty_details::properrty_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::properrty_details)
{
    ui->setupUi(this);
  //  ui->stackedWidget->setCurrentIndex(2);
}

properrty_details::~properrty_details()
{
    delete ui;
}

void properrty_details::on_pushButton_7_clicked()
{
    emit admin_DashBoardClicked();
}


void properrty_details::on_pushButton_2_clicked()
{
   // ui->stackedWidget->setCurrentIndex(1);
}
