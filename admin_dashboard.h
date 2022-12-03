#ifndef ADMIN_DASHBOARD_H
#define ADMIN_DASHBOARD_H

#include <QWidget>
#include "user_details.h"
#include "properrty_details.h"

namespace Ui {
class admin_dashboard;
}

class admin_dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit admin_dashboard(QWidget *parent = nullptr);
    ~admin_dashboard();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void admin_DashBoard();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::admin_dashboard *ui;
    User_details user_info;
    properrty_details property;

};

#endif // ADMIN_DASHBOARD_H
