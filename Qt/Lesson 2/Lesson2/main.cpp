#include <QCoreApplication>
#include <QtNetwork/QTcpSocket>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpSocket socket1;
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QSQLITE", "Connection1");
    return a.exec();
}
