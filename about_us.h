#ifndef ABOUT_US_H
#define ABOUT_US_H

#include <QWidget>

namespace Ui {
class about_us;
}

class about_us : public QWidget
{
    Q_OBJECT

public:
    explicit about_us(QWidget *parent = nullptr);
    ~about_us();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::about_us *ui;
};

#endif // ABOUT_US_H
