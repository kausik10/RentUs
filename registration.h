#ifndef REGISTRATION_H
#define REGISTRATION_H

#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_register_btn_clicked();
    void on_signin_btn_clicked();
    void on_signin_2_btn_clicked();
private:
    Ui::MainWindow *ui;

    QSqlDatabase database;
};
#endif // REGISTRATION_H
