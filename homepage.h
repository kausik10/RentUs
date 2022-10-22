#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "regsitration.h"
#include "sign_in.h"
namespace Ui {
class Homepage;
}

class Homepage : public QWidget
{
    Q_OBJECT

public:
    explicit Homepage(QWidget *parent = nullptr);
    ~Homepage();

private slots:
     void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Homepage *ui;
      MainWindow *registration;
       sign_in *signin;
};

#endif // HOMEPAGE_H
