#include "user_details.h"
#include "ui_user_details.h"


User_details::User_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User_details)
{
   // ui->stackedWidget->setCurrentIndex(0);
    //ui->stackedWidget->insertWidget(1, &property);
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    if(db.open())
    {
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery *qry=new QSqlQuery();
        qry->prepare("select username, email, contact, gender, age, address from user_detailss ORDER BY username");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0, Qt::Horizontal, tr("NAME"));
        modal->setHeaderData(1, Qt::Horizontal, tr("EMAIL"));
        modal->setHeaderData(2, Qt::Horizontal, tr("CONTACT"));
        modal->setHeaderData(3, Qt::Horizontal, tr("GENDER"));
        modal->setHeaderData(4, Qt::Horizontal, tr("AGE"));
        modal->setHeaderData(5, Qt::Horizontal, tr("ADDRESS"));

        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
        {
            ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        }

    }
}

User_details::~User_details()
{
    delete ui;
}

void User_details::on_pushButton_7_clicked()
{
    emit admin_DashBoardClicked();
}




