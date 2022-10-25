#ifndef REGISTRATION__H
#define REGISTRATION__H

#include <QWidget>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>

namespace Ui {
class registration_;
}

class registration_ : public QWidget
{
    Q_OBJECT

public:
    explicit registration_(QWidget *parent = nullptr);
    ~registration_();


private slots:
    void on_register_btn_2_clicked();

    virtual void on_signin_btn_3_clicked();

    void on_signin_btn_4_clicked();

private:
    Ui::registration_ *ui;

    QSqlDatabase database;
};

#endif // REGISTRATION__H
