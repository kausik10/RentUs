#ifndef ABOUTME_H
#define ABOUTME_H
//#include "sign_in.h"
#include <QWidget>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QMessageBox>
#include<QDebug>
//#include "globals.h"
namespace Ui {
class aboutme;
}

class aboutme : public QWidget
{
    Q_OBJECT

public:
    explicit aboutme(QWidget *parent = nullptr);
    ~aboutme();

private:
    Ui::aboutme *ui;

signals:
    void DashBoardClicked();
    void MyContributions();
    void AddPropertyClicked();
private slots:
    void on_pushButton_23_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();
    void on_continue_to_edit_clicked();
};

#endif // ABOUTME_H
