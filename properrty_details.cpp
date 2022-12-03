#include "properrty_details.h"
#include "ui_properrty_details.h"


properrty_details::properrty_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::properrty_details)
{
    ui->setupUi(this);


    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE", "db");
    db.setDatabaseName("C:/Users/ASUS/OneDrive/Desktop/QT/RentUS/Database/mydb.sqlite");
    if(db.open())
    {
        QSqlQueryModel *modal =new QSqlQueryModel();

        QSqlQuery *qry=new QSqlQuery(db);
        qry->prepare("select username, email, location, property_type, owner_name, contact_owner from property_details ORDER BY owner_name");
        qry->exec();
        modal->setQuery(*qry);
        modal->setHeaderData(0, Qt::Horizontal, tr("ADDED BY"));
        modal->setHeaderData(1, Qt::Horizontal, tr("USER EMAIL"));
        modal->setHeaderData(2, Qt::Horizontal, tr("PROPERTY TYPE"));
        modal->setHeaderData(3, Qt::Horizontal, tr("OWNER OF PROPERTY"));
        modal->setHeaderData(4, Qt::Horizontal, tr("CONTACT OF OWNER"));
//        modal->setHeaderData(5, Qt::Horizontal, tr("ADDRESS"));

        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->setModel(modal);
        ui->tableView->resizeColumnsToContents();
        for (int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c)
        {
            ui->tableView->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        }



    }
    db.close();
}

properrty_details::~properrty_details()
{
    delete ui;
}

void properrty_details::on_pushButton_7_clicked()
{
    emit admin_DashBoardClicked();
}


void properrty_details::on_pushButton_2_clicked()
{
   // ui->stackedWidget->setCurrentIndex(1);
}

