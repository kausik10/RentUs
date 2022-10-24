#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <mycontributions.h>
#include <addproperty.h>
#include <aboutme.h>
namespace Ui {
class userpage;
}

class userpage : public QWidget
{
    Q_OBJECT

public:
    explicit userpage(QWidget *parent = nullptr);
    ~userpage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void Dashboard();
  //  void on_pushButton_34_clicked();

private:
    Ui::userpage *ui;
    mycontributions contributions;
    addproperty property;
    aboutme myinfo;
};

#endif // DASHBOARD_H
