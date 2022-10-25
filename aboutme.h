#ifndef ABOUTME_H
#define ABOUTME_H

#include <QWidget>

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
};

#endif // ABOUTME_H
