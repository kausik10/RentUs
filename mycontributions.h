#ifndef MYCONTRIBUTIONS_H
#define MYCONTRIBUTIONS_H

#include <QWidget>

namespace Ui {
class mycontributions;
}

class mycontributions : public QWidget
{
    Q_OBJECT

public:
    explicit mycontributions(QWidget *parent = nullptr);
    ~mycontributions();

private:
    Ui::mycontributions *ui;

signals:
      void DashBoardClicked();


private slots:
        void on_pushButton_15_clicked();




        void on_pushButton_10_clicked();
};

#endif // MYCONTRIBUTIONS_H
