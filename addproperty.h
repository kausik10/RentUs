#ifndef ADDPROPERTY_H
#define ADDPROPERTY_H

#include <QWidget>

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


  //  void Property();
signals:
    void DashBoardClicked();

private slots:
    void on_pushButton_30_clicked();


    void on_pushButton_26_clicked();
};

#endif // ADDPROPERTY_H
