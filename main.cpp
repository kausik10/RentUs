


#include "homepage.h"

#include <QApplication>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Homepage w;

    w.show();

    return a.exec();
}
