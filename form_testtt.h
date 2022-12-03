#ifndef FORM_TESTTT_H
#define FORM_TESTTT_H

#include <QWidget>

namespace Ui {
class Form_testtt;
}

class Form_testtt : public QWidget
{
    Q_OBJECT

public:
    explicit Form_testtt(QWidget *parent = nullptr);
    ~Form_testtt();

private:
    Ui::Form_testtt *ui;
};

#endif // FORM_TESTTT_H
