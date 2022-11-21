#ifndef ADDPROPERTY_H
#define ADDPROPERTY_H

#include <QWidget>
#include<QtSql/QtSql>
#include<QtSql/QSqlQuery>
#include<QSqlDatabase>
#include <QMessageBox>
#include<QDebug>

namespace Ui {
class addproperty;
}

class addproperty : public QWidget
{
    Q_OBJECT

public:
    explicit addproperty(QWidget *parent = nullptr);
    ~addproperty();

private:
    Ui::addproperty *ui;
    QSqlDatabase database;

  //  void Property();
signals:
    void DashBoardClicked();


private slots:
    void on_pushButton_30_clicked();
    void on_pushButton_26_clicked();
    void on_addproperty_btn_clicked();


    void on_addproperty_btn_2_clicked();

public slots:

    void checkLineEdits();


};

#endif // ADDPROPERTY_H
