#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "registration_.h"
#include "sign_in.h"
#include <QMainWindow>

namespace Ui {
class Homepage;
}

class Homepage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Homepage(QWidget *parent = nullptr);
    ~Homepage();

private slots:
     void on_pushButton_clicked();

    void on_pushButton_2_clicked();
//    void openRegistration();


    void on_pushButton_7_clicked();

private:
    Ui::Homepage *ui;
    registration_ *registration;
    sign_in *signin;
};

#endif // HOMEPAGE_H
