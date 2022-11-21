#ifndef SIGN_IN_H
#define SIGN_IN_H


#include <QObject>
#include <QWidget>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>


namespace Ui {
class sign_in;
}

class sign_in : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(int UserId READ UserId WRITE setUserId NOTIFY UserIdChanged)
    Q_PROPERTY(QString Username READ Username WRITE setUsername NOTIFY UsernameChanged)


public:
    explicit sign_in(QWidget *parent = nullptr);
    ~sign_in();

    int user_id;

    int UserId() const;
    void setUserId(int newUserId);


    const QString &Username() const;
    void setUsername(const QString &newUsername);

    QString m_username;
    QString getusername();



signals:
    void UserIdChanged();

    void UsernameChanged();


private slots:
    void on_login_bt_clicked();

    void on_signin_btn_3_clicked();

//      QString validation(const QString &username, const QString &password);

//    void HomeClosed();

private:
    Ui::sign_in *ui;


    int m_UserId;

    QString m_Username;

};

#endif // SIGN_IN_H
