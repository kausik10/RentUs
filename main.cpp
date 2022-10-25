//#include "registration_.h"
#include "homepage.h"
//#include "dashboard.h"
//#include "sign_in.h"
#include <QApplication>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//  registration_ w;
//    userpage w;
//    sign_in w;
    Homepage w;
    w.show();

//    w.setGeometry(0,0,1307,619);
    return a.exec();
}
