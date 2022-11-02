#ifndef USER_DETAILS_H
#define USER_DETAILS_H

#include <QWidget>
#include<QSqlDatabase>
#include<QDebug>
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>



namespace Ui {
class User_details;
}

class User_details : public QWidget
{
    Q_OBJECT

public:
    explicit User_details(QWidget *parent = nullptr);
    ~User_details();
signals:
    void admin_DashBoardClicked();
private slots:
    void on_pushButton_7_clicked();



private:
    Ui::User_details *ui;

};

#endif // USER_DETAILS_H
