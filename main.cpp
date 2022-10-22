//#include "regsitration.h"
//#include "homepage.h"
#include "userpage.h"
#include <QApplication>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    userpage w;
    w.show();
    return a.exec();
}
