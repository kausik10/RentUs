#include "admin_dashboard.h"
#include "ui_admin_dashboard.h"

admin_dashboard::admin_dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_dashboard)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &user_info);
    ui->stackedWidget->insertWidget(2, &property);

    connect(&user_info, SIGNAL(admin_DashBoardClicked()), this, SLOT(admin_DashBoard()));
    connect(&property, SIGNAL(admin_DashBoardClicked()), this, SLOT(admin_DashBoard()));

}

admin_dashboard::~admin_dashboard()
{
    delete ui;
}

void admin_dashboard::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void admin_dashboard::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void admin_dashboard::admin_DashBoard()
{
    ui->stackedWidget->setCurrentIndex(0);
}
