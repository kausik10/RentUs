#ifndef PROPERRTY_DETAILS_H
#define PROPERRTY_DETAILS_H

#include <QWidget>
#include<QSqlDatabase>
#include<QDebug>
#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
namespace Ui {
class properrty_details;
}

class properrty_details : public QWidget
{
    Q_OBJECT

public:
    explicit properrty_details(QWidget *parent = nullptr);
    ~properrty_details();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();
signals:
    void admin_DashBoardClicked();
private:
    Ui::properrty_details *ui;

};

#endif // PROPERRTY_DETAILS_H
