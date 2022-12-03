


#include "homepage.h"

#include <QApplication>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>

//#include "testttt.h"


//#include "user_details.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Homepage w;

//    User_details w;

    w.show();

//    w.setGeometry(0,0,1307,619);
    return a.exec();
}
